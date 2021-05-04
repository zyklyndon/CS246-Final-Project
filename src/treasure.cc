#include "treasure.h"
treasure::treasure(int row, int col, int value):row{row},col{col},value{value},pickable{true},picked{false} {}
int treasure::getRow(){
    return row;
}

int treasure::getCol(){
    return col;
}

bool treasure::getPickable(){
    return pickable;
}

int treasure::getValue(){
return value;
}
bool treasure::getStatus(){
    return picked;
}
void treasure::setStatus(){
    picked = true;
}

void treasure::picky(){
pickable=true;
}  

