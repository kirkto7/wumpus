#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "entity.h"

class Classroom : public Entity {
public:
    Classroom();
private:
    char token;
};

#endif // CLASSROOM_H