///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Multi-Inheritance
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/11

#pragma once
#ifndef MI_H
#define MI_H

namespace mi {

class Printable {
public:
    Printable() {
    }
    virtual ~Printable() {
    }
    virtual void print(ostream &) const = 0;
};

class Intable {
public:
    Intable() {
    }
    virtual ~Intable() {
    }
    virtual int toInt() const = 0;
};

class Stringable {
public:
    Stringable() {
    }
    virtual ~Stringable() {
    }
    virtual string toString() const = 0;
};

class Able : public Printable, public Intable, public Stringable {
    int myData;
public:
    ~Able() {
    }
    explicit Able(int x) {
        myData = x;
    }
    void print(ostream &os) const {
        os << myData;
    }
    int toInt() const {
        return myData;
    }
    string toString() const {
        ostringstream oss;
        oss << myData;
        return oss.str();
    }
};

void testPrintable(Printable const &p) {
    p.print(cout);
    cout << endl;
}

void testIntable(Intable const &n) {
    cout << n.toInt() + 1 << endl;
}

void testStringable(Stringable const &s) {
    cout << s.toString() + "th" << endl;
}

void test_interface_inharitance() {
    Able a(7);
    testPrintable(a);
    testIntable(a);
    testStringable(a);
}

class AbleBase {
    int myData;
public:
    explicit AbleBase(int x) {
        myData = x;
    }
    void print(ostream &os) const {
        os << myData;
    }
    int toInt() const {
        return myData;
    }
    string toString() const {
        ostringstream oss;
        oss << myData;
        return oss.str();
    }
};

template<class Printable>
void testPrintable(Printable const&p) {
    p.print(cout);
    cout << endl;
}

template<class Intable>
void testIntable(Intable const &n) {
    cout << n.toInt() + 1 << endl;
}

template<class Stringable>
void testStringable(Stringable const &s) {
    cout << s.toString() + "th" << endl;
}

void test_template() {
    Able a(7);
    testPrintable(a);
    testIntable(a);
    testStringable(a);
}

}//namespace mi

#endif  //MI_H
