#ifndef RH_H
#define RH_H
#include "potion.h"
#include <string>
class RH: public potion{
    public:
        RH(character *pc, int row, int col,std::string type);
        void effect() override;
};
#endif
