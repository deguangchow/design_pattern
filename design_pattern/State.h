///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    State pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/03

#pragma once
#ifndef STATE_H
#define STATE_H

namespace state {

#if 0
class Creature {
    bool isFrog;
public:
    Creature() : isFrog(true) {
    }
    void greet() {
        if (isFrog) {
            cout << "Ribbet!" << endl;
        } else {
            cout << "Darling!" << endl;
        }
    }
    void kiss() {
        isFrog = false;
    }
};
#else
class Creature {
    class State {
    public:
        virtual string response() = 0;
    };
    class Frog : public State {
    public:
        string response() {
            return "Ribbet! ";
        }
    };
    class Prince : public State {
    public:
        string response() {
            return "Darling!";
        }
    };

    State *m_pState;

public:
    Creature() : m_pState(new Frog()) {
    }
    ~Creature() {
        if (m_pState) {
            delete m_pState;
        }
        m_pState = nullptr;
    }
    void greet() {
        cout << m_pState->response() << endl;
    }
    void kiss() {
        if (m_pState) {
            delete m_pState;
        }
        m_pState = new Prince();
    }
};
#endif

void test_state() {
    Creature creature;
    creature.greet();
    creature.kiss();
    creature.greet();
}

}//namespace state

#endif  //STATE_H
