#include "BD.h"
#include <string>
using namespace std;

BD::BD(character *pc, int row, int col,string type):
    potion{pc,row,col,type} {}

void BD::effect(){
    string type = theChar->getType();
    theChar->setBD();
    if(type == "Drow"){
        theChar->setDef(7.5);
    }else{
        theChar->setDef(5);
    }      
}
