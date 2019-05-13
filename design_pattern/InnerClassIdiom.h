/*
copyright:    deguangchow@qq.com
data:        2018/04/27
autor:        deguangchow
brief:        设计模式：观察者模式。
*/
#pragma once
#ifndef INNER_CLASSI_DIOM_H
#define INNER_CLASSI_DIOM_H

namespace inner_outer {


//接口类：Poingable
class Poingable {
public:
    virtual void poing() = 0;
};

void callPoing(Poingable &p);

//接口类：Boingalbe
class Boingalbe {
public:
    virtual void boing() = 0;
};

void callBoing(Boingalbe &b);

//外部类：Outer
class Outer {
    string name;

    //定义内部类1：Inner1，用以实现接口类：Poingable
    class Inner1;
    friend class Outer::Inner1;
    class Inner : public Poingable {
        Outer *parent;
    public:
        explicit Inner(Outer *p) : parent(p) {
        }
        void poing() {
            cout << "poing called for " << parent->name.c_str() << endl;
        }
    }inner1;

    //定义内部类2：Inner2，用以实现接口类：Boingalbe
    class Inner2;
    friend class Outer::Inner2;
    class Inner2 : public Boingalbe {
        Outer *parent;
    public:
        explicit Inner2(Outer *p) : parent(p) {
        }
        void boing() {
            cout << "boing called for " << parent->name.c_str() << endl;
        }
    }inner2;

public:
    explicit Outer(const string & nm) : name(nm), inner1(this), inner2(this) {
    }

    //运算符重载：
    //强制 Poingable 引用类型转换运算符的重载
    operator Poingable&() {
        return inner1;
    }

    //强制 Boingalbe 引用类型转换运算符的重载
    operator Boingalbe&() {
        return inner2;
    }
};

void test_outer();

}//namespace inner_outer

#endif    //INNER_CLASSI_DIOM_H

