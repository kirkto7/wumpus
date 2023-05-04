#include "entity.h"
#include <iostream>

using namespace std;

CEStudent::CEStudent() {
    token = 'C';
}

char CEStudent::display() {
    return token;
}

void CEStudent::printWarning() {
    cout << "You get a pungent whiff of a computer engineer" << endl;
}

void CEStudent::act(Player* player) {
    player->kill();
    cout << "You run into a CE, trapping you in a conversation about assembly." << endl;
}
