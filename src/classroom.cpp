#include "entity.h"
#include <iostream>

using namespace std;

Classroom::Classroom() {
    token = 'R';
}

void Classroom::printWarning() {
    cout << "You hear your prefessor lecturing." << endl;
}

void Classroom::act(Player* player) {
    player->kill();
    cout << "You accidentally walk back into class and now you're stuck listening to lecture." << endl;
}