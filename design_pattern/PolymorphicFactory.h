///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Polymorphic Factory Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/05

#pragma once
#ifndef POLYMORPHIC_FACTORY_H
#define POLYMORPHIC_FACTORY_H

namespace polymorphic_factory {

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape() {}
};

//基类工厂
class ShapeFactory {
    virtual Shape* create() = 0;
    static map<string, ShapeFactory*> factories;
public:
    virtual ~ShapeFactory() {}
    friend class ShapeFactoryInitializer;
    class BadShapeCreation : public logic_error {
    public:
        explicit BadShapeCreation(string const& type) : logic_error("Cannot cretae type " + type) {
        }
    };
    static Shape* cretaeShape(const string &id) throw(BadShapeCreation) {
        auto const &pos = factories.find(id);
        if (pos != factories.end()) {
            return pos->second->create();
        }
        throw BadShapeCreation(id);
    }
};

map<string, ShapeFactory*> ShapeFactory::factories;

class Circle : public Shape {
    Circle() {}
    friend class ShapeFactoryInitializer;
    class Factory;
    friend class Factory;
    //继承基类工厂，重写方法 create
    class Factory : public ShapeFactory {
    public:
        Shape* create() {
            return new Circle;
        }
        friend class ShapeFactoryInitializer;
    };
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

class Square : public Shape {
    Square() {}
    friend class ShapeFactoryInitializer;
    class Factory;
    friend class Factory;
    //继承基类工厂，重写方法 create
    class Factory : public ShapeFactory {
    public:
        Shape* create() {
            return new Square;
        }
        friend class ShapeFactoryInitializer;
    };
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

class ShapeFactoryInitializer {
    static ShapeFactoryInitializer si;
    ShapeFactoryInitializer() {
        //注册：新建类各自的工厂对象到工厂对象集合中
        ShapeFactory::factories["Circle"] = new Circle::Factory;
        ShapeFactory::factories["Square"] = new Square::Factory;
    }
    ~ShapeFactoryInitializer() {
        auto pos = ShapeFactory::factories.begin();
        while (pos != ShapeFactory::factories.end()) {
            if (pos->second) {
                delete pos->second;
                pos->second = nullptr;
            }
            ++pos;
        }
    }
};

ShapeFactoryInitializer ShapeFactoryInitializer::si;

int test_polymorphic_factory() {
    char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };
    vector<Shape*> shapes;
    try {
        size_t const &size = sizeof sl / sizeof sl[0];
        for (size_t i = 0; i < size; ++i) {
            shapes.push_back(ShapeFactory::cretaeShape(sl[i]));
        }
    } catch (ShapeFactory::BadShapeCreation const &e) {
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

}//namespace polymorphic_factory

#endif  //POLYMORPHIC_FACTORY_H
