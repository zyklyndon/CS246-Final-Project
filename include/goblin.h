#ifndef GOBLIN_H
#define GOBLIN_H
#include "character.h"
class goblin: public character{
/*    void attack(human &h) override;
    void attack(dwarf &w) override;
    void attack(elf &e) override;
    void attack(orcs &o) override;    
    void attack(merchant &m) override;
    void attack(dragon &d) override;
    void attack(halfling &l) override;*/
    public:
        goblin(int row, int col);
        void beAttackedBy(enemy &e) override; 
        ~goblin();
};
#endif
