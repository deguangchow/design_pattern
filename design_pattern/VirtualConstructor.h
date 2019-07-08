///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Virtual Constructor.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/08

#pragma once
#ifndef VIRTUAL_CONSTRUCTOR_H
#define VIRTUAL_CONSTRUCTOR_H

namespace virtual_constructor {

class Shape {
    Shape *s;
    Shape(Shape const&);
    Shape& operator=(Shape const&);

protected:
    Shape() {
        s = nullptr;
    }

public:
    virtual void draw() {
        s->draw();
    }
    virtual void erase() {
        s->erase();
    }
    virtual void test() {
        s->test();
    }
    virtual ~Shape() {
        if (s) {
            cout << "Making virtual call: ";
            s->erase();//Virtual call
        }
        cout << "delete s: ";
        delete s;
        s = nullptr;
    }
    class BadShapeCreation : public logic_error {
    public:
        explicit BadShapeCreation(string const &type) : logic_error("Cannot create type " + type) {
        }
    };
    explicit Shape(string const &type) throw(BadShapeCreation);
};

class Circle : public Shape {
    Circle(Circle const&);
    Circle& operator=(Circle const&);
    Circle() {
    }
    friend class Shape;
public:
    void draw() {
        cout << "Circle::draw" << endl;
    }
    void erase() {
        cout << "Circle::erase" << endl;
    }
    void test() {
        draw();
    }
    ~Circle() {
        cout << "Circle::~Circle()" << endl;
    }
};

class Square : public Shape {
    Square(Square const&);
    Square& operator=(Square const&);
    Square() {
    }
    friend class Shape;
public:
    void draw() {
        cout << "Square::draw" << endl;
    }
    void erase() {
        cout << "Square::erase" << endl;
    }
    void test() {
        draw();
    }
    ~Square() {
        cout << "Square::~Square()" << endl;
    }
};

Shape::Shape(string const& type) throw(Shape::BadShapeCreation) {
    if (type == "Circle") {
        s = new Circle;
    } else if (type == "Square") {
        s = new Square;
    } else {
        throw BadShapeCreation(type);
    }
    draw();//Virtual call in the constructor
}

int test_virtual_constructor() {
    char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };
    vector<Shape*> shapes;
    auto const& size = sizeof sl / sizeof sl[0];
    try {
        for (size_t i = 0; i < size; ++i) {
            shapes.push_back(new Shape(sl[i]));
        }
    } catch (Shape::BadShapeCreation const &e) {
        cout << e.what() << endl;
        common_functions::purge(shapes);
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->draw();
        cout << "test" << endl;
        shapes[i]->test();
        cout << "end test" << endl;
        shapes[i]->erase();
    }
    Shape c("Circle");
    cout << "destructor calls:" << endl;
    common_functions::purge(shapes);
    return 0;
}

}//namespace virtual_constructor

#endif  //VIRTUAL_CONSTRUCTOR_H
