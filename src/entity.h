#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    Entity();
    char display();
    void getHealth();
    int damage();
    std::string getName();
private:
    char token;
    int damage;
    int health;
    std::string name;
};

#endif // ENTITY_H