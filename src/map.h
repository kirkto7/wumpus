#ifndef MAP_H
#define MAP_H

#include "cell.h"
class MapCell;

class Map {
    static constexpr int HEIGHT = 6;
    static constexpr int WIDTH = 6;
    MapCell *cells[WIDTH][HEIGHT];
    bool CEAlive;
public:
    Map();
    void load(int playerX, int playerY);
    void write();
    MapCell* getCell(int x, int y);
    void spawnEntity(int range, int playerX, int playerY, Entity* entity);
    void spawnCE(int playerX, int playerY);
    int getWIDTH() {return WIDTH;}
    int getHEIGHT() {return HEIGHT;}
};

#endif // MAP_H