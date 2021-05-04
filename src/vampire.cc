#include "vampire.h"
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

vampire::~vampire(){}

vampire::vampire(int row, int col):
    character{50,25,25,0,0,0,true,999999999,"Vampire",row,col} {}

void vampire::beAttackedBy(enemy &e){
    e.attack(*this);
}

void vampire::attack(human &h){
    int h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+h_def));
    h.setHp(-damage);
    setHp(5);
 }

void vampire::attack(dwarf &w){
    int w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+w_def));
    w.setHp(-damage);
    setHp(-5);
 }

void vampire::attack(orcs &o){
    int o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+o_def));
    o.setHp(-damage);
    setHp(5);
 }

void vampire::attack(merchant &m){
    int m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+m_def));
    m.setHp(-damage);
    setStatus();
    setHp(5);
  }

void vampire::attack(elf &e){
    int e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+e_def));
    e.setHp(-damage);
    setHp(5);
}

void vampire::attack(dragon &d){
    int d_def = d.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+d_def));
    d.setHp(-damage);
    setHp(5);
   
}

void vampire::attack(halfling &l){
    int miss = rand() % 10 + 1;
    if(miss > 5){
        int l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil((atk*100)/(100+l_def));
        l.setHp(-damage);
        setHp(5);
        }else{
        setAction("You missed.");
        throw invalid_argument("missed");
        }
   
}
