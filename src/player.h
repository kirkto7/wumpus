#include "map.h"
#include <string>

class Player {

    public:
        Player(Map *map, int startx, int starty) : map(*map), currx(startx), curry(starty), ammo(5){}

        bool move(char direction);
        int shoot(char direction);

    private:
        Map* map;
        int currx;
        int curry;
        int ammo;

}