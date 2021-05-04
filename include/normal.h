#ifndef NORMAL_H
#define NORMAL_H
#include "character.h"
class normal: public character{
/*    void attack(human &h) override;
    void attack(dwarf &w) override;
    void attack(elf &e) override;
    void attack(orcs &o) override;    
    void attack(merchant &m) override;
    void attack(dragon &d) override;
    void attack(halfling &l) override;
    void beAttackedBy(enemy &e) override;*/
    public:
        normal(int row, int col);
    void beAttackedBy(enemy &e) override;
    ~normal();
};
#endif
