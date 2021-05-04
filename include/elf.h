#ifndef _elf_
#define _elf_
#include "enemy.h"
#include <string>

class elf: public enemy{
public:
    elf(int row, int col, Floor *f);
    int getGold();
    enemy *createEnemy(int row, int col, Floor *f);
    void beAttackedBy(character &c);
    std::string getSType();
    void attack(troll &t);
    void attack(vampire &v);
    void attack(normal &n);
    void attack(goblin &g);
};
#endif

