#include "dhoard.h"
using namespace std;

dhoard::dhoard(int row, int col):treasure{row, col, 6},d_r{0},d_c{0} {pickable=false;}

void dhoard::set_dragon(int d_row, int d_col){
    d_r=d_row;
    d_c=d_col;
}

