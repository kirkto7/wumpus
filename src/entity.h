#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    Entity();
    char display();
    std::string getName();
private:
    char token;
    std::string name;
};

#endif // ENTITY_H