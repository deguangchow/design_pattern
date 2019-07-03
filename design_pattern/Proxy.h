///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Proxy pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/03

#pragma once
#ifndef PROXY_H
#define PROXY_H

namespace proxy {

class ProxyBase {
public:
    virtual void f() = 0;
    virtual void g() = 0;
    virtual void h() = 0;
    virtual ~ProxyBase() {
    }
};

class Implemetation : public ProxyBase {
public:
    void f() {
        cout << "Implemetation.f()" << endl;
    }
    void g() {
        cout << "Implemetation.g()" << endl;
    }
    void h() {
        cout << "Implemetation.h()" << endl;
    }
};

class Proxy : public ProxyBase {
    ProxyBase *implemetation;
public:
    Proxy() {
        implemetation = new Implemetation();
    }
    ~Proxy() {
        if (implemetation) {
            delete implemetation;
        }
        implemetation = nullptr;
    }
    //Forward calls to the implementation:
    void f() {
        implemetation->f();
    }
    void g() {
        implemetation->g();
    }
    void h() {
        implemetation->h();
    }
};

void test_proxy() {
    Proxy p;
    p.f();
    p.g();
    p.h();
}

}//namespace proxy

#endif  //PROXY_H
