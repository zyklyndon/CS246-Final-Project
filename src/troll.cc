#include "troll.h"
#include <math.h>
#include "elf.h"
#include "orcs.h"
#include "human.h"
#include "dwarf.h"
#include "merchant.h"
#include "dragon.h"
#include "enemy.h"
#include "halfling.h"
#include <cstdlib>
using namespace std;

troll::~troll(){}

troll::troll(int row, int col):
    character{120,25,15,0,0,0,true,120,"Troll",row,col}{}

void troll::beAttackedBy(enemy &e){
    e.attack(*this);
}

void troll::attack(human &h){
    int h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+h_def));
    h.setHp(-damage);
    setHp(5);
    //beAttackedBy(h);
}

void troll::attack(dwarf &w){
    int w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+w_def));
    w.setHp(-damage);
    setHp(5);
    //beAttackedBy(w);
}

void troll::attack(orcs &o){
    int o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+o_def));
    o.setHp(-damage);
    setHp(5);
   // beAttackedBy(o);
}

void troll::attack(merchant &m){
    int m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+m_def));
    m.setHp(-damage);
    setStatus();
    setHp(5);
   // beAttackedBy(m);
}

void troll::attack(elf &e){
    int e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+e_def));
    e.setHp(-damage);
    setHp(5);
  //  beAttackedBy(e);
   // beAttackedBy(e);
}

void troll::attack(dragon &d){
    int d_def = d.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+d_def));
    d.setHp(-damage);
    setHp(5);
   // beAttackedBy(d);
}

void troll::attack(halfling &l){
    int miss = rand() % 10 +1;
    if(5<miss){
        int l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil((atk*100)/(100+l_def));
        l.setHp(-damage);
        setHp(5);
    }
   // beAttackedBy(l);
}
