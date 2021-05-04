#ifndef _treasure_
#define _treasure_
#include <cstdlib>
#include "character.h"
class treasure{
protected:
    int row;
    int col;
    int value;
    bool pickable;
    bool picked;
public:
    treasure(int row, int col, int value);
    int getRow();
    bool getPickable();
    int getCol();
    int getValue();
    bool getStatus();
    void setStatus();
    void picky();
};
#endif

