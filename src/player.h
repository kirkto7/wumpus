#include "map.h"
#include "cell.h"
#include <string>

class Player {

    public:
        Player(Map *map, int startx, int starty) : map(*map), currx(startx), curry(starty), ammo(5), isDead(false){}

        bool move(char direction);
        bool shoot(char direction);
        void place(int x, int y);

    private:
        void cleanCE(int val, int max, bool isX);
        Map map;
        int currx;
        int curry;
        int ammo;
        bool isDead;
};