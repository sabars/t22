// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#ifndef WINCE
// 如果必须将位于下面指定平台之前的平台作为目标，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER              // 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501       // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT        // 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501 // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINDOWS      // 允许使用特定于 Windows 98 或更高版本的功能。
#define _WIN32_WINDOWS 0x0410 // 将此值更改为适当的值，以指定将 Windows Me 或更高版本作为目标。
#endif

#ifndef _WIN32_IE           // 允许使用特定于 IE 6.0 或更高版本的功能。
#define _WIN32_IE 0x0600    // 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif

#define WIN32_LEAN_AND_MEAN     // 从 Windows 头中排除极少使用的资料
// Windows 头文件:
#include <windows.h>

// TODO: 在此处引用程序需要的其他头文件

#else // WinCE

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

// 注意 - 这个值与作为目标的 Windows CE OS 版本的关联性并不强
#define WINVER _WIN32_WCE

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN        // 从 Windows 头中排除极少使用的资料
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  // 某些 CString 构造函数将是显式的
#ifdef _CE_DCOM
#define _ATL_APARTMENT_THREADED
#endif

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <ceconfig.h>
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define SHELL_AYGSHELL
#endif

// Windows 头文件:
#include <windows.h>

#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#ifndef _DEVICE_RESOLUTION_AWARE
#define _DEVICE_RESOLUTION_AWARE
#endif
#endif

#ifdef _DEVICE_RESOLUTION_AWARE
#include "DeviceResolutionAware.h"
#endif

#include <aygshell.h>
#pragma comment(lib, "aygshell.lib")

#if (_WIN32_WCE < 0x500) && ( defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP) )
#pragma comment(lib, "ccrtrtti.lib")
#ifdef _X86_
#if defined(_DEBUG)
#pragma comment(lib, "libcmtx86d.lib")
#else
#pragma comment(lib, "libcmtx86.lib")
#endif
#endif
#endif

#include <altcecrt.h>

#endif
