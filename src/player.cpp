#include "player.h"

using namespace std;

Player::Player(Map *map, int startx, int starty) {
    this->map = map;
    this->currx = startx;
    this->curry = starty;
    this->ammo = 5;
    this->isDead = false;
    this->map->getCell(startx, starty)->enter();
}

bool Player::move(char direction) {
    int nextx = currx;
    int nexty = curry;
    switch(tolower(direction)) {
      case 'e':
        nextx += 1;
        break;
      case 'w':
        nextx -= 1;
        break;
      case 's':
        nexty += 1;
        break;
      case 'n':
        nexty -= 1;
        break;
      default:
        cout << "Sorry, that wasn't a valid direction." << endl;
        break;
    }
    if(nextx >= map->getWIDTH() || nextx < 0 || nexty >= map->getHEIGHT() || nexty < 0) {
      return false;
    }
    MapCell* cell = map->getCell(nextx, nexty);
    map->getCell(currx, curry)->vacate();
    if(cell->hasEntity()) {
        cell->getEntity()->act(this);
        return false;
    }
    cell->enter();
    currx = nextx;
    curry = nexty;
}


bool Player::shoot(char direction) {
    if(ammo > 0) {
        ammo -= 1;
        switch(tolower(direction)) {
            case 'e':
                cleanCE(currx, map->getWIDTH(), true);
                break;
            case 'w':
                cleanCE(currx, -1, true);
                break;
            case 's':
                cleanCE(curry, map->getHEIGHT(), false);
                break;
            case 'n':
                cleanCE(curry, -1, false);
                break;
            default:
                break;
        }
        cout << "You have " << ammo << " deodorants left." << endl;
    } else {
        cout << "Sorry, you have no more deodorant left" << endl;
        return false;
    }
}

void Player::cleanCE(int val, int max, bool isX) {
    int dir = max > val ? 1 : -1; //sets direction of the deodorant 
    val+=dir;
    while(val != max) { 
        MapCell* cell = isX ? map->getCell(val, curry) : map->getCell(currx, val);
        if(cell->hasEntity() && typeid(*cell->getEntity()) == typeid(CEStudent)) {
            cell->removeEntity();
            cout << "You hit the CE with deodorant!" << endl;
            break;
        }
        val += dir;
    }
}

void Player::place(int x, int y) {
    currx = x;
    curry = y;
    move('x');
}

void Player::kill() {
    this->isDead = true;
}

