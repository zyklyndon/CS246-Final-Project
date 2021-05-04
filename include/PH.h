#ifndef PH_H
#define PH_H
#include "potion.h"
#include <string>
class PH: public potion{
    public:
        PH(character *pc, int row, int col,std::string type);
        void effect() override;
};
#endif
