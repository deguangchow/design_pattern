///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Singleton
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/14

#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

namespace singleton {

class Singleton {
    Singleton() {}
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    //~Singleton() {}

    typedef std::shared_ptr <Singleton> Singleton_ptr;
    static Singleton_ptr m_ptrSingleton;
public:
    static Singleton_ptr GetInstance() {
        if (nullptr == m_ptrSingleton) {
            m_ptrSingleton.reset(new Singleton());
        }
        return m_ptrSingleton;
    }
};

Singleton::Singleton_ptr Singleton::m_ptrSingleton = nullptr;

void test_singleton() {
    auto ptrSingleton = Singleton::GetInstance();
}


//Separates a class from its singleton-ness (almost).
template<class T> class SingletonT {
    SingletonT(SingletonT const&) = delete;
    SingletonT& operator=(SingletonT const&) = delete;
protected:
    SingletonT() {}
    virtual ~SingletonT() {}
public:
    static T& instance() {
        static T theInstance;
        return theInstance;
    }
};

class MyClass : public SingletonT<MyClass> {
    int x;
protected:
    friend class SingletonT<MyClass>;
    MyClass() { x = 0; }
public:
    void setValue(int n) { x = n; }
    int getValue() const { return x; }
};

void test_singletonT() {
    MyClass& m = MyClass::instance();
    cout << m.getValue() << endl;
    m.setValue(1);
    cout << m.getValue() << endl;
}


}//namespace singleton

#endif  //SINGLETON_H
