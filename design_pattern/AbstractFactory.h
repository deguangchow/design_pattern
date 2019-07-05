///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Abstract Factory Pattern.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/07/05

#pragma once
#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

namespace abstract_factory {

//道具
class Obstacle {
public:
    virtual void action() = 0;
};

class Puzzle : public Obstacle {
public:
    void action() {
        cout << "Puzzle" << endl;
    }
};

class NastyWeapon : public Obstacle {
public:
    void action() {
        cout << "NastyWeapon" << endl;
    }
};

//角色
class Player {
public:
    virtual void interactWith(Obstacle*) = 0;
};

class Kitty : public Player {
    virtual void interactWith(Obstacle* ob) {
        cout << "Kitty has encountered a ";
        ob->action();
    }
};

class KungFuGuy : public Player {
    virtual void interactWith(Obstacle* ob) {
        cout << "KungFuGuy now battles against a ";
        ob->action();
    }
};


//The abstract factory：抽象工厂类
class GameElementFactory {
public:
    virtual Player* makePlayer() = 0;
    virtual Obstacle* makeObstacle() = 0;
};

//Concrete factories：具体的工厂类
class KittiesAndPuzzies : public GameElementFactory {
public:
    Player* makePlayer() {
        return new Kitty;
    }
    Obstacle* makeObstacle() {
        return new Puzzle;
    }
};
class KillAndDismember : public GameElementFactory {
public:
    Player* makePlayer() {
        return new KungFuGuy;
    }
    Obstacle* makeObstacle() {
        return new NastyWeapon;
    }
};

class GameEnvironment {
    GameElementFactory *gef;
    Player *p;
    Obstacle *ob;
public:
    explicit GameEnvironment(GameElementFactory *factory)
        : gef(factory), p(factory->makePlayer()), ob(factory->makeObstacle()) {
    }
    void play() {
        p->interactWith(ob);
    }
    ~GameEnvironment() {
        delete p;
        delete ob;
        delete gef;
    }
};


int test_abstract_factory() {
    GameEnvironment g1(new KittiesAndPuzzies);
    GameEnvironment g2(new KillAndDismember);

    g1.play();
    g2.play();

    return 0;
}

}//namespace abstract_factory

#endif  //ABSTRACT_FACTORY_H
