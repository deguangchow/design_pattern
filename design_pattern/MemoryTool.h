///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MemoryLeakCheck
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/14
#pragma once
#ifndef MEMORY_LEAK_CHECK_H
#define MEMORY_LEAK_CHECK_H

namespace memory_tool {


//可以定位到发生内存泄露 所在的文件和具体那一行，用于检测 malloc 分配的内存
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//检测内存泄露
inline void enable_memory_leak_check() {
    //该语句在程序退出时自动调用 _CrtDumpMemoryLeaks(),用于多个退出出口的情况.
    //如果只有一个退出位置，可以在程序退出之前调用 _CrtDumpMemoryLeaks()
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

    //{n}: 运行到第n次内存分配的时中断：n为0时则默认不中断
    _CrtSetBreakAlloc(0);
}


}//namespace memory_tool

#endif  //MEMORY_LEAK_CHECK_H
