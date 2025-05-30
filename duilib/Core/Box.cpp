#include "Box.h"
#include "duilib/Core/Window.h"
#include "duilib/Utils/StringUtil.h"

namespace ui
{
Box::Box(Window* pWindow, Layout* pLayout) :
    Control(pWindow),
    m_pLayout(pLayout),
    m_bAutoDestroyChild(true),
    m_bMouseChildEnabled(true),
    m_items(),
    m_nDropInId(0),
    m_nDragOutId(0)
{
    ASSERT(m_pLayout != nullptr);
    if (m_pLayout) {
        m_pLayout->SetOwner(this);
    }
}

Box::~Box()
{
    if (m_bAutoDestroyChild) {
        for (Control* pControl : m_items) {
            if (pControl != nullptr) {
                delete pControl;
            }
        }
    }
    m_items.clear();
    if (m_pLayout != nullptr) {
        delete m_pLayout;
        m_pLayout = nullptr;
    }
}

DString Box::GetType() const { return DUI_CTR_BOX; }

void Box::SetAttribute(const DString& strName, const DString& strValue)
{
    if ((strName == _T("mouse_child")) || (strName == _T("mousechild"))) {
        SetMouseChildEnabled(strValue == _T("true"));
    }
    else if (m_pLayout->SetAttribute(strName, strValue, Dpi())) {
        return;
    }
    else if (strName == _T("drag_out_id")) {
        uint8_t nValue = ui::TruncateToUInt8(StringUtil::StringToInt32(strValue));
        SetDragOutId(nValue);
    }
    else if (strName == _T("drop_in_id")) {
        uint8_t nValue = ui::TruncateToUInt8(StringUtil::StringToInt32(strValue));
        SetDropInId(nValue);
    }
    else {
        Control::SetAttribute(strName, strValue);
    }
}

void Box::ChangeDpiScale(uint32_t nOldDpiScale, uint32_t nNewDpiScale)
{
    ASSERT(nNewDpiScale == Dpi().GetScale());
    if (nNewDpiScale != Dpi().GetScale()) {
        return;
    }
    if (m_pLayout != nullptr) {
        m_pLayout->ChangeDpiScale(Dpi(), nOldDpiScale);
    }
    BaseClass::ChangeDpiScale(nOldDpiScale, nNewDpiScale);
    for (auto pControl : m_items) {
        if (pControl != nullptr) {
            pControl->ChangeDpiScale(nOldDpiScale, nNewDpiScale);
        }
    }
}

void Box::SetParent(Box* pParent)
{
    Control::SetParent(pParent);
    for (auto pControl : m_items) {
        ASSERT(pControl != nullptr);
        if (pControl != nullptr) {
            pControl->SetParent(this);
        }
    }    
}

void Box::SetWindow(Window* pWindow)
{
    Control::SetWindow(pWindow);
    for (auto pControl : m_items) {
        ASSERT(pControl != nullptr);
        if (pControl != nullptr) {
            pControl->SetWindow(pWindow);
        }
    }    
}

void Box::SetPos(UiRect rc)
{
    Control::SetPos(rc);
    if (m_pLayout != nullptr) {
        m_pLayout->ArrangeChild(m_items, rc);    
    }
}

UiRect Box::GetPosWithoutPadding() const
{
    UiRect rc = GetPos();
    rc.Deflate(GetPadding());
    rc.Validate();
    return rc;
}

UiRect Box::GetRectWithoutPadding() const
{
    UiRect rc = GetRect();
    rc.Deflate(GetPadding());
    rc.Validate();
    return rc;
}

void Box::PaintChild(IRender* pRender, const UiRect& rcPaint)
{
    UiRect rcTemp;
    if (!UiRect::Intersect(rcTemp, rcPaint, GetRect())) {
        return;
    }

    std::vector<Control*> delayItems;
    for (auto pControl : m_items) {
        if (pControl == nullptr) {
            continue;
        }
        if (!pControl->IsVisible()) {
            continue;
        }
        if (pControl->GetPaintOrder() != 0) {
            //设置了绘制顺序， 放入延迟绘制列表
            delayItems.push_back(pControl);
            continue;
        }
        pControl->AlphaPaint(pRender, rcPaint);
    }

    if (!delayItems.empty()) {
        std::sort(delayItems.begin(), delayItems.end(), [](const Control* a, const Control* b) {
            return a->GetPaintOrder() < b->GetPaintOrder();
            });
        //绘制延迟绘制的控件
        for (auto pControl : delayItems) {
            if (pControl != nullptr) {
                pControl->AlphaPaint(pRender, rcPaint);
            }            
        }
    }

    if ((pRender != nullptr) && IsShowFocusRect() && IsFocused()) {
        DoPaintFocusRect(pRender);    //绘制焦点状态
    }
}

void Box::PaintFocusRect(IRender* /*pRender*/)
{
}

void Box::SetEnabled(bool bEnabled)
{
    if (BaseClass::IsEnabled() == bEnabled) {
        return;
    }

    BaseClass::SetEnabled(bEnabled);

    //子控件的Enable状态，与父控件是同步的(如果支持不同步，相关业务逻辑需要做调整)
    for (auto pControl : m_items) {
        ASSERT(pControl != nullptr);
        if (pControl != nullptr) {
            pControl->SetEnabled(bEnabled);
        }
    }

    Invalidate();
}

void Box::SetVisible(bool bVisible)
{
    if (BaseClass::IsVisible() == bVisible) {
        return;
    }
    bool v = BaseClass::IsVisible();
    BaseClass::SetVisible(bVisible);
    if (BaseClass::IsVisible() != v) {
        //子控件的Visible控件是同步的(如果支持不同步，相关业务逻辑需要做调整，除了判断控件自身是否可见，还要判断父控件是否可见)
        for (auto pControl : m_items){
            ASSERT(pControl != nullptr);
            if (pControl != nullptr) {
                pControl->SetVisible(bVisible);
            }
        }
    }
}

UiEstSize Box::EstimateSize(UiSize szAvailable)
{
    UiFixedSize fixedSize = GetFixedSize();
    if (!fixedSize.cx.IsAuto() && !fixedSize.cy.IsAuto()) {
        //如果宽高都不是auto属性，则直接返回
        return MakeEstSize(fixedSize);
    }
    szAvailable.Validate();
    if (!IsReEstimateSize(szAvailable)) {
        //使用缓存中的估算结果
        return GetEstimateSize();
    }
    //Box控件本身的大小，不包含外边距（本身也是一个控件，可以有文字/背景图片等）
    UiPadding rcPadding = GetPadding();
    UiSize szNewAvailable = szAvailable;
    szNewAvailable.cx -= (rcPadding.left + rcPadding.right);
    szNewAvailable.cy -= (rcPadding.top + rcPadding.bottom);
    UiEstSize estSizeBySelf = BaseClass::EstimateSize(szNewAvailable);
    UiSize sizeBySelf;
    if (estSizeBySelf.cx.IsInt32()) {
        sizeBySelf.cx = estSizeBySelf.cx.GetInt32() + rcPadding.left + rcPadding.right;
    }
    if (estSizeBySelf.cy.IsInt32()) {
        sizeBySelf.cy = estSizeBySelf.cy.GetInt32() + rcPadding.top + rcPadding.bottom;
    }

    //子控件的大小，包含内边距，但不包含外边距
    UiSize sizeByChild = m_pLayout->EstimateSizeByChild(m_items, szAvailable);
    
    SetReEstimateSize(false);
    for (auto pControl : m_items) {
        ASSERT(pControl != nullptr);
        if ((pControl == nullptr) || !pControl->IsVisible() || pControl->IsFloat()) {
            continue;
        }
        if ((pControl->GetFixedWidth().IsAuto()) || 
            (pControl->GetFixedHeight().IsAuto())) {
            if (pControl->IsReEstimateSize(szAvailable)) {
                SetReEstimateSize(true);
                break;
            }
        }
    }
    if (fixedSize.cx.IsAuto()) {
        fixedSize.cx.SetInt32(std::max(sizeByChild.cx, sizeBySelf.cx));
    }
    if (fixedSize.cy.IsAuto()) {
        fixedSize.cy.SetInt32(std::max(sizeByChild.cy, sizeBySelf.cy));
    }

    UiEstSize estSize = MakeEstSize(fixedSize);
    SetEstimateSize(estSize, szAvailable);
    return estSize;
}

Control* Box::FindControl(FINDCONTROLPROC Proc, void* pProcData,
                          uint32_t uFlags, const UiPoint& ptMouse, const UiPoint& scrollPos)
{
    return FindControlInItems(m_items, Proc, pProcData, uFlags, ptMouse, scrollPos);
}

Control* Box::FindControlInItems(const std::vector<Control*>& items,
                                 FINDCONTROLPROC Proc, void* pProcData,
                                 uint32_t uFlags, 
                                 const UiPoint& ptMouse, 
                                 const UiPoint& scrollPos)
{
    //ptMouse: 是适配过容器自身的坐标
    //scrollPos: 是当前容器的滚动条偏移    
    if ((uFlags & UIFIND_VISIBLE) != 0 && !IsVisible()) {
        return nullptr;
    }
    if ((uFlags & UIFIND_ENABLED) != 0 && !IsEnabled()) {
        return nullptr;
    }
    if ((uFlags & UIFIND_HITTEST) != 0) {
        if (!GetRect().ContainsPt(ptMouse)) {
            return nullptr;
        }
        if (!IsMouseChildEnabled()) {
            Control* pResult = Control::FindControl(Proc, pProcData, uFlags, ptMouse);
            return pResult;
        }
    }

    if ((uFlags & UIFIND_ME_FIRST) != 0) {
        Control* pControl = Control::FindControl(Proc, pProcData, uFlags, ptMouse);
        if (pControl != nullptr) {
            return pControl;
        }
    }
#ifdef _DEBUG
    if (((uFlags & UIFIND_HITTEST) != 0) && ((uFlags & UIFIND_DRAG_DROP) == 0) && (pProcData != nullptr)) {
        UiPoint ptOrg(*(UiPoint*)pProcData);
        ptOrg.Offset(this->GetScrollOffsetInScrollBox());
        ASSERT(ptOrg == ptMouse);
    }
#endif // _DEBUG
    UiPoint boxPt(ptMouse);
    boxPt.Offset(scrollPos);
    UiRect rc = GetRectWithoutPadding();
    if ((uFlags & UIFIND_TOP_FIRST) != 0) {
        //倒序
        for (int32_t it = (int32_t)items.size() - 1; it >= 0; --it) {
            if (items[it] == nullptr) {
                continue;
            }
            Control* pControl = items[it]->FindControl(Proc, pProcData, uFlags, boxPt);
            if (pControl != nullptr) {
                if ((uFlags & UIFIND_HITTEST) != 0 &&
                    !pControl->IsFloat() && !rc.ContainsPt(ptMouse)) {
                    continue;
                }
                else {
                    return pControl;
                }
            }
        }
    }
    else {
        //正常顺序
        for (Control* pItemControl : items) {
            if (pItemControl == nullptr) {
                continue;
            }
            Control* pControl = pItemControl->FindControl(Proc, pProcData, uFlags, boxPt);
            if (pControl != nullptr) {
                if ((uFlags & UIFIND_HITTEST) != 0 && 
                    !pControl->IsFloat() && !rc.ContainsPt(ptMouse)) {
                    continue;
                }
                else {
                    return pControl;
                }
            }
        }
    }

    Control* pResult = nullptr;
    if ((uFlags & UIFIND_ME_FIRST) == 0) {
        pResult = Control::FindControl(Proc, pProcData, uFlags, ptMouse);
    }
    return pResult;
}

Control* Box::FindSubControl(const DString& pstrSubControlName)
{
    Control* pSubControl = GetWindow()->FindSubControlByName(this, pstrSubControlName);
    return pSubControl;
}

size_t Box::FindSelectable(size_t iIndex, bool bForward /*= true*/) const
{
    // NOTE: This is actually a helper-function for the list/combo/ect controls
    //       that allow them to find the next enabled/available selectable item
    const size_t itemCount = GetItemCount();
    if (itemCount == 0) {
        return Box::InvalidIndex;
    }
    if (!Box::IsValidItemIndex(iIndex)) {
        iIndex = 0;
    }
    if (iIndex >= (itemCount - 1)) {
        iIndex = itemCount - 1;
    }
    if (bForward) {
        for (size_t i = iIndex; i < itemCount; ++i) {
            Control* pControl = GetItemAt(i);
            if (pControl == nullptr) {
                continue;
            }
            if (pControl->IsSelectableType() &&
                pControl->IsVisible()        &&
                pControl->IsEnabled()) {
                return i;
            }
        }
        return Box::InvalidIndex;
    }
    else {
        for (int i = (int)iIndex; i >= 0; --i) {
            Control* pControl = GetItemAt(static_cast<size_t>(i));
            if (pControl == nullptr) {
                continue;
            }
            if (pControl->IsSelectableType() &&
                pControl->IsVisible()        &&
                pControl->IsEnabled()) {
                return static_cast<size_t>(i);
            }
        }
        return FindSelectable(0, true);
    }
}

Control* Box::GetItemAt(size_t iIndex) const
{
    if (iIndex >= m_items.size()) {
        return nullptr;
    }
    return m_items[iIndex];
}

size_t Box::GetItemIndex(Control* pControl) const
{
    if (pControl == nullptr) {
        return Box::InvalidIndex;
    }
    auto it = std::find(m_items.begin(), m_items.end(), pControl);
    if (it == m_items.end()) {
        return Box::InvalidIndex;
    }
    return static_cast<int>(it - m_items.begin());
}

bool Box::SetItemIndex(Control* pControl, size_t iIndex)
{
    if (pControl == nullptr) {
        return false;
    }
    if (iIndex >= m_items.size()) {
        return false;
    }
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if( *it == pControl ) {
            Arrange();            
            m_items.erase(it);
            m_items.insert(m_items.begin() + iIndex, pControl);
            return true;
        }
    }
    return false;
}

size_t Box::GetItemCount() const
{
    return m_items.size();
}

bool Box::AddItem(Control* pControl)
{
    return DoAddItemAt(pControl, m_items.size());
}

bool Box::AddItemAt(Control* pControl, size_t iIndex)
{
    return DoAddItemAt(pControl, iIndex);
}

bool Box::DoAddItemAt(Control* pControl, size_t iIndex)
{
    ASSERT(pControl != nullptr);
    if (pControl == nullptr) {
        return false;
    }
    if(iIndex > m_items.size() ) {
        ASSERT(0);
        return false;
    }
    m_items.insert(m_items.begin() + iIndex, pControl);
    Window* pWindow = GetWindow();
    if (pWindow != nullptr) {
        pWindow->InitControls(pControl);
    }
    pControl->SetParent(this);

    //同步Enable属性和Visible属性(只同步基类的值)
    if (!BaseClass::IsEnabled()) {
        pControl->SetEnabled(BaseClass::IsEnabled());
    }
    if (!Control::IsVisible()) {
        pControl->SetVisible(BaseClass::IsVisible());
    }

    //在添加到父容器以后，调用初始化函数
    pControl->Init();
    if (IsVisible()) {
        Arrange();
    }    
    return true;
}

bool Box::RemoveItem(Control* pControl)
{
    return DoRemoveItem(pControl);
}

bool Box::RemoveItemAt(size_t iIndex)
{
    Control* pControl = GetItemAt(iIndex);
    if (pControl != nullptr) {
        return DoRemoveItem(pControl);
    }
    return false;
}

bool Box::DoRemoveItem(Control* pControl)
{
    ASSERT(pControl != nullptr);
    if (pControl == nullptr) {
        return false;
    }
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if (*it == pControl) {
            m_items.erase(it);
            if (m_bAutoDestroyChild) {
                if (pControl) {
                    if (pControl->HasDestroyEventCallback()) {
                        pControl->SendEvent(kEventDestroy);
                    }
                    delete pControl;
                }                
            }
            Arrange();
            return true;
        }
    }
    return false;
}

void Box::RemoveAllItems()
{
    std::vector<Control*> items;
    items.swap(m_items);
    if (m_bAutoDestroyChild) {
        for(Control* pControl : items) {
            delete pControl;
        }
    }
    if (!items.empty()) {
        Arrange();
    }    
}

Layout* Box::ResetLayout(Layout* pNewLayout)
{
    ASSERT(pNewLayout != nullptr);
    if (pNewLayout != nullptr) {        
        pNewLayout->SetOwner(this);
    }
    Layout* pOldLayout = m_pLayout;
    m_pLayout = pNewLayout;
    return pOldLayout;
}

void Box::FreeLayout(Layout* pLayout)
{
    if (pLayout != nullptr) {
        ASSERT(m_pLayout != pLayout);
        if (m_pLayout != pLayout) {
            delete pLayout;
        }        
    }
}

void Box::ClearImageCache()
{
    BaseClass::ClearImageCache();
    for (Control* pControl : m_items) {
        if (pControl != nullptr) {
            pControl->ClearImageCache();
        }
    }
}

uint32_t Box::GetControlFlags() const
{
    return UIFLAG_DEFAULT; // Box 默认不支持 TAB 切换焦点
}

void Box::SetDropInId(uint8_t nDropInId)
{
    m_nDropInId = nDropInId;
}

uint8_t Box::GetDropInId() const
{
    return m_nDropInId;
}

void Box::SetDragOutId(uint8_t nDragOutId)
{
    m_nDragOutId = nDragOutId;
}

uint8_t Box::GetDragOutId() const
{
    return m_nDragOutId;
}

} // namespace ui
