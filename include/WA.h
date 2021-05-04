#ifndef WA_H
#define WA_H
#include "potion.h"
#include <string>
class WA: public potion{
    public:
        WA(character *pc, int row, int col, std::string type);
        void effect() override;
};
#endif
