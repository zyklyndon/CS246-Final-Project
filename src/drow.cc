#include "drow.h"
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

drow::~drow(){}

drow::drow(int row, int col):
    character{150,25,15,0,0,0,true,150,"Drow",row,col}{}


void drow::beAttackedBy(enemy &e){
    e.attack(*this);
}

/*void drow::attack(human &h){
    int h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+h_def)));
    h.setHp(-damage);
    beAttackedBy(h);
}

void drow::attack(dwarf &w){
    int w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+w_def)));
    w.setHp(-damage);
    beAttackedBy(w);
}

void drow::attack(orcs &o){
    int o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+o_def)));
    o.setHp(-damage);
    beAttackedBy(o);
}

void drow::attack(merchant &m){
    int m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+m_def)));
    m.setHp(-damage);
    setStatus();
    beAttackedBy(m);
}*/

void drow::attack(elf &e){
    int e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+e_def));
    e.setHp(-damage);
  //  beAttackedBy(e);
}

/*void drow::attack(dragon &d){
    int d_def = d.getDef();
    double atk = getAtk();
    int  damage = ceil(atk*(100/(100+d_def)));
    d.setHp(-damage);
    beAttackedBy(d);
}

void drow::attack(halfling &l){
    int miss = rand() %10 +1;      
    if(miss>5){
        int l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil(atk*(100/(100+l_def)));
        l.setHp(-damage);
    }
    beAttackedBy(l);
}*/
