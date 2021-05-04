//
//  cell.cpp
//  project
//
//  Created by tianhaoqing on 2018/7/14.
//  Copyright © 2018年 tianhaoqing. All rights reserved.
//

#include "cell.h"

int Cell::getRow(){
    return row;
}

int Cell::getCol(){
    return col;
}

Type Cell::GetOtype(){
    return oritype;
}

Type Cell::GetCtype(){
    return curtype;
}


void Cell::unsetCell(){
    curtype = oritype;
}

void Cell::setCell(Type type){
    curtype = type;
}

Cell::Cell(int row, int col, Type otype, Type ctype): row{row}, col{col},oritype{otype},curtype{ctype} {}

