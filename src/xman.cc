#include "xman.h"
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
#include <stdexcept>
using namespace std;

xman::~xman(){}

xman::xman(int row, int col):
    character{250,60,40,0,0,0,true,250,"Xman",row,col} {}

void xman::beAttackedBy(enemy &e){
    e.attack(*this);
}

void xman::attack(human &h){
    int h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+h_def));
    int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }
    h.setHp(-damage);
  //  beAttackedBy(h);
}

void xman::attack(dwarf &w){
    int w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+w_def));
    int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }

    w.setHp(-damage);
   // beAttackedBy(w);
}

void xman::attack(orcs &o){
    int o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+o_def));
    int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }

    o.setHp(-damage);
   // beAttackedBy(o);
}

void xman::attack(merchant &m){
    int m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+m_def));
    int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }

    m.setHp(-damage);
    setStatus();
   // beAttackedBy(m);
}

void xman::attack(elf &e){
    int e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+e_def));
    int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }

    e.setHp(-damage);
   // beAttackedBy(e);
   // beAttackedBy(e);
}

void xman::attack(dragon &d){
    int d_def = d.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+d_def));
    int critical=rand()%10+1;
    if(critical<=4){
        damage=2*damage;
    }

    d.setHp(-damage);
   // beAttackedBy(d);
}

void xman::attack(halfling &l){
    int miss = rand() % 10 + 1;
    if(miss > 5){
        int l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil((atk*100)/(100+l_def));
        int critical=rand()%10;
    if(critical<=4){
        damage=2*damage;
    }

        l.setHp(-damage);
    }else{
    setAction("You missed.");
    throw invalid_argument("missed");
    }
    //beAttackedBy(l);
}
