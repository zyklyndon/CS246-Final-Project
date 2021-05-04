//
//  cell.hpp
//  project
//
//  Created by tianhaoqing on 2018/7/14.
//  Copyright © 2018年 tianhaoqing. All rights reserved.
//

#ifndef cell_h
#define cell_h
#include <stdio.h>

enum class Type {VWall,HWall, Tile, Passage, Door, Blank, Stair, Potion, Gold, Player, Dragon, Halfling, Merchant, Orcs, Elf, Dwarf, Human};

class Cell{
    int row;
    int col;
    Type oritype;
    Type curtype;
public:
    int getRow();
    int getCol();
    Cell(int row, int col, Type otype, Type ctype);
    void unsetCell();
    void setCell(Type type);
    Type GetOtype();
    Type GetCtype();
};



#endif

