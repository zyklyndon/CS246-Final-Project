#include "enemy.h"
#include "character.h"
#include <cstdlib>
#include "normal.h"
#include "vampire.h"
#include "drow.h"
#include "goblin.h"
#include "xman.h"
#include "troll.h"
#include <math.h>
#include "floor.h"
#include "superman.h"
#include <iostream>
using namespace std;

enemy::enemy(int hp, double atk, double def, int row, int col, Floor *f, Type tp,int h_row,int h_col):hp{hp}, atk{atk}, def{def},
col{col}, row{row}, f{f}, tp{tp} ,live{true},h_row{h_row},h_col{h_col} {}

int enemy::getHRow(){
return h_row;
}

int enemy::getHCol(){
return h_col;
}

int enemy::getRow(){
    return row;
}

int enemy::getCol(){
    return col;
}

int enemy::getHp(){
    return hp;
}

double enemy::getAtk(){
    return atk;
}


double enemy::getDef(){
    return def;
}

Type enemy::getType(){
    return tp;
}

void enemy::setHp(int value){
    hp=hp+value;
}


bool enemy::isDead(){
return !live;
}

void enemy::dead(){
live=false;
}
void enemy::attack(superman &su){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+su.getDef()))*atk);
        su.setHp(-1*damage);
        su.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        su.addAction(" "+getSType()+" attacked you but missed.");
    }
}

void enemy::attack(troll &t){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+t.getDef()))*atk);
        t.setHp(-1*damage);
        t.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        t.addAction(" "+getSType()+" attacked you but missed.");
    }
}
void enemy::attack(xman &x){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+x.getDef()))*atk);
        x.setHp(-1*damage);
        x.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        x.addAction(" "+getSType()+" attacked you but missed.");
    }
}
void enemy::attack(drow &d){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+d.getDef()))*atk);
        d.setHp(-1*damage);        
        d.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        d.addAction(" "+getSType()+" attacked you but missed.");
    }

}

void enemy::attack(vampire &v){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+v.getDef()))*atk);
        v.setHp(-1*damage);       
       v.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        v.addAction(" "+getSType()+" attacked you but missed.");
    }

}

bool enemy::inAttackRange(character &c){
    int r=c.getRow();
    int colc=c.getCol();
    if((r-row)>1||(r-row)<-1||(colc-col)>1||(colc-col)<-1){
        return false;
    }
    return true;
}

void enemy::attack(goblin &g){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+g.getDef()))*atk);
        g.setHp(-1*damage);        
       g.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        g.addAction(" "+getSType()+" attacked you but missed.");
    }
}

void enemy::attack(normal &n){
    int miss = rand() % 10 + 1;
    if(miss>5){
        int damage=ceil((100/(100+n.getDef()))*atk);
        n.setHp(-1*damage);        
        n.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        n.addAction(" "+getSType()+" attacked you but missed.");
    }

}


void enemy::autoAttack(character &c){
    if(!live){
        return;
    }
    if(inAttackRange(c)&&!(tp==Type::Merchant&&c.isHostile())){
        c.beAttackedBy(*this);
        return;
    }
}

void enemy::move(character &c){
    if(!live){
        return;
    }
    //cout<<"move"<<"\n";
    if(inAttackRange(c)&&!(tp==Type::Merchant&&c.isHostile())){
        return;
    }
    while(true){
    int dir = rand() % 8 + 1;
    if(dir==1){ //north
        if(f->isValidEnemyMove(row,col,"no",tp)){
            row=row-1;
            col=col;
            return;
        }
        continue;
    }else if(dir==2){ //south
        if(f->isValidEnemyMove(row,col,"so",tp)){
            row=row+1;
            col=col;
            return;
        }
        continue;
    }else if(dir==3){ //west
        if(f->isValidEnemyMove(row,col,"we",tp)){
            row=row;
            col=col-1;
            return;
        }
        continue;
    }else if(dir==4){ //east
        if(f->isValidEnemyMove(row,col,"ea",tp)){
            row=row;
            col=col+1;
            return;
        }
        continue;
    }else if(dir==5){ //south_west
        if(f->isValidEnemyMove(row,col,"sw",tp)){
            row=row+1;
            col=col-1;
            return;
        }
        continue;
    }else if(dir==6){ //south_east
        if(f->isValidEnemyMove(row,col,"se",tp)){
            row=row+1;
            col=col+1;
            return;
        }
        continue;
    }else if(dir==7){ //north_west
        if(f->isValidEnemyMove(row,col,"nw",tp)){
            row=row-1;
            col=col-1;
            return;
        }
        continue;
    }else{ //north_east
        if(f->isValidEnemyMove(row,col,"ne",tp)){
            row=row-1;
            col=col+1;
            return;
        }
        continue;
    }
}
}


