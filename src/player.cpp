#include "player.h"
#include <iostream>

using namespace std;

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
        break;
    }
    if(nextx > map.WIDTH || nextx < 0 || nexty > map.HEIGHT || nexty < 0) {
      return false;
    }
    MapCell* cell = map.getCell(nextx, nexty);
    map.getCell(currx, curry)->vacate();
    if(cell->hasCE()) {
        cout << "You run into a CE, trapping you in a conversation about assembly";
        isDead = true;
        return false;
    }
    if(cell->hasEntity()) {
        //cell.entity->do();
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
                cleanCE(currx, map.WIDTH, true);
                break;
            case 'w':
                cleanCE(currx, 0, true);
                break;
            case 's':
                cleanCE(curry, map.HEIGHT, false);
                break;
            case 'n':
                cleanCE(curry, 0, false);
                break;
            default:
                break;
        }
    } else {
        return false;
    }
}

void Player::cleanCE(int val, int max, bool isX) {
    int dir = max > val ? 1 : -1; //sets direction of the deodorant 
    val+=dir;
    while(val != max) { 
        MapCell* cell = isX ? map.getCell(val, curry) : map.getCell(currx, val);
        if(cell->hasCE()) {
            //remove CE
            cout << "You hit the CE with deodorant!";
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

