#include "human.h"
#include <math.h>
#include "character.h"
#include "floor.h"
#include <iostream>
using namespace std;

human::human(int row, int col, Floor *f):enemy{140,20,20,row,col,f,Type::Human} {}


int human::getGold(){
    return 4;
}

enemy*human::createEnemy(int row, int col, Floor *f){
    enemy* h = new human{row,col,f};
    return h;
}

string human::getSType(){
return "Human";
}

void human::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
        live=false;
    }
}
