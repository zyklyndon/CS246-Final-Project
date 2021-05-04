#include "potion.h"

using namespace std;

potion::potion(character *pc, int row, int col, string type):
character{row,col},
       theChar{pc}, counter{0}, row{row}, col{col}, type{type}, used{false} {}

int potion::getCounter(){
    return counter;
}

void potion::setCounter(){
    counter++;
}

int potion::getRow(){
    return row;
}

int potion::getCol(){
    return col;
}

void potion::beAttackedBy(enemy &e){
    return;
}
string potion::getType(){
    return type;
}
potion::~potion(){}
bool potion::getStatus(){
    return used;
}
void potion::setStatus(){
    used = true;
}
