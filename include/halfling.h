#ifndef _halfling_
#define _halfling_
#include "enemy.h"
#include <string>
class halfling: public enemy{

public:
    halfling(int row, int col, Floor *f);
    int getGold();
    enemy *createEnemy(int row, int col, Floor *f);
    void beAttackedBy(character &c);
    std::string getSType();
};
#endif

