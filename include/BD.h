#ifndef BD_H
#define BD_H
#include "potion.h"
#include <string>
class BD: public potion{
    public:
        BD(character *pc, int row, int col,std::string type);
        void effect() override;
};
#endif
