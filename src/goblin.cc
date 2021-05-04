#include "goblin.h"
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

goblin::~goblin(){}

goblin::goblin(int row, int col):
    character{110,15,20,0,0,0,true,110,"Goblin",row,col} {}

void goblin::beAttackedBy(enemy &e){
    e.attack(*this);
}

/*void goblin::attack(human &h){
    int h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+h_def)));
    h.setHp(-damage);
    beAttackedBy(h);
}

void goblin::attack(dwarf &w){
    int w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+w_def)));
    w.setHp(-damage);
    beAttackedBy(w);
}

void goblin::attack(orcs &o){
    int o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+o_def)));
    o.setHp(-damage);
    beAttackedBy(o);
}

void goblin::attack(merchant &m){
    int m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+m_def)));
    m.setHp(-damage);
    setStatus();
    beAttackedBy(m);
}

void goblin::attack(elf &e){
    int e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+e_def)));
    e.setHp(-damage);
    beAttackedBy(e);
    beAttackedBy(e);
}

void goblin::attack(dragon &d){
    int d_def = d.getDef();
    double atk = getAtk();
    int damage = ceil(atk*(100/(100+d_def)));
    d.setHp(-damage);
    beAttackedBy(d);
}

void goblin::attack(halfling &l){
    int miss = rand() % 10 +1;
    if(miss > 5){
        int l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil(atk*(100/(100+l_def)));
        l.setHp(-damage);
    }
    beAttackedBy(l);
}*/
