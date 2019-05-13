///  Copyright (C) 2018 cpp_prime5 DG.C
///      http://www.futuresoft.com.cn
///
/// \brief 定义控制台应用程序的入口点
///
/// \author zhoudeguang
/// \version 1.0
/// \2018/05/03
#include "stdafx.h"
#include "InnerClassIdiom.h"
#include "ObservedFlower.h"
#include "PaperScissorsRock.h"
#include "BeeAndFlowers.h"


int main() {
#if 0
    inner_outer::test_outer();
    observer::test_observer();
    paper_scissors_rock::test_multiple_dispatching();
#endif

    observer::test_visitor();
    return 0;
}

