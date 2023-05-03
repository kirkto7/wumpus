#ifndef CESTUDENT_H
#define CESTUDENT_H

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

#endif // CESTUDENT_H