/*
copyright:    deguangchow@qq.com
data:        2018/04/28
autor:        deguangchow
brief:        设计模式：观察者模式，观察者类 Observer
*/
#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

namespace observer {

class Notifier;    //通知者类
class Argument {};    //参数类（此处未定义，可以是任意类型）

//观察者类：Observer
class Observer {
public:
    //当被观察的对象发生改变时，以下方法由被观察对象的通知器来通知调用。
    virtual void update(Notifier *o, Argument *arg) = 0;
    virtual ~Observer() {
    }
};

}//namespace observer

#endif    //OBSERVER_H

