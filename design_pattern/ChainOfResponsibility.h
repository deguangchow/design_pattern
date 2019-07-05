///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Chain of responsibility pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/04

#pragma once
#ifndef CHAIN_OF_RESPONSIBLITY_H
#define CHAIN_OF_RESPONSIBLITY_H

namespace chain_of_responsibility {

enum Answer {
    NO,
    YES
};

class GimmeStrategy {
public:
    virtual Answer canIHave() = 0;
    virtual ~GimmeStrategy() {}
};

class AskMom : public GimmeStrategy {
public:
    Answer canIHave() {
        cout << "Mom, Can I have this?" << endl;
        return NO;
    }
};

class AskDad : public GimmeStrategy {
public:
    Answer canIHave() {
        cout << "Dad, I really need this!" << endl;
        return NO;
    }
};

class AskGrandpa : public GimmeStrategy {
public:
    Answer canIHave() {
        cout << "Grandpa, is it my birthday yet?" << endl;
        return NO;
    }
};

class AskGrandma : public GimmeStrategy {
public:
    Answer canIHave() {
        cout << "Grandma, I really love you!" << endl;
        return YES;
    }
};

class Gimme : public GimmeStrategy {
    vector<GimmeStrategy*> chain;
public:
    Gimme() {
        chain.push_back(new AskMom);
        chain.push_back(new AskDad);
        chain.push_back(new AskGrandpa);
        chain.push_back(new AskGrandma);
    }
    Answer canIHave() {
        auto &pos = chain.begin();
        while (pos != chain.end()) {
            if ((*pos)->canIHave() == YES) {
                return YES;
            }
            ++pos;
        }
        cout << "Whiiiiiiiinnne!" << endl;
        return NO;
    }
    ~Gimme() {
        common_functions::purge(chain);
    }
};

void test_chain_of_responsibility() {
    Gimme chain;
    chain.canIHave();
}

}//namespace chain_of_responsibility

#endif  //CHAIN_OF_RESPONSIBLITY_H
