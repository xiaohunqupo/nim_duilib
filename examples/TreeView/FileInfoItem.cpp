#include "FileInfoItem.h"
#include "FileInfoList.h"

FileInfoItem::FileInfoItem(ui::Window* pWindow):
    ui::ListBoxItem(pWindow),
    m_nElementIndex(ui::Box::InvalidIndex),
    m_pIconControl(nullptr),
    m_pTextControl(nullptr)
{
}

FileInfoItem::~FileInfoItem()
{
}

void FileInfoItem::InitSubControls(const FileInfo& fileInfo, size_t nElementIndex)
{
    m_nElementIndex = nElementIndex;
    if (m_pIconControl == nullptr) {
        m_pIconControl = FindSubControl(_T("control_img"));
    }
    if (m_pTextControl == nullptr) {
        m_pTextControl = dynamic_cast<ui::Label*>(FindSubControl(_T("control_text")));
    }
    if (m_pTextControl != nullptr) {
        m_pTextControl->SetAutoToolTip(true);
        m_pTextControl->SetText(fileInfo.m_fileName.ToString());        
    }
    if (m_pIconControl != nullptr) {
        if (!fileInfo.m_isFolder && IsImageFile(fileInfo.m_fileName.ToString())) {
            //图片文件，直接显示图片（屏蔽了，运行速度太慢，待优化）
            int32_t itemWidth = 64;// this->GetWidth();
            DString imageString = fileInfo.m_filePath.ToString();
            if (itemWidth > 0) {
                imageString = ui::StringUtil::Printf(_T("file='%s' halign='center' valign='center' width='%d'"), imageString.c_str(), itemWidth);
            }
            else {
                imageString = ui::StringUtil::Printf(_T("file='%s' halign='center' valign='center'"), imageString.c_str());
            }
            m_pIconControl->SetBkImage(imageString);
        }
        else {
            //非图片文件或者文件夹，显示图标
            DString iconString = ui::GlobalManager::Instance().Icon().GetIconString(fileInfo.m_hIcon);
            if (!iconString.empty()) {
                iconString = ui::StringUtil::Printf(_T("file='%s' halign='center' valign='center'"), iconString.c_str());
                m_pIconControl->SetBkImage(iconString);
            }
        }             
    }
}

bool FileInfoItem::IsImageFile(const DString& filePath) const
{
    DString fileExt;
    size_t pos = filePath.rfind(_T('.'));
    if (pos != DString::npos) {
        fileExt = filePath.substr(pos);
    }
    fileExt = ui::StringUtil::MakeLowerString(fileExt);
    if (fileExt == _T(".svg")) {
        return true;
    }
    /*if ((fileExt == _T(".svg")) || 
        (fileExt == _T(".jpg")) || 
        (fileExt == _T(".jpeg")) || 
        (fileExt == _T(".gif")) || 
        (fileExt == _T(".png")) || 
        (fileExt == _T(".bmp")) || 
        (fileExt == _T(".webp")) || 
        (fileExt == _T(".ico"))) {
        return true;
    }*/
    return false;
}
