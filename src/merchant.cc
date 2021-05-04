#include "merchant.h"
#include <math.h>
#include "character.h"
#include "floor.h"
using namespace std;

merchant::merchant(int row, int col, Floor *f):enemy{30,70,5,row,col,f,Type::Merchant} {}


int merchant::getGold(){
    return 6;
}


enemy*merchant::createEnemy(int row, int col, Floor *f){
    enemy* m = new merchant{row,col,f};
    return m;
}

void merchant::auto_attack(character &c){
    if(hp<=0){
        f->notified(*this,c);
    }
    if(c.getStatus()){
        return;
    }
    if(inAttackRange(c)){
        c.beAttackedBy(*this);
    }
    return;
}

string merchant::getSType(){
return "Merchant";
}

void merchant::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
    }
}
