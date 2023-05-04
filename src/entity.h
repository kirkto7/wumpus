#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include "player.h"
class Player;

class Entity {
public:
    Entity();
    char display();
    std::string getName();
    virtual void act(Player* player) = 0;
    virtual void printWarning() = 0;
private:
    char token;
    std::string name;
};

class Stairwell : public Entity {
public:
    Stairwell();
    void act(Player* player) override;
    void printWarning() override;
    
private:
    char token;
};

class Classroom : public Entity {
public:
    Classroom();
    void printWarning() override;
    void act(Player* player) override;

private:
    char token;
};

class CEStudent : public Entity {
public:
    CEStudent();
    char display();
    void act(Player* player) override;
    void printWarning() override;

private:
    char token;
};



#endif // ENTITY_H