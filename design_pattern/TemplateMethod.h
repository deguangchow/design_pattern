///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Template Method Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/03

#pragma once
#ifndef TEMPLATE_METHOD_H
#define TEMPLATE_METHOD_H

namespace template_method {

class ApplicationFramework {
protected:
    virtual void customize1() = 0;
    virtual void customize2() = 0;
public:
    void templateMethod() {
        for (int i = 0; i < 5; ++i) {
            customize1();
            customize2();
        }
    }
};

//Create a new "application"
class MyApp : public ApplicationFramework {
protected:
    void customize1() {
        cout << "Hello ";
    }
    void customize2() {
        cout << "World!" << endl;
    }
};

void test_template_method() {
    MyApp app;
    app.templateMethod();
}

}//namespace template_method

#endif  //TEMPLATE_METHOD_H
