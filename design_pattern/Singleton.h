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
    using ptrSingleton = std::shared_ptr <Singleton>;
    static ptrSingleton m_pSingleton;
public:
    static ptrSingleton GetInstance() {
        if (nullptr == m_pSingleton) {
            m_pSingleton.reset(new Singleton());
        }
        return m_pSingleton;
    }
};

Singleton::ptrSingleton Singleton::m_pSingleton = nullptr;

void test_singleton() {
    auto pSingleton = Singleton::GetInstance();
}


}//namespace singleton

#endif  //SINGLETON_H
