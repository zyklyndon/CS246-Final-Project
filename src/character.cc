#include "character.h"
#include "characterImpl.h"
#include <string>
#include <math.h>
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "enemy.h"
#include <stdexcept>
using namespace std;

character::character(int row, int col):hp{1},atk{1}, def{1},gold{1},p_atk{0},p_def{0},maxHp{1}, type{" "},if_hostile{true},row{row},col{col}/*,info{" "}, ba{0}, bd{0}, wa{0}, wd{0}, ph{0}, rh{0}*/ {}

character::character(int hp, double atk, double def, int gold, double p_atk, double p_def, bool if_hostile, int maxHp, string type, int row, int col/*, string info, int ba, int bd, int wa, int wd, int ph, int rh*/):hp{hp},atk{atk},def{def},gold{gold},p_atk{p_atk},p_def{p_def},if_hostile{if_hostile}, maxHp{maxHp}, type{type},row{row},col{col}/*,info{" "}, ba{ba}, bd{bd}, wa{wa}, wd{wd}, ph{ph}, rh{rh}*/ {}

void character::setAction(string info){
    this->info = info;
}

bool character::isHostile(){
return if_hostile;
}

string character::getAction(){
    return info;
}

void character::addAction(string newInfo){
    info += newInfo;
}
int character::getHp(){
    return hp;
}
void character::setHp(int value){
    hp = min(getMaxHp(),hp + value);
}

double character::getAtk(){
    return atk + p_atk;
}
void character::setAtk(double value){
    p_atk += value;
}
void character::clearAtk(){
    p_atk = 0;
}

double character::getDef(){
    return def + p_def;
}
void character::setDef(double value){
    p_def += value;
}
void character::clearDef(){
    p_def = 0;
}

int character::getGold(){
    return gold;
}

int character::addGold(int value){
gold=gold+value;
}
void character::pickGold(int value){
    gold += value;
}

int character::getMaxHp(){
    return maxHp;
}   

string character::getType(){
    return type;
}

int character::getRow(){
    return row;
}
void character::setRow(int n_row){
    row = n_row;
}

int character::getCol(){
    return col;
}
void character::setCol(int n_col){
    col = n_col;
}

void character::setStatus(){
    if_hostile = false;
}

bool character::getStatus(){
    return if_hostile;
}

void character::move(string direction){
    if(direction == "no"){
        col -= 1;     
    }else if(direction == "so"){
        col += 1;
    }else if(direction == "ea"){
        row += 1;
    }else if(direction == "we"){
        row -= 1;
    }else if(direction == "ne"){
        row -= 1;
        col += 1;
    }else if(direction == "nw"){
        row -= 1;
        col -= 1;
    }else if(direction == "se"){
        row += 1;
        col += 1;
    }else if(direction == "sw"){
        row -= 1;
        col += 1;
    }
    if(getType() == "Troll"){
        setHp(5);
    }
}

/*void character::beAttackedBy(enemy &e){
    e.attack(*this);
}*/

void character::attack(human &h){
    double h_def = h.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+h_def));
    h.setHp(-damage);
   // beAttackedBy(h);
}
void character::attack(dwarf &w){
    double w_def = w.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+w_def));
    w.setHp(-damage);       
   // beAttackedBy(w);
}

void character::attack(orcs &o){
    double o_def = o.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+o_def));
    o.setHp(-damage);
  //  beAttackedBy(o);
}

void character::attack(merchant &m){
    double m_def = m.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+m_def));
    m.setHp(-damage);
    setStatus();       
   // beAttackedBy(m);
}

void character::attack(elf &e){
    double e_def = e.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+e_def));
    e.setHp(-damage);     
   // beAttackedBy(e);
   // beAttackedBy(e);
}

void character::attack(dragon &d){
    double d_def = d.getDef();
    double atk = getAtk();
    int damage = ceil((atk*100)/(100+d_def));
    d.setHp(-damage);       
    //beAttackedBy(d);
}

void character::attack(halfling &l){
    int miss = rand() % 10 +1;
    if(5<miss){
        double l_def = l.getDef();
        double atk = getAtk();
        int damage = ceil((atk*100)/(100+l_def));
        l.setHp(-damage);
    }else{
        setAction("You missed.");
        throw invalid_argument("missed");
    }
   // beAttackedBy(l);
}

int character::getBA(){
    return ba;
}
void character::setBA(){
    ba = 1;
}
        
int character::getBD(){
    return bd;
}
void character::setBD(){
    bd = 1;
}

int character::getWA(){
    return wa;
}
void character::setWA(){
    wa = 1;
}
        
int character::getPH(){
    return ph;
}
void character::setPH(){
    ph = 1;
}

int character::getWD(){
    return wd;
}
void character::setWD(){
    wd = 1;
}

int character::getRH(){
    return rh;
}
void character::setRH(){
    rh = 1;
}

character::~character(){}
