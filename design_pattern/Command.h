///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Command pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/03

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

namespace command {

class Command {
public:
    virtual void execute() = 0;
};

class Hello : public Command {
public:
    void execute() {
        cout << "Hello " << endl;
    }
};

class World : public Command {
public:
    void execute() {
        cout << "World! " << endl;
    }
};

class IAm : public Command {
public:
    void execute() {
        cout << "I`m the command pattern! " << endl;
    }
};

//An Object that holds commands:
class Macro {
    vector<Command*> commands;
public:
    void add(Command* c) {
        commands.push_back(c);
    }
    void run() {
        auto &pos = commands.begin();
        while (pos != commands.end()) {
            (*pos)->execute();
            ++pos;
        }
    }
};

void test_command() {
    Macro macro;
    macro.add(new Hello);
    macro.add(new World);
    macro.add(new IAm);
    macro.run();
}


//Framework for running tasks.
class Task {
public:
    virtual void operation() = 0;
};

class TaskRunner {
    static vector<Task*> tasks;
    TaskRunner() {}
    TaskRunner& operator=(TaskRunner const&) = delete;
    TaskRunner(TaskRunner const&) = delete;
    static TaskRunner tr;
public:
    static void add(Task& t) {
        tasks.push_back(&t);
    }
    static void run() {
        auto &pos = tasks.begin();
        while (pos != tasks.end()) {
            (*pos)->operation();
            ++pos;
        }
    }
};
TaskRunner TaskRunner::tr;
vector<Task*> TaskRunner::tasks;

class EventSimulator {
    clock_t creation;
    clock_t delay;
public:
    EventSimulator() : creation(clock()) {
        delay = CLOCKS_PER_SEC / 4 * (rand() % 20 + 1);
        cout << "delay = " << delay << endl;
    }
    bool fired() {
        return clock() > creation + delay;
    }
};

//Something that can produce asynchronous events:
class Button {
    bool pressed;
    string id;
    EventSimulator e;
public:
    explicit Button(string const& name) : pressed(false), id(name) {
    }
    void press() {
        pressed = true;
    }
    bool isPressed() {
        if (e.fired()) {
            press();
        }
        return pressed;
    }
    friend ostream& operator<<(ostream& os, const Button& b) {
        return os << b.id;
    }
};

//The Command object
class CheckButton : public Task {
    Button& button;
    bool handled;
public:
    explicit CheckButton(Button &b) : button(b), handled(false) {
    }
    void operation() {
        if (button.isPressed() && !handled) {
            cout << button << " pressed" << endl;
            handled = true;
        }
    }
};

void procedure1() {
    TaskRunner::run();
}

void procedure2() {
    TaskRunner::run();
}

void procedure3() {
    TaskRunner::run();
}

void test_multicase_command() {
    srand(time(0));
    Button b1("Button 1"), b2("Button 2"), b3("Button 3");
    CheckButton cb1(b1), cb2(b2), cb3(b3);
    TaskRunner::add(cb1);
    TaskRunner::add(cb2);
    TaskRunner::add(cb3);
    cout << "Control-C to exit" << endl;
    while (true) {
        procedure1();
        procedure2();
        procedure3();
    }
}

}//namespace command

#endif  //COMMAND_H
