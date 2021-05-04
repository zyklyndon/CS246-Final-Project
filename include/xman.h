#ifndef XMAN_H
#define XMAN_H
/*#include "character.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "enemy.h"*/
#include "character.h"
class human;
class dwarf;
class elf;
class orcs;
class merchant;
class dragon;
class halfling;
class enemy;

class xman: public character{
    public:
        void attack(dwarf &w);
    void attack(human &h);
    void attack(elf &e);
    void attack(orcs &o);    
    void attack(merchant &m);
    void attack(dragon &d);
    void attack(halfling &l);
    void beAttackedBy(enemy &e) override;
    xman(int row, int col);
    ~xman();
};
#endif
