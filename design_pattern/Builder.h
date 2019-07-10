///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Builder Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/10

#pragma once
#ifndef BUILDER_H
#define BUILDER_H

namespace builder {



class BicyclePart {
public:
    enum BPart {
        FRAME, WHEEL, SEAT, DERAILLEUR, HANDLEBAR, SPROCKET, RACK, SHOCK, NPARTS
    };
private:
    BPart id;
    static char* names[NPARTS];
public:
    explicit BicyclePart(BPart bp);
    friend ostream& operator<<(ostream &os, BicyclePart const &bp) {
        return os << bp.names[bp.id];
    }
};

class Bicycle {
    vector<BicyclePart*> parts;
public:
    ~Bicycle();
    void addPart(BicyclePart *bp);
    friend ostream& operator<<(ostream &os, Bicycle const &b) {
        os << "{ ";
        for (size_t i = 0; i < b.parts.size(); ++i) {
            os << *b.parts[i] << ' ';
        }
        return os << '}';
    }
};

class BicycleBuilder {
protected:
    Bicycle* product;
public:
    BicycleBuilder();
    void createProduct();
    virtual void buildFrame() = 0;
    virtual void buildWheel() = 0;
    virtual void buildSeat() = 0;
    virtual void buildDerailleur() = 0;
    virtual void buildHandlebar() = 0;
    virtual void buildSprocket() = 0;
    virtual void buildRack() = 0;
    virtual void buildShock() = 0;
    virtual string getBikeName() const = 0;
    Bicycle* getProduct();
};

class MountainBikeBuilder : public BicycleBuilder {
public:
    void buildFrame();
    void buildWheel();
    void buildSeat();
    void buildDerailleur();
    void buildHandlebar();
    void buildSprocket();
    void buildRack();
    void buildShock();
    string getBikeName() const;
};

class TouringBikeBuilder : public BicycleBuilder {
public:
    void buildFrame();
    void buildWheel();
    void buildSeat();
    void buildDerailleur();
    void buildHandlebar();
    void buildSprocket();
    void buildRack();
    void buildShock();
    string getBikeName() const;
};

class RacingBikeBuilder : public BicycleBuilder {
public:
    void buildFrame();
    void buildWheel();
    void buildSeat();
    void buildDerailleur();
    void buildHandlebar();
    void buildSprocket();
    void buildRack();
    void buildShock();
    string getBikeName() const;
};

class BicycleTechnician {
    BicycleBuilder *builder;
public:
    BicycleTechnician();
    void setBuilder(BicycleBuilder *b);
    void construct();
};

//Constructs a bike via a concrete builder
Bicycle* buildMeABike(BicycleTechnician &t, BicycleBuilder *builder);

void test_builder();

}//namespace builder

#endif  //BUILDER_H
