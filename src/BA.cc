#include "BA.h"
#include <string>
using namespace std;

BA::BA(character *pc, int row, int col,string type):
    potion{pc,row,col,type} {}

void BA::effect(){
    string type = theChar->getType();
    theChar->setBA();
    if(type == "Drow"){
        theChar->setAtk(7.5);
    }else{
        theChar->setAtk(5);
    }      
}

