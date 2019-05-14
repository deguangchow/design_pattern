///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    design_pattern
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/14

#include "stdafx.h"
#include "InnerClassIdiom.h"
#include "ObservedFlower.h"
#include "PaperScissorsRock.h"
#include "BeeAndFlowers.h"
#include "Adapter.h"
#include "MemoryTool.h"


int main() {
    memory_tool::enable_memory_leak_check();

#if 1
    inner_outer::test_outer();
    observer::test_observer();
    paper_scissors_rock::test_multiple_dispatching();
    visitor::test_visitor();
#endif

    adapter::test_adapter();
    return 0;
}

