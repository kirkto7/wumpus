#include "cell.h"
#include <iostream>

using namespace std;

MapCell::MapCell(int x, int y) {
    xLocation = x;
    yLocation = y;
    hasPlayer = false;
    ce = nullptr;
    entity = nullptr;
}

// Marks the current cell as occupied if it contains a ce or entity
bool MapCell::occupied() {
    bool result = false;
    if (hasCE() || hasEntity())
    {
        result = true;
    }
    return result;
}


char MapCell::display() {
    if (hasPlayer) 
    {
        return 'P';
    } else if(hasSomething()) {
        if(hasCE()) {
            return ce->display();
        } else if (hasEntity()) {
            return entity->display();
        }
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

bool MapCell::hasSomething() { //might not need this method depending on how you code deodorant
    bool result = false;
    if (occupied() || hasEntity())
    {
        result = true;
    }
    return result;
}

void MapCell::addCE(CEStudent *ceStudent) {
    ce = ceStudent;
}

void MapCell::addEntity(Entity *something) {
    entity = something;
}

bool MapCell::hasCE() {
    bool result = false;
    if (ce != nullptr)
    {
        result = true;
    }
    return result;
}

bool MapCell::hasEntity() {
    bool result = false;
    if (entity != nullptr) 
    {
        result = true;
    }
    return result;
}
