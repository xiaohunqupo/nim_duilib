#include "MainThread.h"
#include "BrowserManager.h"
#include "duilib/WebView2/WebView2Manager.h"

WorkerThread::WorkerThread()
    : FrameworkThread(_T("WorkerThread"), ui::kThreadWorker)
{
}

WorkerThread::~WorkerThread()
{
}

void WorkerThread::OnInit()
{
}

void WorkerThread::OnCleanup()
{
}

MainThread::MainThread() :
    FrameworkThread(_T("MainThread"), ui::kThreadUI)
{
}

MainThread::~MainThread()
{
}

void MainThread::OnInit()
{
    //启动工作线程
    m_workerThread.reset(new WorkerThread);
    m_workerThread->Start();

    //初始化全局资源, 使用本地文件夹作为资源
    ui::FilePath resourcePath = ui::FilePathUtil::GetCurrentModuleDirectory();
    resourcePath += _T("resources\\");
    ui::GlobalManager::Instance().Startup(ui::LocalFilesResParam(resourcePath));

    //初始化WebView2的基本配置
    DString userDataFolder = ui::WebView2Manager::GetInstance().GetDefaultUserDataFolder(_T("Webview2Browser"));
    ui::WebView2Manager::GetInstance().Initialize(userDataFolder);

    //创建窗口, 显示默认页面
    BrowserManager::GetInstance()->CreateBorwserBox(nullptr, "", _T(""));
}

void MainThread::OnCleanup()
{
    if (m_workerThread != nullptr) {
        m_workerThread->Stop();
        m_workerThread.reset(nullptr);
    }
    ui::WebView2Manager::GetInstance().UnInitialize();
    ui::GlobalManager::Instance().Shutdown();    
}
