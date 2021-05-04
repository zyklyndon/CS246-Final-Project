#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "characterImpl.h"
#include "character.h"
#include "normal.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "drow.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "orcs.h"
#include "elf.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "potion.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
#include "treasure.h"
#include "floor.h"
#include "cell.h"
#include "xman.h"
#include "superman.h"

using namespace std;

bool isDir(string input){
    if(input == "no"||input == "so"||input=="we"||input=="ea"||input=="ne"||input=="nw"||input=="se"||input=="sw"){
        return true;
    }
    return false;
}

void playGame(string file="default.txt"){
    srand(time(NULL));
//-----------variables initialization---------------------- 
    string com;
    string pcType;
    character *pc;
    Floor *floor=new Floor();
    floor->init(file);
//    floor->printfloor(pc);
//    cout<<"asdsa"<<endl;
    enum class direction{no,so,we,ea,ne,nw,se,sw};
    bool if_frozen = false;
//---------------------------------------------------------

//-----------character initialization----------------------
    cout << "Welcome to CC3K! Please specify your character by choosing from the following options: s, d, v, g, t" << endl;
    cin >> com;
    while(com != "s" && com != "d" && com != "v" && com != "g" && com != "t" &&com !="gameistoohard"){
        cout << "Invalid character. Please choose from the following options: s, d, v, g, t" << endl;
        cin >> com;
    }
    if(com=="gameistoohard"){
        cout << "Welcome to CC3K! Please specify your character by choosing from the following options: s, d, v, g, t, x, super" << endl;
        cin >> com;
        while(com != "s" && com != "d" && com != "v" && com != "g" && com != "t" && com != "x"&&com !="super"){
            /*if(com=="gameistoohard"){
                cin>>com;
                    continue;
            }*/
            cout << "Invalid character. Please choose from the following options: s, d, v, g, t, x, super" << endl;
            cin >> com;
        }
    }
    pcType = com;
    floor->generator(&pc, com);

//--------------------------------------------------------
    cout << endl;
    cout << "Instructions:" << endl;
    cout << "Valid directions: no, so, ea, we, ne, nw, se, sw." << endl;
    cout << "Move: Type a valid direction input and press ENTER." << endl;
    cout << "Attack: Type 'a xx', where xx is a valid direction, and press ENTER." << endl;
    cout << "Use potions/pick up gold: Type 'u xx', where xx is a valid direction, and press Enter." <<endl;
    cout << "r: Restart" << endl;
    cout << "f: freeze enemies so that they can NOT move." << endl;
    cout << "i: review the instruction." << endl;
    cout << "q: quit the game." << endl;  
    cout << endl; 
    floor->printfloor(*pc);
    //cout << "Action: Your player character has spawned." << endl;
//----------command from players--------------------------
        while((cin >> com)){
            if(isDir(com)){
                try{
                    floor->playerMove(com, *pc);
                }
                catch(out_of_range &ia){
                    //cout << "You just reached Floor " << floor->getFloor()+1 << "!" << endl;
                    floor->generator(&pc);
                }
                if(!if_frozen){
                    floor->enemyAutoMove(*pc);
                }
                floor->enemyAutoAttack(*pc);
                //---print info----
                floor->printfloor(*pc);
                //-----------------
            }else if(com == "u"){
                cin >> com;
                //cout << "command is captured. it's " << com << endl;
                int cur_row = pc->getRow();
                int cur_col = pc->getCol();
                if(com == "no"){
                    floor->pick(cur_row-1,cur_col, pc);
                }else if(com == "so"){
                    floor->pick(cur_row+1,cur_col, pc);
                }else if(com == "we"){
                    floor->pick(cur_row, cur_col-1, pc);
                }else if(com == "ea"){
                    floor->pick(cur_row, cur_col+1, pc);
                }else if(com == "se"){
                    floor->pick(cur_row+1,cur_col+1, pc);
                }else if(com == "sw"){
                    floor->pick(cur_row+1, cur_col-1, pc);
                }else if(com == "ne"){
                    floor->pick(cur_row-1, cur_col+1, pc);
                }else if(com == "nw"){
                    floor->pick(cur_row-1, cur_col-1, pc);
                }
                if(!if_frozen){
                    floor->enemyAutoMove(*pc);
                }
                floor->enemyAutoAttack(*pc);
                //----print info------
                floor->printfloor(*pc);
                //--------------------
            }else if(com == "a"){
                cin >> com;
                int cur_row = pc->getRow();
                int cur_col = pc->getCol();
                if(com == "no"){
                    floor->attack(cur_row-1,cur_col, pc);
                }else if(com == "so"){
                    floor->attack(cur_row+1,cur_col, pc);
                }else if(com == "we"){
                    floor->attack(cur_row, cur_col-1, pc);
                }else if(com == "ea"){
                    floor->attack(cur_row, cur_col+1, pc);
                }else if(com == "se"){
                    floor->attack(cur_row+1,cur_col+1, pc);
                }else if(com == "sw"){
                    floor->attack(cur_row+1, cur_col-1, pc);
                }else if(com == "ne"){
                    floor->attack(cur_row-1, cur_col+1, pc);
                }else if(com == "nw"){
                    floor->attack(cur_row-1, cur_col-1, pc);
                }
                if(!if_frozen){
                    floor->enemyAutoMove(*pc);
                }
                floor->enemyAutoAttack(*pc);
                floor->printfloor(*pc);
            }else if(com == "f"){
                if(if_frozen){
                    cout << "The game has been unfrozen. The enemies will move until you hit 'f' again to freeze them" << endl;
                    if_frozen = false;
                }else{
                    cout << "The game has been frozen. The enemies will not move until you hit 'f' to unfreeze them" << endl;
                    if_frozen = true;
                }
            }else if(com == "r"){
                cout << "Are you sure you want to restart the game? You will lose any progress you've made. (y or n)" << endl;
                cin >> com;
                if(com == "y"){
                    delete pc;
                    delete floor;
                    cout << "The game has been restarted." << endl;
                    playGame(file);
                }
            }else if(com == "q"){
                delete pc;
                delete floor;
                return;
            }else if(com == "i"){
                cout << "Instructions:" << endl;
                cout << "Valid directions: no, so, ea, we, ne, nw, se, sw." << endl;
                cout << "Move: Type a valid direction input and press ENTER." << endl;
                cout << "Attack: Type 'a xx', where xx is a valid direction, and press ENTER." << endl;
                cout << "Use potions/pick up gold: Type 'u xx', where xx is a valid direction, and press Enter." <<endl;
                cout << "r: Restart" << endl;
                cout << "f: freeze enemies so that they can NOT move." << endl;
                cout << "i: review the instruction." << endl;
                cout << "q: quit the game." << endl;  
            }else{
                cout << "Invalid input." << endl;
            }
            if((pc->getHp()<0)||(floor->getFloor()>5)){
                break;       
            }
        }
    if(pc->getHp() <= 0){
        cout << "Your character is defeated.";
    }else if(floor->getFloor()>5){
        cout << "Congratulations! You made it!";
    }          
    cout << " You made the score of " << pc->getGold() <<". Do you wanna restart or quit? (r or q, any other keys will quit the game)" << endl;
    cin >> com;
    if(com == "r"){
        delete pc;
        delete floor;
        playGame(file);
    }else if(com == "q"){
        delete pc;
        delete floor;
        return;
    }else{
    delete pc;
    delete floor;
    return;
    }
}

int main(int argc, char*argv[]){
    if(argc>2){
        cout<<"Too many files!"<<endl;
        return 0;
    }else if(argc == 2){
        playGame(argv[1]);
    }else{
        playGame();
    }
}
