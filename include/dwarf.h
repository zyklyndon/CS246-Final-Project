#ifndef _dwarf_
#define _dwarf_
#include "enemy.h"
#include "floor.h"
#include <string>
class dwarf: public enemy{

public:
    dwarf(int row, int col, Floor *f);
    int getGold();
    enemy *createEnemy(int row, int col, Floor *f);
    void beAttackedBy(character &c);
    std::string getSType();
};
#endif

