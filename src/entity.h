#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include "player.h"
class Player;

class Entity {
public:
    Entity();
    virtual char display() = 0;
    std::string getName();
    virtual void act(Player* player) = 0;
    virtual void printWarning() = 0;
private:
    std::string name;
};

class Stairwell : public Entity {
public:
    Stairwell(){}
    char display() override;
    void act(Player* player) override;
    void printWarning() override;
};

class Classroom : public Entity {
public:
    Classroom(){}
    char display() override;
    void printWarning() override;
    void act(Player* player) override;
};

class CEStudent : public Entity {
public:
    CEStudent(){}
    char display() override;
    void act(Player* player) override;
    void printWarning() override;
};



#endif // ENTITY_H