#include "cell.h"
#include <iostream>

using namespace std;

MapCell::MapCell(int x, int y) {
    xLocation = x;
    yLocation = y;
    hasPlayer = false;
    ce = nullptr;
}

// Marks the current cell as occupied if it contains a cow or hodag
bool MapCell::occupied() {
    bool result = false;
    return result;
}

bool MapCell::hasSomething() {
    bool result = false;
    return result;
}

bool MapCell::hasCE() {
    bool result = false;
    return result;
}

char MapCell::display() {
}

int MapCell::getDamage() {
}

void MapCell::enter() {
    hasPlayer = true;
    // player enters cell
}

void MapCell::vacate() {
    hasPlayer = false;
    // player leaves cell
}
