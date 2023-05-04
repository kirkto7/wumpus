#include "entity.h"
#include <iostream>

using namespace std;

Stairwell::Stairwell() {
    token = 'S';
}

void Stairwell::act(Player* player) {
    int x = rand() % 5;
    int y = rand() % 5;
    player->place(x,y);
}

void Stairwell::printWarning() {
    cout << "You feel the wind of a door close" << endl;
}