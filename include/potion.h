#ifndef POTION_H
#define POTION_H
#include "enemy.h"
#include "character.h"
#include <string>
class potion: public character{
    protected:
        character *theChar;
        int counter;
        int row;
        int col;
        std::string type;
        bool used;
    public:
        potion(character* pc,int row, int col, std::string type);
        virtual void effect()=0;
        int getRow();
        int getCol();
        std::string getType();
        int getCounter();
        void setCounter();
        virtual ~potion();
        void beAttackedBy(enemy &e);
        bool getStatus();
        void setStatus();
};
#endif
