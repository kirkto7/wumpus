#include "entity.h"
#include <iostream>

using namespace std;


void Stairwell::act(Player* player) {
    int x = rand() % 5;
    int y = rand() % 5;
    player->place(x,y);
    cout << "You traverse the stairwell, putting you in an unexpected part of the building." << endl;
    
}

void Stairwell::printWarning() {
    cout << "You feel the wind of a door close." << endl;
}

char Stairwell::display() {
    return 'S';
}