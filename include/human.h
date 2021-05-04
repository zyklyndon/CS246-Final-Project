#ifndef _human_
#define _human_
#include "enemy.h"
#include <string>
class human: public enemy{
    
public:
    human(int row, int col, Floor *f);
    int getGold();
    enemy *createEnemy(int row, int col, Floor *f);
    void beAttackedBy(character &c);
    std::string getSType();
};
#endif
