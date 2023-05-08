#include "entity.h"
#include <iostream>

using namespace std;

void Classroom::printWarning() {
    cout << "You hear your professor lecturing." << endl;
}

void Classroom::act(Player* player) {
    player->kill();
    cout << "You accidentally walk back into class and now you're stuck listening to lecture." << endl;
}

char Classroom::display() {
    return 'R';
}