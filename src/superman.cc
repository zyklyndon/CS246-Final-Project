#include "superman.h"
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

superman::~superman(){}

superman::superman(int row, int col):
    character{500,40,60,0,0,0,true,500,"Superman",row,col} {}

void superman::beAttackedBy(enemy &e){
    e.attack(*this);
}

void superman::attack(human &h){
    double atk = getAtk();  
    h.setHp(-atk);
  //  beAttackedBy(h);
}

void superman::attack(dwarf &w){
     double atk = getAtk();
    w.setHp(-atk);
   // beAttackedBy(w);
}

void superman::attack(orcs &o){
     double atk = getAtk();
    o.setHp(-atk);
   // beAttackedBy(o);
}

void superman::attack(merchant &m){
    double atk = getAtk();
    m.setHp(-atk);
    setStatus();
   // beAttackedBy(m);
}

void superman::attack(elf &e){
    double atk = getAtk();
    e.setHp(-atk);
   // beAttackedBy(e);
   // beAttackedBy(e);
}

void superman::attack(dragon &d){
    double atk = getAtk();
    d.setHp(-atk);
   // beAttackedBy(d);
}

void superman::attack(halfling &l){
    int miss = rand() % 10 + 1;
    if(miss > 5){
         double atk = getAtk();

        l.setHp(-atk);
    }else{
    setAction("You missed.");
    throw invalid_argument("missed");
    }
    //beAttackedBy(l);
}
