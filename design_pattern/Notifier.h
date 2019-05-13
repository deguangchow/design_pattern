/*
copyright:    deguangchow@qq.com
data:        2018/04/28
autor:        deguangchow
brief:        设计模式：观察者模式，通知者类 Notifier
*/
#pragma once
#ifndef NOTIFIER_H
#define NOTIFIER_H
#include "Observer.h"

namespace observer {

//通知者类：Notifier
class Notifier {
private:
    bool changed;
    std::set<Observer*> observers;    //需要通知的观察者对象集合

protected:
    virtual void setChanged() { changed = true; }
    virtual void clearChanged() { changed = false; }

public:
    virtual void addObserver(Observer &o) {
        observers.insert(&o);
    }
    virtual void deleteObserver(Observer &o) {
        observers.erase(&o);
    }
    virtual void deleteObservers() {
        observers.clear();
    }
    virtual size_t countObservers() {
        return observers.size();
    }
    virtual bool hasChanged() {
        return changed;
    }

    //被观察者类Observable的通知函数：当对象状态改变时，通知观察的所有对象。
    virtual void notifyObservers(Argument *arg = 0) {
        if (!hasChanged()) {
            return;
        }
        clearChanged();
        for (auto pos = observers.begin(); pos != observers.end(); ++pos) {
            (*pos)->update(this, arg);
        }
    }

    virtual ~Notifier() {}
};

}//namespace observer

#endif    //OBSERVABLE_H

