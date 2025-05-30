#ifndef EXAMPLES_REPLACE_FORM_H_
#define EXAMPLES_REPLACE_FORM_H_

// duilib
#include "duilib/duilib.h"

class MainForm;
class ReplaceForm : public ui::WindowImplBase
{
public:
    explicit ReplaceForm(MainForm* pMainForm);
    virtual ~ReplaceForm() override;

    /** 资源相关接口
     * GetSkinFolder 接口设置你要绘制的窗口皮肤资源路径
     * GetSkinFile 接口设置你要绘制的窗口的 xml 描述文件
     */
    virtual DString GetSkinFolder() override;
    virtual DString GetSkinFile() override;

    /** 当窗口创建完成以后调用此函数，供子类中做一些初始化的工作
    */
    virtual void OnInitWindow() override;

private:
    //查找下一个
    void OnFindNext();
    //替换
    void OnReplace();
    //全部替换
    void OnReplaceAll();

private:
    //查找/替换接口
    MainForm* m_pMainForm;

    //搜索方向选项
    ui::Option* m_pDirectionOption;

    //是否区分大小写
    ui::CheckBox* m_pCaseSensitive;

    //是否全字匹配
    ui::CheckBox* m_pMatchWholeWord;

    //查找内容
    ui::RichEdit* m_pFindText;

    //替换内容
    ui::RichEdit* m_pReplaceText;
};

#endif //EXAMPLES_REPLACE_FORM_H_
