#ifndef _enemy_
#define _enemy_
#include <cstdlib>
#include <string>
#include "cell.h"
class character;
class troll;
class drow;
class vampire;
class goblin;
class normal;
class Floor;
class xman;
class superman;
class enemy{
protected:
    int hp;
    double atk;
    double def;
    int col;
    int row;
    Floor *f;
    Type tp;
    bool live;
    int h_row;
    int h_col; 
public:
    virtual void autoAttack(character &c);
    int getHRow();
    int getHCol();
    enemy(int hp, double atk, double def, int col, int row, Floor *f, Type tp, int h_row=0, int h_col=0);
    int getHp();
    double getAtk();
    virtual int getGold()=0;
    double getDef();
    int getRow();
    int getCol();
    Type getType();
    virtual bool inAttackRange(character &c);
    virtual void beAttackedBy(character &c)=0;
    virtual void attack(troll &t);
    virtual void attack(drow &d);
    virtual void attack(vampire &v);
    virtual void attack(goblin &g);
    virtual void attack(normal &n);
    virtual void attack(superman &su);
    virtual void attack(xman &x);
    virtual void move(character &c);
    void setHp(int value);
    virtual enemy *createEnemy(int row, int col, Floor *f)=0;
    virtual std::string getSType()=0;
    void dead();
    bool isDead();
    
};
#endif
