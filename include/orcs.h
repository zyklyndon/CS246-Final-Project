#ifndef _orcs_
#define _orcs_
#include "enemy.h"
#include <string>
class orcs: public enemy{
    
public:
    orcs(int row, int col, Floor *f);
    int getGold();
    void attack(goblin &g);
    enemy *createEnemy(int row, int col, Floor *f);
    void beAttackedBy(character &c);
    std::string getSType();
};
#endif

