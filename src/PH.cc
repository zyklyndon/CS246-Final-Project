#include "PH.h"
#include <string>
#include <math.h>
using namespace std;

PH::PH(character *pc, int row, int col,string type):
    potion{pc, row ,col,type} {}

void PH::effect(){
    int HP = theChar->getHp();
    theChar->setPH();
    string type = theChar->getType();
    if(type == "Drow"){
        theChar->setHp(max(1-HP,-15));
    }else{
        theChar->setHp(max(1-HP,-10));
    }      
}
