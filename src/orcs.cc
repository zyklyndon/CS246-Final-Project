#include "orcs.h"
#include <math.h>
#include "character.h"
#include "floor.h"
#include "goblin.h"
#include <iostream>
using namespace std;

orcs::orcs(int row, int col, Floor *f):enemy{180,30,25,row,col,f,Type::Orcs} {}

int orcs::getGold(){
    return 2;
}


void orcs::attack(goblin &g){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil(1.5*(100/(100+g.getDef()))*atk);
        g.setHp(-1*damage);
       }else{
        g.addAction(" Orcs attacked you but missed.");
       }
}


enemy*orcs::createEnemy(int row, int col, Floor *f){
    enemy* o = new orcs{row,col,f};
    return o;
}

string orcs::getSType(){
return "Orcs";
}

void orcs::beAttackedBy(character &c){
    cout<<hp<<endl;
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
    }
}

