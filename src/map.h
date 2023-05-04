#ifndef MAP_H
#define MAP_H

class MapCell;

class Map {
    static constexpr int HEIGHT = 6;
    static constexpr int WIDTH = 6;
    MapCell *cells[WIDTH][HEIGHT];
    bool CEAlive;
public:
    Map();
    void load(int playerX, int playerY);
    void write();
    MapCell* getCell(int x, int y);
    bool getCEStatus();
    void changeCEStatus(int x, int y);
    int getWIDTH() {return WIDTH;}
    int getHEIGHT() {return HEIGHT;}
};

#endif // MAP_H