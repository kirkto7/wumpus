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
    if(nextx >= map->getWIDTH() || nextx < 0 || nexty >= map->getHEIGHT()|| nexty < 0) {
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
    findWarnings();
}


bool Player::shoot(char direction) {
    bool hit = false;
    if(ammo > 0) {
        ammo -= 1;
        switch(tolower(direction)) {
            case 'e':
                hit = cleanCE(currx, map->getWIDTH(), true);
                break;
            case 'w':
                hit = cleanCE(currx, -1, true);
                break;
            case 's':
                hit = cleanCE(curry, map->getHEIGHT(), false);
                break;
            case 'n':
                hit = cleanCE(curry, -1, false);
                break;
            default:
                break;
        }
        if(hit) {
            cout << "You hit the CE with deodorant!" << endl;
        } else {
            cout << "You miss!" << endl;
        }
        cout << "You have " << ammo << " deodorants left." << endl;
    } else {
        cout << "Sorry, you have no more deodorant left." << endl;
    }
    return hit;
}

bool Player::cleanCE(int val, int max, bool isX) {
    int dir = max > val ? 1 : -1; //sets direction of the deodorant 
    val+=dir;
    while(val != max) { 
        MapCell* cell = isX ? map->getCell(val, curry) : map->getCell(currx, val);
        if(cell->hasEntity() && typeid(*cell->getEntity()) == typeid(CEStudent)) {
            cell->removeEntity();
            return true;
        }
        val += dir;
    }
    return false;
}

void Player::place(int x, int y) {
    int nextx = x;
    int nexty = y;
    MapCell* cell = map->getCell(nextx, nexty);
    map->getCell(currx, curry)->vacate();
    if(cell->hasEntity()) {
        cell->getEntity()->act(this);
    }
    cell->enter();
    currx = nextx;
    curry = nexty;
    findWarnings();
}

void Player::kill() {
    this->isDead = true;
}

void Player::findWarnings() {
    int x = currx;
    int y = curry;
    for(int i = -1; i <= 1; i++) {
        x = min(max(0, currx + i), map->getWIDTH());
        for(int j = -1; j <= 1; j++) {
            y = min(max(0, curry + j), map->getHEIGHT());
            MapCell* cell = map->getCell(x,y);
            if(cell->hasEntity()) {
                cell->getEntity()->printWarning();
            }
        }
    }
}

