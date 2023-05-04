#include <iostream>
#include "map.h"
#include "player.h"

using namespace std;

void move(Player* player) {
    char dir;
    cout << "Move a direction: (N)orth, (S)outh, (E)ast, (W)est: ";
    cin >> dir;
    player->move(dir);
}

void shoot(Player* player) {
    char dir;
    cout << "What direction to shoot: (N)orth, (S)outh, (E)ast, (W)est: ";
    cin >> dir;
    player->shoot(dir);
}

int main() {
    Map* m = new Map();
    int initx = 1;
    int inity = 2;
    m->load(initx,inity);
    Player* player = new Player(m, initx, inity);
    bool gameWon = false;
    int cleanedCEs = 0;
    while(!gameWon && player->isAlive()) {
        m->write();
        char cmd;
        cout << "Do Something: (M)ove, (S)hoot, (Q)uit: ";     
        cin >> cmd;  
        switch(tolower(cmd)) {
            case 'm':
                move(player);
                break;
            case 's':
                shoot(player);
                break;
            case 'q':
                return 0;
                break;
            default:
                cout << "Sorry, that isn't a valid command." << endl;
                break;
        }
    }
    if(gameWon) {
        cout << "Congrats, you escaped the science building!" << endl;
    } else {
        cout << "GAME OVER" << endl;
    }
}
