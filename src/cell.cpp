#include "cell.h"
#include <iostream>

using namespace std;

MapCell::MapCell(int x, int y) {
    xLocation = x;
    yLocation = y;
    hasPlayer = false;
    entity = nullptr;
}


char MapCell::display() {
    if (hasPlayer) 
    {
        return 'P';
    } else if(hasEntity()) {
        return entity->display();
    } else {
        return '_';
    }
}

void MapCell::enter() {
    hasPlayer = true;
    // player enters cell
}

void MapCell::vacate() {
    hasPlayer = false;
    // player leaves cell
}

void MapCell::addEntity(Entity *something) {
    entity = something;
}

bool MapCell::hasEntity() {
    bool result = false;
    if (entity != nullptr) 
    {
        result = true;
    }
    return result;
}
