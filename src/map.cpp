#include "map.h"
#include "entity.h"
#include <iostream>

using namespace std;

Map::Map() {
    for (size_t x = 0; x < WIDTH; x++)
    {
        for (size_t y = 0; y < HEIGHT; y++)
        {
            cells[x][y] = nullptr;
        }
    }
    CEAlive = true;
}

void Map::load(int playerX, int playerY) {
    int range = 5;
    
    for (size_t x = 0; x < WIDTH; x++)
    {
        for (size_t y = 0; y < HEIGHT; y++)
        {
            cells[x][y] = new MapCell(x, y);
        }
    }

    spawnEntity(range, playerX, playerY, new CEStudent());
    spawnEntity(range, playerX, playerY, new Stairwell());
    spawnEntity(range, playerX, playerY, new Classroom());
}

void Map::write() {
    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            cout << cells[x][y]->display();
        }
        cout << endl;
    }
}

MapCell* Map::getCell(int x, int y) {
    return cells[x][y];
}

void Map::spawnEntity(int range, int playerX, int playerY, Entity* entity) {
    int x = rand() % range;
    int y = rand() % range;

    while (cells[x][y]->hasEntity() || (x == playerX && y == playerY)) 
    {
        x = rand() % range;
        y = rand() % range;
    }
    cells[x][y]->addEntity(entity);
}

void Map::spawnCE(int playerX, int playerY) {
    spawnEntity(this->WIDTH - 1, playerX, playerY, new CEStudent());
}