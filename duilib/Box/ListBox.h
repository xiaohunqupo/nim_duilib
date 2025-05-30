#ifndef UI_BOX_LISTBOX_H_
#define UI_BOX_LISTBOX_H_

#include "duilib/Box/ListBoxItem.h"
#include "duilib/Box/ScrollBox.h"
#include "duilib/Control/Option.h"

namespace ui 
{

/** 用户自定义的排序函数
@param [in] pControl1 第一个控件接口
@param [in] pControl2 第二个控件接口
@param [in] pCompareContext 用户自定义上下文数据
@return < 0 控件1小于控件2
        = 0 控件1等于控件2
        > 0 控件1大于控件2
*/
typedef int (CALLBACK *PFNCompareFunc)(Control* pControl1, Control* pControl2, void* pCompareContext);

/** 鼠标键盘操作的辅助类
*/
class ListBoxHelper;

/** 列表容器，用于展示一组数据使用
*   通过修改布局，形成 HListBox和VListBox和TileListBox三个子类
*/
class UILIB_API ListBox : public ScrollBox, public IListBoxOwner
{
    typedef ScrollBox BaseClass;
public:
    ListBox(Window* pWindow, Layout* pLayout);
    virtual ~ListBox() override;

    ListBox(const ListBox& r) = delete;
    ListBox& operator=(const ListBox& r) = delete;

    /// 重写父类方法，提供个性化功能，请参考父类声明
    virtual DString GetType() const override;
    virtual void SetAttribute(const DString& strName, const DString& strValue) override;
    virtual void HandleEvent(const EventArgs& msg) override;
    virtual void SendEventMsg(const EventArgs& msg) override;

    //IListBoxOwner 接口的实现
    virtual void StopScroll() override;
    virtual bool CanPaintSelectedColors(bool bHasStateImages) const override;
    virtual void EnsureSingleSelection() override;

public:
    /** 是否支持多选
    */
    virtual bool IsMultiSelect() const override;

    /** 设置是否支持多选，由界面层调用，保持与界面控件一致
    * @return bMultiSelect true表示支持多选，false表示不支持多选
    */
    virtual void SetMultiSelect(bool bMultiSelect);

    /** 获取当前选择的索引(仅单选时有效)
    @return 返回选择的索引，如果无有效索引，则返回Box::InvalidIndex
    */
    virtual size_t GetCurSel() const override;

    /** 设置当前选择的索引(仅单选时有效)
    * @param [in] iIndex 子项目的ID
    */
    virtual void SetCurSel(size_t iIndex) override;

    /** 获取是否随鼠标滚轮的滚动改变选中项设置(此选项仅单选有效)
    * @return 返回 true 表示跟随滚动条改变选择项，否则为 false
    */
    bool IsScrollSelect() const;

    /** 设置是否随鼠标滚轮的滚动改变选中项设置(此选项仅单选有效)
     * @param[in] bScrollSelect 为 true 是为跟随滚动条改变选中项，false 为不跟随
     */
    void SetScrollSelect(bool bScrollSelect);

    /** 在移除一个子项后, 如果被移除项是选择项，是否自动选择下一项(此选项仅单选有效)
     */
    bool IsSelectNextWhenActiveRemoved() const;

    /** 在移除一个子项后, 如果被移除项是选择项，则自动选择下一项(此选项仅单选有效)
     * @param [in] bSelectNextItem 为 true 时自动选择下一项，false 为不自动选择
     */
    void SetSelectNextWhenActiveRemoved(bool bSelectNextItem);

public:
    /** 查找下一个可选控件的索引
     * @param[in] iIndex 指定要起始查找的索引
     * @param[in] bForward true 为递增查找， false 为递减查找
     * @return 下一个可选控件的索引，返回 Box::InvalidIndex 为没有可选控件
     */
    virtual size_t FindSelectable(size_t iIndex, bool bForward = true) const;

    /** 获取当前选择的子项(支持单选和多选)，选择时排除!IsVisible() 和 !IsEnabled() 子项
    * @param [out] selectedIndexs 返回选择的子项ID，范围是：[0, GetItemCount())
    */
    virtual void GetSelectedItems(std::vector<size_t>& selectedIndexs) const;

    /** 选择子项
    * @param [in] iIndex 子项目的ID
    * @param [in] bTakeFocus 是否让子项控件成为焦点控件
    * @param [in] bTriggerEvent 是否触发选择事件, 如果为true，会触发一个kEventSelect事件
    * @param [in] vkFlag 按键标志, 取值范围参见 enum VKFlag 的定义
    * @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    virtual bool SelectItem(size_t iIndex, bool bTakeFocus, 
                            bool bTriggerEvent, uint64_t vkFlag = 0) override;

    /** 取消选择子项
    * @param [in] iIndex 子项目的ID
    * @param [in] bTriggerEvent 是否触发选择事件, 如果为true，会触发一个kEventUnSelect事件
    * @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    virtual bool UnSelectItem(size_t iIndex, bool bTriggerEvent) override;

    /** 选中上一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemPrevious(bool bTakeFocus, bool bTriggerEvent);

    /** 选中下一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemNext(bool bTakeFocus, bool bTriggerEvent);

    /** 向上滚动一页，选中一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemPageUp(bool bTakeFocus, bool bTriggerEvent);

    /** 向下滚动一页，选中一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemPageDown(bool bTakeFocus, bool bTriggerEvent);

    /** 滚动到第一页，选中第一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemHome(bool bTakeFocus, bool bTriggerEvent);

    /** 滚动到最后一页，选中最后一项，并确保选中项可见
    * @return 返回选中的子项索引，有效范围是：[0, GetItemCount())
    */
    virtual size_t SelectItemEnd(bool bTakeFocus, bool bTriggerEvent);

public:    
    /** 确保矩形区域可见
    * @param [in] rcItem 可见区域的矩形范围
    * @param [in] vVisibleType 垂直方向可见的附加标志
    * @param [in] hVisibleType 水平方向可见的附加标志
    */
    virtual void EnsureVisible(const UiRect& rcItem,
                               ListBoxVerVisible vVisibleType,
                               ListBoxHorVisible hVisibleType) override;

    /** 确保子项可见
    * @param [in] iIndex 子项索引，范围是：[0, GetItemCount())
    * @param [in] vVisibleType 垂直方向可见的附加标志
    * @param [in] hVisibleType 水平方向可见的附加标志
    * @return 如果是虚表实现，返回该元素对应的新的控件索引号，范围是：[0, GetItemCount())
    */
    virtual size_t EnsureVisible(size_t iIndex,
                                 ListBoxVerVisible vVisibleType = ListBoxVerVisible::kVisible,
                                 ListBoxHorVisible hVisibleType = ListBoxHorVisible::kVisible);

    /** 滚动到指定子项位置
     * @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
     */
    virtual bool ScrollItemToTop(size_t iIndex);

    /** 滚动到指定子项位置
     * @param [in] itemName 子项名称(即：Control::GetName())
     */
    virtual bool ScrollItemToTop(const DString& itemName);

    /** 获取当前矩形区域(Control::GetPos())中的第一个子项
     */
    virtual Control* GetTopItem() const;

public:
    /** 设置子项的位置索引
     * @param [in] pControl 子项指针
     * @param [in] iIndex 索引号，范围是：[0, GetItemCount())
     */
    virtual bool SetItemIndex(Control* pControl, size_t iIndex) override;

    /** 追加一个子项到末尾
     * @param [in] pControl 子项指针
     */
    virtual bool AddItem(Control* pControl) override;

    /** 在指定位置之后插入一个子项
     * @param [in] pControl 子项指针
     * @param[in] iIndex 要插入的位置索引，范围是：[0, GetItemCount())
     */
    virtual bool AddItemAt(Control* pControl, size_t  iIndex) override;

    /** 根据子项指针
     * @param [in] pControl 子项指针
     */
    virtual bool RemoveItem(Control* pControl) override;

    /** 根据索引移除一个子项
     * @param [in] iIndex 子项索引，范围是：[0, GetItemCount())
     */
    virtual bool RemoveItemAt(size_t iIndex) override;

    /** 移除所有子项
     */
    virtual void RemoveAllItems() override;

public:
    /** 设置是否支持鼠标框选功能
    */
    void SetEnableFrameSelection(bool bEnable);

    /** 获取是否支持鼠标框选功能
    */
    bool IsEnableFrameSelection() const;

    /** 设置鼠标框选填充颜色
    */
    void SetFrameSelectionColor(const DString& frameSelectionColor);

    /** 获取鼠标框选填充颜色
    */
    DString GetFrameSelectionColor() const;

    /** 设置鼠标框选填充颜色的Alpha值
    */
    void SetframeSelectionAlpha(uint8_t frameSelectionAlpha);

    /** 获取鼠标框选填充颜色的Alpha值
    */
    uint8_t GetFrameSelectionAlpha() const;

    /** 设置鼠标框选边框颜色
    */
    void SetFrameSelectionBorderColor(const DString& frameSelectionBorderColor);

    /** 获取鼠标框选边框颜色
    */
    DString GetFrameSelectionBorderColor() const;

    /** 设置鼠标框选边框的大小
    * @param [in] nBorderSize 边框大小（未经DPI缩放）
    */
    void SetFrameSelectionBorderSize(int32_t nBorderSize);

    /** 获取鼠标框选边框的大小（未经DPI缩放）
    */
    int32_t GetFrameSelectionBorderSize() const;

    /** 设置普通列表项（非Header、非置顶）的top坐标(目前ListCtrl在用此功能)
    */
    void SetNormalItemTop(int32_t nNormalItemTop);

    /** 获取普通列表项（非Header、非置顶）的top坐标(目前ListCtrl在用此功能)
    */
    int32_t GetNormalItemTop() const;

    /** 设置当鼠标点击空白部分时，是否取消选择(仅当开启鼠标框选功能时有效)
    */
    void SetSelectNoneWhenClickBlank(bool bSelectNoneWhenClickBlank);

    /** 获取当鼠标点击空白部分时，是否取消选择
    */
    bool IsSelectNoneWhenClickBlank() const;

    /** 设置选择模式：是否按ListCtrl风格（仅多选模式有效，即Windows资源管理器中，对文件操作类似的方式）
        按Ctrl: 只选择点击的子项, 再次点击则取消选择
        按Shift：选择两次点击之间的所有子项
    */
    void SetSelectLikeListCtrl(bool bSelectLikeListCtrl);

    /** 获取设置选择模式：是否按ListCtrl风格
    */
    bool IsSelectLikeListCtrl() const;

public:
    /** 选择全部, 同时按需更新界面显示
    * @return 如果有数据变化返回true，否则返回false
    */
    virtual bool SetSelectAll();

    /** 取消所有选择, 同时按需更新界面显示
    * @return 如果有数据变化返回true，否则返回false
    */
    virtual bool SetSelectNone();

    /** 选择状态发生变化(全选，全不选触发)
    */
    virtual void OnSelectStatusChanged();

public:
    /** 对子项排序
     * @param [in] pfnCompare 自定义排序函数
     * @param [in] pCompareContext 传递给比较函数的用户自定义数据
     */
    virtual bool SortItems(PFNCompareFunc pfnCompare, void* pCompareContext);

    /** 监听选择子项的事件
    * @param[in] callback 选择子项时的回调函数
    *            参数说明:
    *                   wParam: 当前新选择的子项ID
    *                    lParam: 原来旧选择的子项ID，可能为无效值Box::InvalidIndex
    */
    void AttachSelect(const EventCallback& callback) { AttachEvent(kEventSelect, callback); }

    /** 监听取消选择子项的事件
    * @param[in] callback 取消选择子项时的回调函数
    *            参数说明:
    *                   wParam: 取消选择的子项ID
    *                    lParam: 无效值Box::InvalidIndex
    */
    void AttachUnSelect(const EventCallback& callback) { AttachEvent(kEventUnSelect, callback); }

protected:
    /** 当从多选切换为单选模式的时候，需要确保列表中只有一个选择项
    * @return 如果有变化返回true，否则返回false
    */
    virtual bool OnSwitchToSingleSelect();

    /** 同步当前选择项的选择状态
    * @return 如果有变化返回true，否则返回false
    */
    bool UpdateCurSelItemSelectStatus();

    /** 查找的模式
    */
    enum class SelectableMode
    {
        kForward,    //从当前元素nCurSel向前查找第nCount个数据
        kBackward,    //从当前元素nCurSel向后查找第nCount个数据
        kSelect,    //定位到当前所选择的数据（虚表模式下，选择的数据可能不在显示区域）
        kHome,        //定位到第一条数据
        kEnd        //定位到最后一条数据
    };
    /** 即将查找指定的元素（为虚表提供加载数据的机会）
    * @param [in] nCurSel 当前选择的显示控件索引号
    * @param [in] mode  查找的模式
    * @param [in] nCount 查找的控件的第几个数据
    * @param [out] nDestItemIndex 返回加载后的目标控件索引号，有效范围: [0, GetItemCount())
    * @return 返回true表示有数据加载行为，false表示无任何动作
    */
    virtual bool OnFindSelectable(size_t nCurSel, SelectableMode mode, 
                                  size_t nCount, size_t& nDestItemIndex);

    /** 查询本条数据前面还有几条数据（支持虚表数据）
    * @param [in] nCurSel 当前选择的显示控件索引号
    */
    virtual size_t GetItemCountBefore(size_t nCurSel);

    /** 查询本条数据后面还有几条数据（支持虚表数据）
    * @param [in] nCurSel 当前选择的显示控件索引号
    */
    virtual size_t GetItemCountAfter(size_t nCurSel);

    /** 子项的选择状态变化事件，用于状态同步
    * @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
    * @param [in] pListBoxItem 关联的列表项接口
    */
    virtual void OnItemSelectedChanged(size_t iIndex, IListBoxItem* pListBoxItem) override;

    /** 子项的勾选状态变化事件，用于状态同步
    * @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
    * @param [in] pListBoxItem 关联的列表项接口
    */
    virtual void OnItemCheckedChanged(size_t iIndex, IListBoxItem* pListBoxItem) override;

    /** 响应KeyDown消息（实现ListBox标准模式的快捷键处理）
    * @return 返回true表示成功处理，返回false表示未处理此消息
    */
    virtual bool OnListBoxKeyDown(const EventArgs& msg);

    /** 响应KeyDown消息（实现ListCtrl类似的快捷键逻辑: Shift + 方向键）
    * @return 返回true表示成功处理，返回false表示未处理此消息
    */
    virtual bool OnListCtrlKeyDown(const EventArgs& msg);

    /** 响应MouseWheel消息
    @return 返回true表示成功处理，返回false表示未处理此消息
    */
    bool OnListBoxMouseWheel(const EventArgs& msg);

protected:
    /**
     * @brief 默认的子项对比方法
     * @param[in] pvlocale 保存 List 指针
     * @param[in] item1 子项1
     * @param[in] item2 子项2
     * @return 返回对比结果
     */
    static int ItemComareFuncWindows(void* pvlocale, const void* item1, const void* item2);
    static int ItemComareFuncLinux(const void* item1, const void* item2, void* pvlocale);
    static int ItemComareFuncMacOS(void* context, const void* item1, const void* item2);

    int ItemComareFunc(const void* item1, const void* item2);

    /** 选择子项(单选)
    *  @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
    *  @param [in] bTakeFocus 是否让子项控件成为焦点控件
    *  @param [in] bTriggerEvent 是否触发选择事件, 如果为true，会触发一个kEventSelect事件
    *  @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    bool SelectItemSingle(size_t iIndex, bool bTakeFocus, bool bTriggerEvent);

    /** 选择子项(多选)
    *  @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
    *  @param [in] bTakeFocus 是否让子项控件成为焦点控件
    *  @param [in] bTriggerEvent 是否触发选择事件, 如果为true，会触发一个kEventSelect事件
    *  @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    bool SelectItemMulti(size_t iIndex, bool bTakeFocus, bool bTriggerEvent);

    /** 选择子项，选中后让子项控件成为焦点控件，并触发一个kEventSelect事件
    *   为二次封装函数，相当于：SelectItem(iIndex, true, true);
    *  @param [in] iIndex 子项目的ID，范围是：[0, GetItemCount())
    *  @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    bool SelectItem(size_t iIndex);

    /** 按分页的方式选择子项
    */
    size_t SelectItemPage(bool bTakeFocus, bool bTriggerEvent, bool bForward, int32_t nDeltaValue);

    /** 按跳跃nCount个子项的方式选择子项
    */
    size_t SelectItemCountN(bool bTakeFocus, bool bTriggerEvent, bool bForward, size_t nCount);

    /** 获取当前布局方向
    * @return 返回true表示为横向布局，否则为纵向布局
    */
    bool IsHorizontalLayout() const;

    /** 判断当前布局是否为横向滚动条
    */
    bool IsHorizontalScrollBar() const;

    /** 确保选择项可见
    * @param [in] itemIndex 子项目的ID，范围是：[0, GetItemCount())
    * @param [in] bTakeFocus 是否让子项控件成为焦点控件
    * return 返回新的控件索引号(虚表的情况下空间索引号可能会发生变化)，范围是：[0, GetItemCount())
    */
    size_t SelectEnsureVisible(size_t itemIndex, bool bTakeFocus);

    /** 判断一个子项是否为可选择项
    * @param [in] itemIndex 子项目的ID，范围是：[0, GetItemCount())
    */
    bool IsSelectableItem(size_t itemIndex) const;

    /** 判断一个列表项是否处于选择状态（界面控件）
    * @param [in] nIndex 界面控件的子项索引号
    * @return 返回true表示处于选择状态，返回false表示非选择状态
    */
    bool IsItemSelected(size_t nIndex) const;

    /** 计算本页里面显示几个子项
    * @param [in] bIsHorizontal 当前布局是否为水平布局
    * @param [out] nColumns 返回列数
    * @param [out] nRows 返回行数
    * @return 返回可视区域显示的记录数
    */
    virtual size_t GetDisplayItemCount(bool bIsHorizontal, size_t& nColumns, size_t& nRows) const;

    /** 横向瓦片布局，计算可显示行数
    * @return 返回值：>= 1
    */
    int32_t CalcHTileRows(HTileLayout* pHTileLayout) const;

    /** 横向瓦片布局，计算可显示列数
    * @return 返回值：>= 1
    */
    int32_t CalcHTileColumns(HTileLayout* pHTileLayout) const;

    /** 纵向瓦片布局，计算列数
    * @return 返回值：>= 1
    */
    int32_t CalcVTileColumns(VTileLayout* pVTileLayout) const;

    /** 纵向瓦片布局，计算可现实行数
    * @return 返回值：>= 1
    */
    int32_t CalcVTileRows(VTileLayout* pVTileLayout) const;

    /** 设置没按Shift键时的最后一次选中项的索引号，界面控件的索引号（用于按Shift键选择的逻辑）
    */
    virtual void SetLastNoShiftItem(size_t nLastNoShiftItem);

    /** 设置没按Shift键时的最后一次选中项的索引号（用于按Shift键选择的逻辑）
    */
    size_t GetLastNoShiftItem() const;

protected:
    //鼠标消息（返回true：表示消息已处理；返回false：则表示消息未处理，需转发给父控件）
    virtual bool ButtonDown(const EventArgs& msg) override;
    virtual bool ButtonUp(const EventArgs& msg) override;
    virtual bool RButtonDown(const EventArgs& msg) override;
    virtual bool RButtonUp(const EventArgs& msg) override;
    virtual bool MouseMove(const EventArgs& msg) override;
    virtual bool OnWindowKillFocus(const EventArgs& msg) override;//控件所属的窗口失去焦点

    /** 绘制子控件
    */
    virtual void PaintChild(IRender* pRender, const UiRect& rcPaint) override;

    /** 绘制鼠标框选的边框和填充颜色
    */
    virtual void PaintFrameSelection(IRender* pRender);

    /** 列表项的子项收到鼠标事件
    * @return true表示截获该消息，子项不再处理该消息；返回false表示子项继续处理该消息
    */
    virtual bool OnListBoxItemMouseEvent(const EventArgs& msg) override;

    /** 列表项的子项收到窗口失去焦点事件
    */
    virtual void OnListBoxItemWindowKillFocus() override;

    /** 获取滚动视图的滚动幅度(鼠标框选功能)
    */
    virtual void GetScrollDeltaValue(int32_t& nHScrollValue, int32_t& nVScrollValue) const;

    /** 执行了鼠标框选操作(鼠标框选功能，该坐标值是相对于ListBox的左上角坐标值)
    * @param [in] left 框选的X坐标left值
    * @param [in] right 框选的X坐标right值
    * @param [in] top 框选的Y坐标top值
    * @param [in] bottom 框选的Y坐标bottom值
    * @return 如果有选择变化返回true，否则返回false
    */
    virtual bool OnFrameSelection(int64_t left, int64_t right, int64_t top, int64_t bottom);

    /** 选择子项(ListCtrl风格)
    *  @param [in] iIndex 子项目的ID
    *  @param [in] bTakeFocus 是否让子项控件成为焦点控件
    *  @param [in] bTriggerEvent 是否触发选择事件, 如果为true，会触发一个kEventSelect事件
    *  @param [in] vkFlag 按键标志, 取值范围参见 enum VKFlag 的定义
    *  @return 返回true代表内部选择状态发生变化，返回false代表内部状态无变化
    */
    virtual bool ListCtrlSelectItem(size_t iIndex, bool bTakeFocus,
                                    bool bTriggerEvent, uint64_t vkFlag);

    /** 在视图空白处点击了鼠标左键(鼠标框选功能)
    * @return 如果选择项有变化返回true，此时会触发kEventSelChange事件，否则返回false
    */
    virtual bool OnLButtonClickedBlank();

    /** 在视图空白处点击了鼠标右键(鼠标框选功能)
    * @return 如果选择项有变化返回true，此时会触发kEventSelChange事件，否则返回false
    */
    virtual bool OnRButtonClickedBlank();

private:
    /** 横向布局，计算行数
    */
    int32_t CalcRows() const;

    /** 纵向布局，计算列数
    */
    int32_t CalcColumns() const;

private:
    //Helper类型，可以访问所有数据
    friend class ListBoxHelper;

    //当前选择的子项ID, 如果是多选，指向最后一个选择项
    size_t m_iCurSel;

    //没按Shift键时的最后一次选中项的界面控件索引号（用于按Shift键选择的逻辑）
    size_t m_nLastNoShiftItem;

    //用户自定义的排序比较函数
    PFNCompareFunc m_pCompareFunc;

    //用户自定义的排序比较函数中的上下文数据
    void* m_pCompareContext;

    //鼠标键盘操作辅助类
    std::unique_ptr<ListBoxHelper> m_pHelper;

    //多选的时候，是否显示选择背景色: 0 - 默认规则; 1 - 显示背景色; 2: 不显示背景色
    uint8_t m_uPaintSelectedColors;

    //是否随滚动改变选中项
    bool m_bScrollSelect;

    //在移除一个子项后自动选择下一项
    bool m_bSelectNextWhenActiveRemoved;

    //是否允许多选（默认为单选）
    bool m_bMultiSelect;

    //选择模式：ListCtrl风格（仅多选模式有效）
    //按Ctrl: 只选择点击的子项, 再次点击则取消选择
    //按Shift：选择两次点击之间的所有子项
    bool m_bSelectLikeListCtrl;

    //当鼠标点击空白部分时，是否取消选择(仅当开启鼠标框选功能时有效)
    bool m_bSelectNoneWhenClickBlank;
};

/////////////////////////////////////////////////////////////////////////////////////
//

/** 横向布局的ListBox
*/
class UILIB_API HListBox : public ListBox
{
public:
    explicit HListBox(Window* pWindow) :
        ListBox(pWindow, new HLayout)
    {
    }

    virtual DString GetType() const override { return DUI_CTR_HLISTBOX; }
};

/** 纵向布局的ListBox
*/
class UILIB_API VListBox : public ListBox
{
public:
    explicit VListBox(Window* pWindow) :
        ListBox(pWindow, new VLayout)
    {
    }

    virtual DString GetType() const override { return DUI_CTR_VLISTBOX; }
};

/** 瓦片布局的ListBox(横向布局)
*/
class UILIB_API HTileListBox : public ListBox
{
public:
    explicit HTileListBox(Window* pWindow) :
        ListBox(pWindow, new HTileLayout)
    {
    }

    virtual DString GetType() const override { return DUI_CTR_HTILE_LISTBOX; }
};

/** 瓦片布局的ListBox(纵向布局)
*/
class UILIB_API VTileListBox : public ListBox
{
public:
    explicit VTileListBox(Window* pWindow) :
        ListBox(pWindow, new VTileLayout)
    {
    }

    virtual DString GetType() const override { return DUI_CTR_VTILE_LISTBOX; }
};

} // namespace ui

#endif // UI_BOX_LISTBOX_H_
