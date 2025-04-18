﻿# CEF控件（CefControl）    
nim_duilib的CEF控件（CefControl）是对libcef的集成封装，将CEF组件相关的功能封装成为duilib的一个控件，使得网页浏览功能能够与界面库整合在一起使用。libcef（Chromium Embedded Framework，简称CEF）‌是一个开源框架，允许开发者在其应用程序中嵌入Chromium（Google Chrome浏览器的开源基础）浏览器功能。通过libcef，开发者可以将网页渲染、JavaScript执行及HTML5支持等功能集成到自己的应用中，而无需用户单独安装浏览器‌。  

## libcef的核心功能与架构
### 功能定义
libcef.dll/libcef.so是CEF的核心动态链接库，提供Chromium的浏览器内核功能，包括：    
* 网页渲染‌：支持HTML5、CSS3等现代网页技术‌
* JavaScript执行‌：实现与网页脚本的交互‌
* 网络通信‌：处理HTTP请求、响应及资源加载‌
* 多进程架构‌：通过独立进程管理渲染、插件等模块，提升稳定性‌
### 系统架构
* libcef.dll/libcef.so 位于应用程序与Chromium引擎之间，通过接口调用实现功能交互。例如，应用程序通过libcef.dll/libcef.so加载网页时，Chromium的网络模块和渲染模块分别负责内容获取与显示‌。
* nim_duilib通过CEF控件（CefControl）封装了libcef.dll/libcef.so模块的基本功能，将网页与UI界面集成为一体。

## CEF控件（CefControl）相关的类
| 类名称 | 关联头文件| 用途 |
| :--- | :--- | :--- |
| 接口类 | [duilib/duilib_cef.h](../duilib/duilib_cef.h) | CEF控件的接口类，应用程序需要包含这个头文件`#include "duilib/duilib_cef.h"` |
| CefManager | [duilib/CEFControl/CefManager.h](../duilib/CEFControl/CefManager.h) | CEF控件管理器，负责CEF模块的初始化和反初始化相关工作 |
| CefControl | [duilib/CEFControl/CefControl.h](../duilib/CEFControl/CefControl.h) | CEF控件接口，提供网页浏览相关的基本功能及事件的接受等功能 |
| CefControlEvent | [duilib/CEFControl/CefControlEvent.h](../duilib/CEFControl/CefControlEvent.h) | CEF控件的网页浏览相关事件接收接口 |
| CefControlNative | [duilib/CEFControl/CefControlNative.h](../duilib/CEFControl/CefControlNative.h) | CEF控件窗口模式的封装 |
| CefControlOffScreen | [duilib/CEFControl/CefControlOffScreen.h](../duilib/CEFControl/CefControlOffScreen.h) | CEF控件离屏渲染模式的封装 |

## CEF控件（CefControl）相关的示例程序
| 示例程序 | 说明 |
| :---     | :--- |
| examples\cef           | CEF控件的简单使用示例，该程序使用了CEF控件窗口模式 |
| examples\multi_browser | CEF控件的多标签浏览器使用示例， 该程序使用了CEF控件离屏渲染模式|

## CEF控件（CefControl）Windows版的使用说明
### libcef 109版本的支持
libcef 109版本支持Win7及以上版本的操作系统（Win7/Win10/Win11等），不支持Windows XP等低版本的操作系统。    
使用的基本步骤如下：    
1. 修改duilib工程（duilib/duilib.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win_109\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）
2. 修改cef工程（examples/cef/cef.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win_109\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）
3. 修改multi_browser工程（examples/multi_browser/multi_browser.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win_109\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）    
4. 将libcef 109版本的二进制文件和资源文件（libcef.dll等）放在以下目录中：x64版本的放在`bin\libcef_win_109\x64`目录，Win32版本的放在`bin\libcef_win_109\Win32`目录
  * 64位版本的下载链接：[02/03/2023 - 109.1.18+gf1c41e4+chromium-109.0.5414.120 / Chromium 109.0.5414.120](https://cef-builds.spotifycdn.com/cef_binary_109.1.18%2Bgf1c41e4%2Bchromium-109.0.5414.120_windows64.tar.bz2)
  * 32位版本的下载链接：[01/27/2023 - 109.1.18+gf1c41e4+chromium-109.0.5414.120 / Chromium 109.0.5414.120](https://cef-builds.spotifycdn.com/cef_binary_109.1.18%2Bgf1c41e4%2Bchromium-109.0.5414.120_windows32.tar.bz2)    
  下载压缩包后，解压。对于64位版本，将Release目录里的文件和Resources目录里面的文件复制到`bin\libcef_win_109\x64`目录即可，    
  对于对于32位版本，将Release目录里的文件和Resources目录里面的文件复制到`bin\libcef_win_109\Win32`目录即可。
5. `examples.sln`工程，重新编译整体源代码，编译成功后，可以运行cef示例程序或者multi_browser示例程序，能够成功运行即可。

### libcef 133版本（或更高版本）的支持
libcef 133版本（或更高版本），是CEF较新的版本，功能更完善。支持Win10及以上版本的操作系统（Win10/Win11等），不支持Win7等低于Win10的操作系统。
使用的基本步骤如下：    
1. 修改duilib工程（duilib/duilib.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）
2. 修改cef工程（examples/cef/cef.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）
3. 修改multi_browser工程（examples/multi_browser/multi_browser.vcxproj）的头文件包含：添加或者修改使头文件目录包含：`..\duilib\third_party\libcef_win\`（入口：VS工程属性 -> C/C++ -> General -> Additional Include Directories）    
4. 将libcef的二进制文件和资源文件（libcef.dll等）放在以下目录中：x64版本的放在`bin\libcef_win\x64`目录，Win32版本的放在`bin\libcef_win\Win32`目录
  * 64位版本的下载链接：[03/08/2025 - 133.4.8+g99a2ab1+chromium-133.0.6943.142 / Chromium 133.0.6943.142](https://cef-builds.spotifycdn.com/cef_binary_133.4.8%2Bg99a2ab1%2Bchromium-133.0.6943.142_windows64.tar.bz2)
  * 32位版本的下载链接：[03/08/2025 - 133.4.8+g99a2ab1+chromium-133.0.6943.142 / Chromium 133.0.6943.142](https://cef-builds.spotifycdn.com/cef_binary_133.4.8%2Bg99a2ab1%2Bchromium-133.0.6943.142_windows32.tar.bz2)    
  下载压缩包后，解压。对于64位版本，将Release目录里的文件和Resources目录里面的文件复制到`bin\libcef_win\x64`目录即可，    
  对于对于32位版本，将Release目录里的文件和Resources目录里面的文件复制到`bin\libcef_win\Win32`目录即可。
5. `examples.sln`工程，重新编译整体源代码，编译成功后，可以运行cef示例程序或者multi_browser示例程序，能够成功运行即可。

### libcef二进制文件和资源文件的组织结构说明
libcef二进制文件和资源文件需要放在bin下的指定目录（比如最新版本CEF，32位版本文件需放在`bin\libcef_win\Win32`目录，64位版本文件需放在`bin\libcef_win\x64`目录），libcef.dll才能被正常加载。libcef二进制文件和资源文件的基本组织结构为（以64位版本为例）：
* chrome_elf.dll
* d3dcompiler_47.dll
* dxcompiler.dll
* dxil.dll
* libcef.dll
* libEGL.dll
* libGLESv2.dll
* vulkan-1.dll
* vk_swiftshader.dll
* v8_context_snapshot.bin
* vk_swiftshader_icd.json
* chrome_100_percent.pak
* chrome_200_percent.pak
* icudtl.dat
* resources.pak
* locales（目录，里面包含zh-CN.pak、en-US.pak等语言包）

## CEF控件（CefControl）Linux版的使用说明
（未完待续）