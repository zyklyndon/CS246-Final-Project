#include "halfling.h"
#include <math.h>
#include "floor.h"
#include "character.h"
using namespace std;

halfling::halfling(int row, int col, Floor *f):enemy{140,20,20,row,col,f,Type::Halfling} {}


int halfling::getGold(){
    return 8;
}

enemy*halfling::createEnemy(int row, int col, Floor *f){
    enemy* half = new halfling{row,col,f};
    return half;
}

string halfling::getSType(){
return "Halfling";
}

void halfling::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
    f->notified(*this, c);
    }
}

