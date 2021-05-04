#ifndef CHARACTER_H
#define CHARACTER_H
/*#include "characterImpl.h"
*/
#include <string>
class human;
class dwarf;
class elf;
class orcs;
class merchant;
class dragon;
class halfling;
class enemy;
struct characterImpl;
class character{
    protected:
    int hp;
    double atk;
    double def;
    int gold;
    double p_atk;
    double p_def;
    const int maxHp;
    const std::string type;
    bool if_hostile;
    int row;
    int col;
    std::string info=" ";
    int ba=0;
    int bd=0;
    int wa=0;
    int wd=0;
    int ph=0;
    int rh=0;  
    public:
        character(int row, int col);
        character(int hp, double atk, double def, int gold, double p_atk,double p_def, bool if_hostile, int maxHp, std::string type, int row, int col/*, std::string info, int ba, int bd, int wa, int wd, int ph, int rh*/);
        int getHp();
        double getAtk();
        double getDef();
        int getGold();
        int getMaxHp();
        int addGold(int value);
        std::string getType();
        int getRow();
        int getCol();
        bool getStatus();
        void setRow(int n_row);
        void setCol(int n_col);
        void setHp(int value);
        void setAtk(double value);
        void setDef(double value);
        void clearAtk();
        void clearDef();
        void setStatus();
//        void setAction(std::string action, std::string whom);
        virtual void attack(human &h);
        virtual void attack(dwarf &w);
        virtual void attack(elf &e);
        virtual void attack(orcs &o);
        virtual void attack(merchant &m);
        virtual void attack(dragon &d);
        virtual void attack(halfling &l);
        virtual void beAttackedBy(enemy &e)=0;
        void pickGold(int value);
        void move(std::string direction);
        void setAction(std::string info);
        std::string getAction();
        void addAction(std::string newInfo);
	    bool isHostile();
        virtual ~character();
        int getBA();
        void setBA();
        
        int getBD();
        void setBD();

        int getWA();
        void setWA();
        
        int getPH();
        void setPH();

        int getWD();
        void setWD();

        int getRH();
        void setRH();

};
#endif
