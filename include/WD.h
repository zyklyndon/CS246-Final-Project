#ifndef WD_H
#define WD_H
#include "potion.h"
#include <string>
class WD: public potion{
    public:
        WD(character *pc, int row, int col,std::string type);
        void effect() override;
};
#endif
