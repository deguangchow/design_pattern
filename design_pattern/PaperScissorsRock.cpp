///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    PaperScissorsRock
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/13
#include "stdafx.h"
#include "PaperScissorsRock.h"

namespace paper_scissors_rock {

ostream& operator<<(ostream& os, const Outcome out) {
    switch (out) {
    case WIN: {return os << "win"; }
    case LOSE: {return os << "lose"; }
    case DRAW: {return os << "draw"; }
    default: {return os << "error"; }
    }
}

Outcome Paper::compete(const Item *it) {
    return it->eval(this);
}
Outcome Paper::eval(const Rock*) const {
    return LOSE;
}
Outcome Paper::eval(const Scissors*) const {
    return WIN;
}
Outcome Paper::eval(const Paper*) const {
    return DRAW;
}
ostream& Paper::print(ostream& os) const {
    return os << "Paper    ";
}

Outcome Scissors::compete(const Item *it) {
    return it->eval(this);
}
Outcome Scissors::eval(const Rock*) const {
    return WIN;
}
Outcome Scissors::eval(const Scissors*) const {
    return DRAW;
}
Outcome Scissors::eval(const Paper*) const {
    return LOSE;
}
ostream& Scissors::print(ostream& os) const {
    return os << "Scissors    ";
}

Outcome Rock::compete(const Item *it) {
    return it->eval(this);
}
Outcome Rock::eval(const Rock*) const {
    return DRAW;
}
Outcome Rock::eval(const Scissors*) const {
    return LOSE;
}
Outcome Rock::eval(const Paper*) const {
    return WIN;
}
ostream& Rock::print(ostream& os) const {
    return os << "Rock    ";
}

void test_multiple_dispatching() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int sz = 20;
    vector<Item*> v(sz * 2);
    generate(v.begin(), v.end(), ItemGen());
    transform(v.begin(), v.begin() + sz, v.begin() + sz, ostream_iterator<Outcome>(cout, "\n"), Compete());
}

}//namespace paper_scissors_rock
