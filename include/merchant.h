#ifndef _merchant_
#define _merchant_
#include "enemy.h"
#include <string>
class merchant: public enemy{

public:
    merchant(int row, int col, Floor *f);
    int getGold();
    enemy *createEnemy(int row, int col, Floor *f);
    void auto_attack(character &c);
    void beAttackedBy(character &c);
    std::string getSType();
};
#endif
