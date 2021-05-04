#include "RH.h"
#include <string>
using namespace std;

RH::RH(character *pc, int row, int col,string type):
    potion{pc, row, col,type} {}

void RH::effect(){
    int HP = theChar->getHp();
    int maxHp = theChar->getMaxHp();
    theChar->setRH();
    string type = theChar->getType();
    if(type == "Drow"){
        theChar->setHp(15);
    }else{
        theChar->setHp(10);
     }      
}
