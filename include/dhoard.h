#ifndef _dhoard_
#define _dhoard_
#include "treasure.h"
class dhoard: public treasure{
    int d_r;
    int d_c;
public:
     dhoard(int row, int col);
     void set_dragon(int d_row, int d_col);
};
#endif

