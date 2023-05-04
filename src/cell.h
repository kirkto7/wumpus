#ifndef CELL_H
#define CELL_H

#include "entity.h"
#include "CEStudent.h"

class CEStudent;
class Entity;

class MapCell {
    int xLocation, yLocation;
    bool hasPlayer;
    CEStudent *ce;
    Entity *entity;

public:
    MapCell(int x, int y);
    bool occupied();
    char display();
    void enter();
    void vacate();
    bool hasSomething();
    void addCE(CEStudent *ceStudent);
    void addEntity(Entity *something);
    bool hasCE();
    bool hasEntity();
};

#endif // CELL_H