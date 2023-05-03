#ifndef CELL_H
#define CELL_H

class CEStudent;

class MapCell {
    int xLocation, yLocation;
    bool hasPlayer;
    CEStudent *ce;
public:
    MapCell(int x, int y);
    bool occupied();
    char display();
    void enter();
    void vacate();
    bool hasEntity();
    bool hasSomething();
    int getDamage();
    void removeItem();
    bool hasCE();
};

#endif // CELL_H