///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Builder Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/10


#include "stdafx.h"
#include "Builder.h"



namespace builder {

char* BicyclePart::names[NPARTS] = {
    "Frame", "Wheel", "Seat", "Derailleur", "Handlebar", "Sprocket", "Rack", "Shock"
};

BicyclePart::BicyclePart(BPart bp) {
    id = bp;
}

Bicycle::~Bicycle() {
    common_functions::purge(parts);
}
void Bicycle::addPart(BicyclePart *bp) {
    parts.push_back(bp);
}

BicycleBuilder::BicycleBuilder() {
    product = nullptr;
}
void BicycleBuilder::createProduct() {
    product = new Bicycle;
}
Bicycle* BicycleBuilder::getProduct() {
    Bicycle *temp = product;
    product = nullptr;
    return temp;
}

void MountainBikeBuilder::buildFrame() {
    product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void MountainBikeBuilder::buildWheel() {
    product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void MountainBikeBuilder::buildSeat() {
    product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void MountainBikeBuilder::buildDerailleur() {
    product->addPart(new BicyclePart(BicyclePart::DERAILLEUR));
}
void MountainBikeBuilder::buildHandlebar() {
    product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}
void MountainBikeBuilder::buildSprocket() {
    product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void MountainBikeBuilder::buildRack() {
}
void MountainBikeBuilder::buildShock() {
    product->addPart(new BicyclePart(BicyclePart::SHOCK));
}
string MountainBikeBuilder::getBikeName() const {
    return "MountainBike";
}

void TouringBikeBuilder::buildFrame() {
    product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void TouringBikeBuilder::buildWheel() {
    product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void TouringBikeBuilder::buildSeat() {
    product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void TouringBikeBuilder::buildDerailleur() {
    product->addPart(new BicyclePart(BicyclePart::DERAILLEUR));
}
void TouringBikeBuilder::buildHandlebar() {
    product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}
void TouringBikeBuilder::buildSprocket() {
    product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void TouringBikeBuilder::buildRack() {
    product->addPart(new BicyclePart(BicyclePart::RACK));
}
void TouringBikeBuilder::buildShock() {
}
string TouringBikeBuilder::getBikeName() const {
    return "TouringBike";
}

void RacingBikeBuilder::buildFrame() {
    product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void RacingBikeBuilder::buildWheel() {
    product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void RacingBikeBuilder::buildSeat() {
    product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void RacingBikeBuilder::buildDerailleur() {
}
void RacingBikeBuilder::buildHandlebar() {
    product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}
void RacingBikeBuilder::buildSprocket() {
    product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void RacingBikeBuilder::buildRack() {
}
void RacingBikeBuilder::buildShock() {
}
string RacingBikeBuilder::getBikeName() const {
    return "RacingBike";
}

BicycleTechnician::BicycleTechnician() {
    builder = nullptr;
}
void BicycleTechnician::setBuilder(BicycleBuilder *b) {
    builder = b;
}
void BicycleTechnician::construct() {
    assert(builder);
    builder->createProduct();
    builder->buildFrame();
    builder->buildWheel();
    builder->buildSeat();
    builder->buildDerailleur();
    builder->buildHandlebar();
    builder->buildSprocket();
    builder->buildRack();
    builder->buildShock();
}

Bicycle* buildMeABike(BicycleTechnician &t, BicycleBuilder *builder) {
    t.setBuilder(builder);
    t.construct();
    Bicycle *b = builder->getProduct();
    cout << "Built a " << builder->getBikeName() << endl;
    return b;
}

void test_builder() {
    //Create an order for some bicycle
    map<string, size_t> order;
    order["mountain"]   = 2;
    order["touring"]    = 1;
    order["racing"]     = 3;

    //Build bikes
    vector<Bicycle*> bikes;
    BicycleBuilder *m   = new MountainBikeBuilder;
    BicycleBuilder *t   = new TouringBikeBuilder;
    BicycleBuilder *r   = new RacingBikeBuilder;
    BicycleTechnician tech;

    auto pos = order.begin();
    while (pos != order.end()) {
        BicycleBuilder *builder = nullptr;
        if (pos->first == "mountain") {
            builder = m;
        } else if (pos->first == "touring") {
            builder = t;
        } else if (pos->first == "racing") {
            builder = r;
        } else {
            builder = nullptr;
        }
        assert(builder);

        for (size_t i = 0; i < pos->second; ++i) {
            bikes.push_back(buildMeABike(tech, builder));
        }

        ++pos;
    }

    delete m;
    delete t;
    delete r;

    //Display inventory
    for (size_t i = 0; i < bikes.size(); ++i) {
        cout << "Bicycle: " << *bikes[i] << endl;
    }

    common_functions::purge(bikes);
}

}//namespace builder

