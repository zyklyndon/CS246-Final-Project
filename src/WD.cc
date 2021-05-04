#include "WD.h"
#include <string>
using namespace std;

WD::WD(character *pc, int row, int col,string type):
    potion{pc,row,col,type} {}

void WD::effect(){
    string type = theChar->getType();
    theChar->setWD();
    if(type == "Drow"){
        theChar->setDef(-7.5);
    }else{
        theChar->setDef(-5);
    }      
}
