#include "entity.h"
#include <iostream>

using namespace std;


char CEStudent::display() {
    return 'C';
}

void CEStudent::printWarning() {
    cout << "You get a pungent whiff of a computer engineer" << endl;
}

void CEStudent::act(Player* player) {
    player->kill();
    cout << "You run into a CE, trapping you in a conversation about assembly." << endl;
}
