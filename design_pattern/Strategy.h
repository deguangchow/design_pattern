///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Strategy Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/03

#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H

namespace strategy {

class NameStrategy {
public:
    virtual void greet() = 0;
};

class SayHi : public NameStrategy {
public:
    void greet() {
        cout << "Hi! How`s it going?" << endl;
    }
};

class Ignore : public NameStrategy {
public:
    void greet() {
        cout << "(Pretend I don`t see you)" << endl;
    }
};

class Admission : public NameStrategy {
public:
    void greet() {
        cout << "I`m sorry, I forgot your name." << endl;
    }
};

//The "Context" controls the strategy
class Context {
    NameStrategy &strategy;
public:
    explicit Context(NameStrategy& strat) : strategy(strat) {
    }
    void greet() {
        strategy.greet();
    }
};

void test_strategy() {
    SayHi sayhi;
    Ignore ignore;
    Admission adminssion;
    Context c1(sayhi), c2(ignore), c3(adminssion);
    c1.greet();
    c2.greet();
    c3.greet();
}

}//namespace strategy

#endif  //STRATEGY_H
