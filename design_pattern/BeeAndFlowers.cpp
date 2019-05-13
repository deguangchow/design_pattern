///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    BeeAndFlowers
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/13

#include "stdafx.h"
#include "BeeAndFlowers.h"

namespace observer {


StringVal::operator const string&() {
    return s;
}
void StringVal::visit(Chrysanthemum*) {
    s = "Chrysanthemum";
}
void StringVal::visit(Renunculus*) {
    s = "Renunculus";
}
void StringVal::visit(Gladiolus*) {
    s = "Gladiolus";
}
void Bee_Visitor::visit(Chrysanthemum*) {
    cout << "Bee visit Chrysanthemum" << endl;
}
void Bee_Visitor::visit(Renunculus*) {
    cout << "Bee visit Renunculus" << endl;
}
void Bee_Visitor::visit(Gladiolus*) {
    cout << "Bee visit Gladiolus" << endl;
}

void test_visitor() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<Acceptor*> vctFlower(10);    //接待者类对象
    generate(vctFlower.begin(), vctFlower.end(), AcceptorGen());
    StringVal sval; //访问者对象
                    //所有的接待者对象都需要来接待访问者sval
    for (auto pos = vctFlower.begin(); pos != vctFlower.end(); ++pos) {
        (*pos)->accpet(sval);
        cout << string(sval) << endl;
    }
    Bee_Visitor bee;    //访问者对象
                        //所有的接待者对象都需要来接待访问者bee
    for (auto pos = vctFlower.begin(); pos != vctFlower.end(); ++pos) {
        (*pos)->accpet(bee);
    }
}

}//namespace observer
