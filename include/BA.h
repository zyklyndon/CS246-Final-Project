#ifndef BA_H
#define BA_H
#include "potion.h"
#include <string>
class BA: public potion{
    public:
        BA(character *pc, int row, int col,std::string type);
        void effect() override;
};
#endif
