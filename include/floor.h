//
//  floor.hpp
//  project
//
//  Created by tianhaoqing on 2018/7/14.
//  Copyright © 2018年 tianhaoqing. All rights reserved.
//

#ifndef floor_h
#define floor_h

#include <stdio.h>
#include <vector>
#include "cell.h"
#include "treasure.h"
#include "potion.h"
class character;
class enemy;
class dragon;
class xman;
class Floor{
    std::vector<std::vector<Cell*>> *thefloor;
    int height;
    int width;
    int level;
    std::vector<enemy*>enemies;
    std::vector<potion*>potions;
    std::vector<treasure*>treasures;
    std::string lastaction;
public:
    void enemyAutoAttack(character &c);
    void init(std::string filename);
    void generator(character **pc, std::string com=" ");
    int getHeight() const;
    int getWidth() const;
    std::vector<std::vector<Cell*>> &getFloor() const;
    std::vector<potion*> generatePotion();
    std::vector<treasure*> generateGold();
    std::vector<std::vector< Cell*>> getRoom();
    std::vector<enemy*> generateEnemy();
    void unsetCell(int row, int col);
    void setCell(int row, int col, Type type);
    bool valid(int i, int j);
    bool isValidMove(int row, int col, std::string dir);
    bool isValidEnemyMove(int row, int col, std::string command, Type type);
    void pick(int row, int col, character *pc);
    void playerMove(std::string command, character &player);
    void printfloor(character &pc);
    void notified(enemy& e, character &c);
    void enemyAutoMove(character &c);
    void attack(int row, int col, character *pc);
    int getFloor();
};

#endif

