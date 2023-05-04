#ifndef CELL_H
#define CELL_H

class Entity;
#include "entity.h"


class MapCell {
    int xLocation, yLocation;
    bool hasPlayer;
    Entity *entity;

public:
    MapCell(int x, int y);
    char display();
    void enter();
    void vacate();
    void addEntity(Entity *something);
    bool hasEntity();
    Entity* getEntity() { return entity;}
};

#endif // CELL_H