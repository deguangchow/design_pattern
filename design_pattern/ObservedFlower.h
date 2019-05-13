/*
copyright:    deguangchow@qq.com
data:        2018/04/28
autor:        deguangchow
brief:        设计模式：观察者模式，例子。
*/
#pragma once
#ifndef OBSERVEDFLOWER_H
#define OBSERVEDFLOWER_H
#include "Notifier.h"

namespace observer {

//通知者类 Flower：
//含有2个内部类：花开通知者类、花谢通知者类
class Flower {
private:
    bool isOpen;

public:
    //内部类：花开通知类
    class OpenNotifier;
    friend class Flower::OpenNotifier;
    class OpenNotifier : public Notifier {
    private:
        Flower *outer;
        bool alreadyOpen;
    public:
        explicit OpenNotifier(Flower *f);
        //通知函数：通知观察者
        void notifyObservers(Argument *arg = 0);
        void close();
    }openNotifier;    //花开通知器

    //内部类：花谢通知类
    class CloseNotifier;
    friend class Flower::CloseNotifier;
    class CloseNotifier : public Notifier {
    private:
        Flower *outer;
        bool alreadyClose;
    public:
        explicit CloseNotifier(Flower *f);
        //通知函数：通知观察者
        void notifyObservers(Argument *arg = 0);
        void open();
    }closeNotifier;    //花谢通知器

    Flower();

    //花开：花开通知类对象调用通知方法，花谢通知类对象调用花开方法。
    void open();

    //花谢：花谢通知类对象调用通知方法，花开通知类对象调用花谢方法。
    void close();
};

class Bee {
private:
    string name;

    //内部类1：花开观察类，用来观察花开
    class OpenObserver;
    friend class Bee::OpenObserver;
    class OpenObserver : public Observer {
    private:
        Bee *outer;
    public:
        explicit OpenObserver(Bee *b) : outer(b) {
        }
        void update(Notifier *o, Argument *arg) {
            cout << "Bee " << outer->name << "`s breakfast time!" << endl;
        }
    }openObsrv;

    //内部类2：花谢观察类，用来观察花谢
    class CloseObserver;
    friend class Bee::CloseObserver;
    class CloseObserver : public Observer {
    private:
        Bee *parent;
    public:
        explicit CloseObserver(Bee *b) :parent(b) {
        }
        void update(Notifier *o, Argument *arg) {
            cout << "Bee " << parent->name << "`s bed time!" << endl;
        }
    }closeObsrv;

public:
    explicit Bee(string nm) : name(nm), openObsrv(this), closeObsrv(this) {
    }
    Observer& openObserver() {
        return openObsrv;
    }
    Observer& closeObserver() {
        return closeObsrv;
    }
};

class Hummingbird {
    string name;
    //内部类1：花开观察者类
    class OpenObserver;
    friend class Hummingbird::OpenObserver;
    class OpenObserver : public Observer {
        Hummingbird *parent;
    public:
        explicit OpenObserver(Hummingbird *h) : parent(h) {
        }
        void update(Notifier *o, Argument *arg) {
            cout << "Hummingbird " << parent->name << "`s breakfast time!" << endl;
        }
    }openObsrv;

    //内部类2：花谢观察者类
    class CloseObserver;
    friend class Hummingbird::CloseObserver;
    class CloseObserver : public Observer {
        Hummingbird *outer;
    public:
        explicit CloseObserver(Hummingbird *h) : outer(h) {
        }
        void update(Notifier *o, Argument *arg) {
            cout << "Hummingbird " << outer->name << "`s bed time!" << endl;
        }
    }closeObsrv;

public:
    explicit Hummingbird(string nm) : name(nm), openObsrv(this), closeObsrv(this) {
    }
    Observer& openObserver() {
        return openObsrv;
    }
    Observer& closeObserver() {
        return closeObsrv;
    }
};

void test_observer();

}//namespace observer

#endif    //OBSERVEDFLOWER_H

