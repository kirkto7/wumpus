#include "player.h"


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
}

int Player::shoot(char direction) {
    ammo -= 1;
}