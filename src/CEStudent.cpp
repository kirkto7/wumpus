#include "CEStudent.h"

using namespace std;

CEStudent::CEStudent() {
    token = 'C';
    health = 5;
    damage = 5;
}

char CEStudent::display() {
    return token;
}

int CEStudent::getDamage() {
    return damage;
}

void CEStudent::takeDamage(int dmg) {
    health = health - dmg;
}

int CEStudent::getHealth() {
    return health;
}