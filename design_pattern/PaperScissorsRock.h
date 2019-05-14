/*
copyright:    deguangchow@qq.com
data:        2018/04/29
autor:        deguangchow
brief:        设计模式：多重派遣模式。举例：剪刀石头布。
*/
#pragma once
#ifndef PAPERSCISSORSROCK_H
#define PAPERSCISSORSROCK_H

namespace paper_scissors_rock {


class Paper;            //布
class Scissors;         //剪刀
class Rock;             //石头

typedef enum {
    WIN = 0,
    LOSE,
    DRAW
} Outcome;              //结果：赢、输、平


ostream& operator<<(ostream& os, const Outcome out);

class Item {
public:
    virtual Outcome compete(const Item*) = 0;
    virtual Outcome eval(const Paper*) const = 0;
    virtual Outcome eval(const Scissors*) const = 0;
    virtual Outcome eval(const Rock*) const = 0;
    virtual ostream& print(ostream& os) const = 0;
    virtual ~Item() {
    }
    friend ostream& operator<<(ostream& os, const Item* it) {
        return it->print(os);
    }
};
using ptrItem = std::shared_ptr<Item>;


class Paper : public Item {
public:
    Outcome compete(const Item *it);
    Outcome eval(const Paper*) const;
    Outcome eval(const Scissors*) const;
    Outcome eval(const Rock*) const;
    ostream& print(ostream& os) const;
};

class Scissors :public Item {
public:
    Outcome compete(const Item *it);
    Outcome eval(const Paper*) const;
    Outcome eval(const Scissors*) const;
    Outcome eval(const Rock*) const;
    ostream& print(ostream& os) const;
};


class Rock :public Item {
public:
    Outcome compete(const Item *it);
    Outcome eval(const Paper*) const;
    Outcome eval(const Scissors*) const;
    Outcome eval(const Rock*) const;
    ostream& print(ostream& os) const;
};

struct ItemGen {
    ptrItem operator()() {
        std::random_device rd;
        switch (rd() % 3) {
        case 0: {return std::make_shared<Scissors>(); }
        case 1: {return std::make_shared<Paper>(); }
        case 2: {return std::make_shared<Rock>(); }
        default: {return nullptr; }
        }
    }
};

struct Compete {
    Outcome operator()(ptrItem a, ptrItem b) {
        cout << a.get() << "\t" << b.get() << "\t";
        return  a->compete(b.get());
    }
};

void test_multiple_dispatching();

}//namespace paper_scissors_rock
#endif    //PAPERSCISSORSROCK_H
