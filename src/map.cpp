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
    int CEX = rand() % range;
    int CEY = rand() % range;
    int stairwellX = rand() % range;
    int stairwellY = rand() % range;
    int classroomX = rand() % range;
    int classroomY = rand() % range;
    for (size_t x = 0; x < WIDTH; x++)
    {
        for (size_t y = 0; y < HEIGHT; y++)
        {
            cells[x][y] = new MapCell(x, y);
        }
    }

    while (cells[CEX][CEY]->hasEntity() || (CEX == playerX && CEY == playerY)) 
    {
        CEX = rand() % range;
        CEY = rand() % range;
    }
    cells[CEX][CEY]->addEntity(new CEStudent());

    while (cells[stairwellX][stairwellY]->hasEntity() || (stairwellX == playerX && stairwellY == playerY))
    {
        stairwellX = rand() % range;
        stairwellY = rand() % range;
    }
    cells[stairwellX][stairwellY]->addEntity(new Stairwell());
    
    while (cells[classroomX][classroomY]->hasEntity() || (classroomX == playerX && classroomY == playerY))
    {
        classroomX = rand() % range;
        classroomY = rand() % range;
    }
    cells[classroomX][classroomY]->addEntity(new Classroom());
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