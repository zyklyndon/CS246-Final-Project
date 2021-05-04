#ifndef DROW_H
#define DROW_H
#include "character.h"
//#include "elf.h"
class elf;
class drow: public character{
    public:
        void attack(elf &e);
/*    void attack(human &h) override;
    void attack(dwarf &w) override;
    void attack(orcs &o) override;    
    void attack(merchant &m) override;
    void attack(dragon &d) override;
    void attack(halfling &l) override;*/
    void beAttackedBy(enemy &e) override;
    drow(int row, int col);
    ~drow();
};
#endif
