#include "entity.h"

using namespace std;

Entity::Entity() {
    name = "Entity";
    token = 'E';
}

char Entity::display() {
    return token;
}

string Entity::getName() {
    return name;
}