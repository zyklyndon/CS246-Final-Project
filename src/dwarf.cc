#include "dwarf.h"
#include <math.h>
#include "character.h"
#include "floor.h"
using namespace std;

dwarf::dwarf(int row, int col, Floor *f):enemy{100,20,30,row,col,f,Type::Dwarf} {}

int dwarf::getGold(){
    return 2;
}

string dwarf::getSType(){
return "Dwarf";
}

enemy*dwarf::createEnemy(int row, int col, Floor *f){
    enemy* d = new dwarf{row,col,f};
    return d;
}

void dwarf::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
    }
}

