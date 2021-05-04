#include "WA.h"
#include <string>
using namespace std;

WA::WA(character *pc, int row, int col, string type):
    potion{pc, row, col, type} {}

void WA::effect(){
    string type = theChar->getType();
    theChar->setWA();
    if(type == "Drow"){
        theChar->setAtk(-7.5);
    }else{
        theChar->setAtk(-5);
    }      
}
