///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    ObservedFlower
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/13

#include "stdafx.h"
#include "ObservedFlower.h"

namespace observer {


Flower::Flower() : isOpen(false), openNotifier(this), closeNotifier(this) {
}
void Flower::open() {
    cout << "The flower is openning" << endl;
    isOpen = true;
    openNotifier.notifyObservers();
    closeNotifier.open();
}
void Flower::close() {
    cout << "The flower is closing" << endl;
    isOpen = false;
    closeNotifier.notifyObservers();
    openNotifier.close();
}
Flower::CloseNotifier::CloseNotifier(Flower *f) :outer(f), alreadyClose(false) {
}
void Flower::CloseNotifier::notifyObservers(Argument *arg /*= 0*/) {
    if (!outer->isOpen && !alreadyClose) {
        setChanged();
        Notifier::notifyObservers(arg);
        alreadyClose = true;
    }
}
void Flower::CloseNotifier::open() {
    alreadyClose = false;
}
Flower::OpenNotifier::OpenNotifier(Flower *f) : outer(f), alreadyOpen(false) {
}
void Flower::OpenNotifier::notifyObservers(Argument *arg /*= 0*/) {
    if (outer->isOpen && !alreadyOpen) {
        setChanged();
        Notifier::notifyObservers(arg);
        alreadyOpen = true;
    }
}
void Flower::OpenNotifier::close() {
    alreadyOpen = false;
}

void test_observer() {
    Flower f;
    Bee ba("BA"), bb("BB");
    Hummingbird ha("HA"), hb("HB");
    f.openNotifier.addObserver(ba.openObserver());
    f.openNotifier.addObserver(bb.openObserver());
    f.openNotifier.addObserver(ha.openObserver());
    f.openNotifier.addObserver(hb.openObserver());
    f.closeNotifier.addObserver(ba.closeObserver());
    f.closeNotifier.addObserver(bb.closeObserver());
    f.closeNotifier.addObserver(ha.closeObserver());
    f.closeNotifier.addObserver(hb.closeObserver());
    f.open();
    f.close();
    //ha 想睡懒觉，开花时不通知 ha 吃早饭
    f.openNotifier.deleteObserver(ha.openObserver());
    f.open();
    f.close();
    //ba 不想睡觉，花谢时不通知 ba 睡觉
    f.closeNotifier.deleteObserver(ba.closeObserver());
    f.open();
    f.close();
}

}//namespace observer

