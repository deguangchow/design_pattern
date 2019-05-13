/*
copyright:    deguangchow@qq.com
data:        2018/04/30
autor:        deguangchow
brief:        设计模式：访问者模式。区分访问者和接待者。
*/
#pragma once
#ifndef BEEANDFLOWERS_H
#define BEEANDFLOWERS_H

namespace visitor {

class Gladiolus;
class Renunculus;
class Chrysanthemum;

//访问者类
class Visitor {
public:
    //访问函数：根据不同类型的接待者，添加多个访函数
    virtual void visit(Gladiolus *f) = 0;
    virtual void visit(Renunculus *f) = 0;
    virtual void visit(Chrysanthemum *f) = 0;
    virtual ~Visitor() {
    }
};

//来访的是获取接待者对象信息的类：StringVal
class StringVal : public Visitor {
    string s;
public:
    operator const string&();
    //访问函数：获取不同类型的接待者对象的信息
    virtual void visit(Gladiolus*);
    virtual void visit(Renunculus*);
    virtual void visit(Chrysanthemum*);
};

//来访的是操作接待者对象的蜜蜂类：Bee_Visitor
class Bee_Visitor : public Visitor {
public:
    //访问函数：输出不同类型的接待者对象的信息
    virtual void visit(Gladiolus*);
    virtual void visit(Renunculus*);
    virtual void visit(Chrysanthemum*);
};


//接待者类
class Acceptor {
public:
    //接待函数：接待访问者的来访，来对对象本身进行相关visit操作
    virtual void accpet(Visitor &) = 0;
    virtual ~Acceptor() {
    }
};
//剑兰
class Gladiolus : public Acceptor {
    void accpet(Visitor &v) {
        v.visit(this);
    }
};
//毛茛
class Renunculus : public Acceptor {
    void accpet(Visitor &v) {
        v.visit(this);
    }
};
//菊花
class Chrysanthemum : public Acceptor {
    void accpet(Visitor &v) {
        v.visit(this);
    }
};

//不同类型的接待者对象生成器
struct AcceptorGen {
    Acceptor* operator()() {
        std::random_device rd;
        switch (rd() % 3) {
        case 0: {return new Gladiolus; }
        case 1: {return new Renunculus; }
        case 2: {return new Chrysanthemum; }
        default: {return new Gladiolus(); }
        }
    }
};

void test_visitor();

}//namespace visitor


#endif    //BEEANDFLOWERS_H

