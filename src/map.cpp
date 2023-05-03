#include "map.h"
#include "cell.h"
#include "CEStudent.h"
#include "stairwell.h"
#include "deodorant.h"
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

void Map::load(int PlayerX, int playerY) {
    int range = 5;
    int CEX = rand() % range;
    int CEY = rand() % range;
    int stairwellX = rand() % range;
    int stairwellY = rand() % range;
    int deodorantX = rand() % range;
    int deodorantY = rand() % range;
    for (size_t x = 0; x < WIDTH; x++)
    {
        for (size_t y = 0; y < HEIGHT; y++)
        {
            cells[x][y] = new MapCell(x, y);
        }
    }
    
    
}