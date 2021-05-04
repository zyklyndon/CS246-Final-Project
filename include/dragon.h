#ifndef _dragon_
#define _dragon_
#include "enemy.h"
#include <string>
class Floor;
class dragon: public enemy{
public:
    void autoAttack(character &c); 
    int getHRow();
    int getHCol();
    dragon(int row, int col, Floor *f,int h_r, int h_c);
    int getGold();
    //void auto_attack(character &c);
    void move(character &c);
    enemy *createEnemy(int row, int col, Floor *f,int h_r, int h_c);
    int get_h_r();
    int get_h_c();
    void beAttackedBy(character &c);
    enemy *createEnemy(int row, int col, Floor *f);
    bool inAttackRange(character &c);
    std::string getSType();
};
#endif

