#ifndef HODAG_H
#define HODAG_H

class CEStudent {
public:
    CEStudent();
    char display();
    int getDamage();
    void takeDamage(int dmg);
    int getHealth();
private:
    char token;
    int health;
    int damage;
};

#endif // HODAG_H