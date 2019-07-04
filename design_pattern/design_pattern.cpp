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
#include "Singleton.h"
#include "Command.h"
#include "Proxy.h"
#include "State.h"
#include "TemplateMethod.h"
#include "Strategy.h"
#include "ChainOfResponsibility.h"


int main() {
    memory_tool::enable_memory_leak_check();

#if 0
    inner_outer::test_outer();
    observer::test_observer();

    paper_scissors_rock::test_multiple_dispatching();

    visitor::test_visitor();

    singleton::test_singleton();
    singleton::test_singletonT();

    command::test_command();
    command::test_multicase_command();

    proxy::test_proxy();

    state::test_state();

    adapter::test_adapter();
    adapter::test_FibonacciGenerator();
    adapter::test_FibonacciAdapter();
    template_method::test_template_method();

    strategy::test_strategy();
#endif

    chain_of_responsibility::test_chain_of_responsibility();

    return 0;
}

