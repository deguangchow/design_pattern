///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    InnerClassIdiom
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/13

#include "stdafx.h"
#include "InnerClassIdiom.h"

namespace inner_outer {


void callPoing(Poingable &p) {
    p.poing();
}

void callBoing(Boingalbe &b) {
    b.boing();
}

void test_outer() {
    Outer outer("Outer Object");
    callPoing(outer);
    callBoing(outer);
}

}//namespace inner_outer

