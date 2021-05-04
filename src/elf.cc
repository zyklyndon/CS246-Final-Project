#include "elf.h"
#include "character.h"
#include <math.h>
#include "floor.h"
#include "normal.h"
#include "elf.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
using namespace std;

elf::elf(int row, int col, Floor *f):enemy{140,30,10,row,col,f,Type::Elf} {}


string elf::getSType(){
return "Elf";
}

int elf::getGold(){
    return 2;
}



enemy*elf::createEnemy(int row, int col, Floor *f){
    enemy* e = new elf{row,col,f};
    return e;
}

void elf::beAttackedBy(character &c){
    c.attack(*this);
    if(hp<=0){
        f->notified(*this,c);
        live=false;
    }
}

void elf::attack(troll &t){
    int miss = rand() % 10 + 1;
    int damage=ceil((100/(100+t.getDef()))*atk);
    if(miss>5){
        t.setHp(-1*damage);
        t.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        t.addAction(" "+getSType()+" attacked you but missed.");
    }
    miss = rand() % 10 + 1;
    if(miss>5){
        t.setHp(-1*damage);
        t.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        t.addAction(" "+getSType()+" attacked you but missed.");
    }
}

void elf::attack(vampire &v){
    int miss = rand() % 10 + 1;      
    int damage=ceil((100/(100+v.getDef()))*atk);
    if(miss>5){
        v.setHp(-1*damage);       
       v.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        v.addAction(" "+getSType()+" attacked you but missed.");
    }
    miss = rand() % 10 + 1;
    if(miss>5){
   
        v.setHp(-1*damage);
        v.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        v.addAction(" "+getSType()+" attacked you but missed.");
    }

}

void elf::attack(goblin &g){
    int miss = rand() % 10 + 1;       
    int damage=ceil((100/(100+g.getDef()))*atk);
    if(miss>5){
        g.setHp(-1*damage);        
       g.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        g.addAction(" "+getSType()+" attacked you but missed.");
    }
    miss = rand() % 10 + 1;
    if(miss>5){
        g.setHp(-1*damage);
        g.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        g.addAction(" "+getSType()+" attacked you but missed.");
    }
}

void elf::attack(normal &n){
    int miss = rand() % 10 + 1;
    int damage=ceil((100/(100+n.getDef()))*atk);
    if(miss>5){
        n.setHp(-1*damage);        
        n.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        n.addAction(" "+getSType()+" attacked you but missed.");
    }
    miss = rand() % 10 + 1;
    if(miss>5){
        damage=ceil((100/(100+n.getDef()))*atk);
        n.setHp(-1*damage);
        n.addAction(" "+getSType()+" deals "+to_string(damage)+" damage"+" to you.");
    }else{
        n.addAction(" "+getSType()+" attacked you but missed.");
    }

}

