#ifndef PLAYER_H
#define PLAYER_H

#include <typeinfo>

#include "map.h"
#include "cell.h"
#include <string>
#include <iostream>
#include <typeinfo>
class Map;
class MapCell;
class Entity;

class Player {

    public:
        Player(Map *map, int startx, int starty);
        bool move(char direction);
        bool shoot(char direction);
        void place(int x, int y);
        bool isAlive(){return !isDead;}
        int getAmmo(){return ammo;}
        void kill();
        int getCurrx() {return currx;}
        int getCurry() {return curry;}

    private:
        bool cleanCE(int val, int max, bool isX);
        void findWarnings();
        Map* map;
        int currx;
        int curry;
        int ammo;
        bool isDead;
};

#endif //PLAYER_H