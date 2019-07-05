///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Factory Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/05

#pragma once
#ifndef FACTORY_H
#define FACTORY_H

namespace factory {

//形状
class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}

    class BadShapeCreation : public logic_error {
    public:
        explicit BadShapeCreation(string type) : logic_error("Cannot create type " + type) {
        }
    };
    static Shape* factory(const string &type)
        throw(BadShapeCreation);
};

//圆形
class Circle : public Shape {
    Circle() {}
    friend class Shape;
public:
    void draw() {
        cout << "Circle::draw" << endl;
    }
    void erase() {
        cout << "Circle::erase" << endl;
    }
    ~Circle() {
        cout << "Circle::~Circle" << endl;
    }
};

//正方形
class Square : public Shape {
    Square() {}
    friend class Shape;
public:
    void draw() {
        cout << "Square::draw" << endl;
    }
    void erase() {
        cout << "Square::erase" << endl;
    }
    ~Square() {
        cout << "Square::~Square" << endl;
    }
};

//形状成员函数：工厂
Shape* Shape::factory(const string &type) throw(BadShapeCreation) {
    if (type == "Circle") {
        return new Circle;
    }
    if (type == "Square") {
        return new Square;
    }
    throw BadShapeCreation(type);
}


int test_factory() {
    char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };
    vector<Shape*> shapes;
    try {
        size_t const &size = sizeof sl / sizeof sl[0];
        for (size_t i = 0; i < size; ++i) {
            shapes.push_back(Shape::factory(sl[i]));
        }
    } catch (Shape::BadShapeCreation const &e) {
        cout << e.what() << endl;
        common_functions::purge(shapes);
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->draw();
        shapes[i]->erase();
    }
    common_functions::purge(shapes);

    return 0;
}

}//namespace factory

#endif  //FACTORY_H
