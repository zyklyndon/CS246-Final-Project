#include "dragon.h"
#include <math.h>
#include "floor.h"
#include "character.h"
#include "floor.h"
#include <iostream>
using namespace std;

dragon::dragon(int row,int col, Floor *f,int h_r, int h_c):
    enemy{150,20,20,row,col,f,Type::Dragon,h_r,h_c} {}

int dragon::getGold(){
    return 6;
}

int dragon::getHRow(){
return h_row;
}

int dragon::getHCol(){
return h_col;
}

bool dragon::inAttackRange(character &c){
int r=c.getRow();
int colc=c.getCol();
int rdiff=r-h_row;
int cdiff=colc-h_col;
if(!(rdiff>1||rdiff<-1||cdiff>1||cdiff<-1)){
return true;
}
if(!(row-r>1||row-r<-1||col-colc>1||col-colc<-1)){
return true;
}
return false;
}

void dragon::move(character &c){
    return;
}

void dragon::autoAttack(character &c){
if(dragon::inAttackRange(c)){
c.beAttackedBy(*this);
}

}

void dragon::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
    }
}

enemy*dragon::createEnemy(int row, int col, Floor *f, int h_r, int h_c){
    enemy* d = new dragon{row,col,f, h_r, h_c};
    return d;
}

string dragon::getSType(){
return "Dragon";
}

enemy *dragon::createEnemy(int row, int col, Floor *f){
    return nullptr;
}

