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
    void removeEntity() {entity = nullptr;}
    Entity* getEntity() { return entity;}
    bool cellHasPlayer() { return hasPlayer;}
};

#endif // CELL_H