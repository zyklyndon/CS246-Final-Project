#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "floor.h"
#include "enemy.h"
#include "character.h"
#include "goblin.h"
#include "xman.h"
#include "vampire.h"
#include "normal.h"
#include "troll.h"
#include "potion.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
#include <vector>
#include "drow.h"
#include "small.h"
#include "midgold.h"
#include "mhoard.h"
#include "dhoard.h"
#include "halfling.h"
#include "orcs.h"
#include "dragon.h"
#include "elf.h"
#include "merchant.h"
#include "human.h"
#include "dwarf.h"
#include "superman.h"
using namespace std;
//class dragon;

int Floor::getFloor(){
    return level;
}
void Floor::init(string filename){
    string line;
    ifstream f1 (filename);
    char c;
    int i = 0;
    level = 0;
    vector<Cell*> temp;
    thefloor = new vector<vector<Cell *>>;
    while(getline(f1,line)){
        for(int k=0; k<line.length();k++){
            c=line[k];
                if (c=='-'){
                    Cell *a = new Cell{i,k,Type::HWall,Type::HWall};
                    temp.push_back(a);
                }else if(c=='|'){
                    Cell *a = new Cell{i,k,Type::VWall,Type::VWall};
                    temp.push_back(a);
                }else if (c=='#'){
                    Cell *a = new Cell{i,k,Type::Passage,Type::Passage};
                    temp.push_back(a);
                } else if (c=='+'){
                    Cell *a = new Cell{i,k,Type::Door,Type::Door};
                    temp.push_back(a);
                } else if (c==' '){
                    Cell *a = new Cell{i,k,Type::Blank,Type::Blank};
                    temp.push_back(a);
                } else if (c=='.'){
                    Cell *a = new Cell{i,k,Type::Tile, Type::Tile};
                    temp.push_back(a);
                }
        }
        thefloor->push_back(temp);
        temp.clear();
        i=i+1;
    }
    height=25;
    width=79;
}

void Floor::printfloor(character &pc){
    for(int i=0;i<height;i++){
        for(int j=0; j<width;j++){
            //cout<< (*thefloor).at(0).at(0)->getRow() <<endl;
            Type fType = ((*thefloor)[i][j])->GetCtype();
            // cout<<width<<endl;
            if(fType==Type::VWall){
                cout<<"|";
            }else if(fType==Type::HWall){
                cout<<"-";
            }else if(fType==Type::Tile){
                cout<<".";
            }else if(fType==Type::Passage){
                cout<<"#";
            }else if(fType==Type::Door){
                cout<<"+";
            }else if(fType==Type::Blank){
                cout<<" ";
            }else if(fType==Type::Stair){
                cout<<"/";
            }else if(fType==Type::Potion){
                cout<<"P";
            }else if(fType==Type::Gold){
                cout<<"G";
            }else if(fType==Type::Player){
                cout<<"@";
            }else if(fType==Type::Dragon){
                cout<<"D";
            }else if(fType==Type::Halfling){
                cout<<"L";
            }else if(fType==Type::Merchant){
                cout<<"M";
            }else if(fType==Type::Orcs){
                cout<<"O";
            }else if(fType==Type::Elf){
                cout<<"E";
            }else if(fType==Type::Dwarf){
                cout<<"W";
            }else{
                cout<<"H";
            }
        }
        cout<<endl;
    }
    cout << "Race: " << pc.getType() << " Gold: " << pc.getGold()  << "                  Floor " << level << endl;
    cout << "HP: ";
    if(pc.getHp()<0){
        cout << "0" << endl;
    }else{
        cout << pc.getHp() << endl;
    }
    cout << "Atk: " << pc.getAtk() << endl;
    cout << "Def: " << pc.getDef() << endl;
    cout << "Action: " << pc.getAction() << endl;
    return;
    
}


void Floor::generator(character **pc, string com){
    level++;
    //clear the store info for last floor
    potions.clear();    
    enemies.clear();
    treasures.clear();
    vector<vector<Cell *>> graph = getRoom();
    int numOfRooms = graph.size();
    int roomNum, roomSize, randIndex;
    //generate the player
    roomNum = rand()%numOfRooms; //the random index for the room
    vector<Cell *> room = graph[roomNum]; // select the room
    roomSize = graph.at(roomNum).size(); //the size of the selected room
    randIndex = rand()%roomSize; // randomlize an index in the room
    setCell(room[randIndex]->getRow(),room[randIndex]->getCol(),Type::Player);
    if(com != " "){
        if(com == "v"){
            *pc = new vampire(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "d"){
            *pc = new drow(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "t"){
            *pc = new troll(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "g"){
            *pc = new goblin(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "s"){
            *pc = new normal(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "x"){
            *pc = new xman(room[randIndex]->getRow(),room[randIndex]->getCol());
        } else if (com == "super"){
            *pc = new superman(room[randIndex]->getRow(),room[randIndex]->getCol());
        }

    }else{
        (*pc)->setRow(room[randIndex]->getRow());
        (*pc)->setCol(room[randIndex]->getCol());
    }
    (*pc)->setAction("Your PC has spawned");
    //generate the stairway
    int playerRoom = roomNum; //can't assign the stair to the same room
    roomNum = rand()%numOfRooms; //reroll the room number
    while(roomNum == playerRoom){
        roomNum = rand()%numOfRooms;
    }
    room = graph[roomNum]; 
    roomSize = graph[roomNum].size();
    randIndex = rand()%roomSize;
    setCell(room[randIndex]->getRow(),room[randIndex]->getCol(),Type::Stair);
    //printfloor(*pc);
    //generate potions
    int potionType;
    for(int i=1; i<=10; i++){
        potionType = rand()%6 + 1; // roll the type of the potion
        potion *temp_potion;
        roomNum = rand()%numOfRooms;
        vector<Cell *> room = graph[roomNum];
        roomSize = room.size();
        randIndex = rand()%roomSize;
        while(room[randIndex]->GetCtype() != room[randIndex]->GetOtype()){
            randIndex = rand()%roomSize;
        }
        
        switch (potionType){
            case 1:
                temp_potion = new RH{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "RH"};
                break;
            case 2:
                temp_potion = new BA{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "BA"};
                break;
            case 3:
                temp_potion = new BD{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "BD"};
                break;
            case 4:
                temp_potion = new PH{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "PH"};
                break;
            case 5:
                temp_potion = new WA{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "WA"};
                break;
            case 6:
                temp_potion = new WD{*pc, room[randIndex]->getRow(),room[randIndex]->getCol(), "WD"};
                break;
        }
        potions.push_back(temp_potion);
        setCell(room[randIndex]->getRow(),room[randIndex]->getCol(),Type::Potion);
    }
    //printfloor(*pc);
    //generate gold
    int treasureType;
    for(int j=0; j<10; j++){
        treasureType = rand()%8 + 1;
        treasure *temp_treasure;
        int roomNum = rand()%numOfRooms;
        vector<Cell *> room = graph[roomNum];
        int roomSize = room.size();
        int randIndex = rand()%roomSize;
        treasure *temp;
        while(room[randIndex]->GetCtype() != room[randIndex]->GetOtype()){
            randIndex = rand()%roomSize;
        }
        if(treasureType == 1){//dragon hoard
            int g_row = room[randIndex]->getRow();
            int g_col = room[randIndex]->getCol();
            while((*thefloor)[g_row][g_col]->GetCtype() != Type::Tile){
                g_row = room[randIndex]->getRow();
                g_col = room[randIndex]->getCol();
            }
            int d_col = rand()%3 - 1;
            int d_row = rand()%3 - 1;
            bool isFull = true;
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(!(i==0 && j==0)){
                        if((*thefloor)[g_row+i][g_col+j]->GetCtype() == Type::Tile){
                            isFull = false;
                            break;
                        }
                    }
                }
            }
            while(isFull){
                g_row = room[randIndex]->getRow();
                g_col = room[randIndex]->getCol();
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        if(!(i==0 && j==0)){
                            if((*thefloor)[g_row+i][g_col+j]->GetCtype() == Type::Tile){
                                isFull = false;
                                break;
                            }
                        }
                    }
                }
            }
            while((*thefloor)[g_row+d_row][g_col+d_col]->GetCtype() != Type::Tile){
                d_col = rand()%3 - 1;
                d_row = rand()%3 - 1;
            }
            enemy *new_dragon = new dragon{g_row+d_row,g_col+d_col,this,room[randIndex]->getRow(),room[randIndex]->getCol()};
            enemies.push_back(new_dragon);
            setCell(g_row+d_row,g_col+d_col,Type::Dragon);
            temp = new dhoard{room[randIndex]->getRow(),room[randIndex]->getCol()};
        }else if(treasureType == 2 || treasureType == 3){//small hoard
            temp = new small{room[randIndex]->getRow(),room[randIndex]->getCol()};
        }else{//normal
            temp = new midgold{room[randIndex]->getRow(),room[randIndex]->getCol()};
        }
        treasures.push_back(temp);        
        setCell(room[randIndex]->getRow(),room[randIndex]->getCol(),Type::Gold);
    }
    //printfloor(*pc);
    //generate enemy
    int enemyType;
    for(int k=1; k<=20; k++){
        enemy *temp_enemy;
        int roomNum = rand()%numOfRooms;
        vector<Cell *> room = graph[roomNum];
        int roomSize = room.size();
        int randIndex = rand()%roomSize;
        while(room[randIndex]->GetCtype() != room[randIndex]->GetOtype()){
            randIndex = rand()%roomSize;
        }
        enemyType = rand()%18 + 1;
        //cout << "enemyType: "<<enemyType << endl;
        if(1<=enemyType && enemyType<=4){//human
            temp_enemy = new human{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Human);

        }else if(5<=enemyType && enemyType<=7){//dwarf
            temp_enemy = new dwarf{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Dwarf);

        }else if(8<=enemyType && enemyType<=12){//halfling
            temp_enemy = new halfling{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Halfling);

        }else if(13<=enemyType && enemyType<=14){//elf
            temp_enemy = new elf{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Elf);

        }else if(15<=enemyType && enemyType<=16){//orc
            temp_enemy = new orcs{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Orcs);

        }else if(17<=enemyType && enemyType<=18){//merchant
            temp_enemy = new merchant{room[randIndex]->getRow(),room[randIndex]->getCol(),this};
            setCell(room[randIndex]->getRow(),room[randIndex]->getCol(), Type::Merchant);

        }
        enemies.push_back(temp_enemy);
        //cout << "generation finishes!" <<endl;
    }
    //printfloor(*pc);
}


int absv(int a){
    if (a<0){
        return -a;
    } else {
        return a;
    }
}

vector<vector<Cell *>>Floor::getRoom(){
    vector<Cell *> temp; // vector of cells that is tile
    for (int i = 0; i<height; i++){
        for (int j = 0; j<width; j++){
            if ((*thefloor)[i][j]->GetOtype() == Type::Tile){
                temp.push_back((*thefloor)[i][j]);
            }
        }
    }
    int n = temp.size();//number of tiles
    vector<vector <Cell *>> rooms;//ideal collectino of rooms. each oroom is a vector of tiles
    vector<Cell *> r1;//default room 1
    r1.push_back(temp[0]);//base point
    rooms.push_back(r1);  
    for(int i = 1; i<n; i++){
        bool is_newroom=false;
        //loop through every tile. the first tile has been pushed into room
        for(int j=0; j<rooms.size();j++){
            is_newroom=false;
            bool if_break = false;
            for(int s=0;s<rooms[j].size();s++){
                is_newroom=false;
                int rd = absv(rooms[j][s]->getRow()-temp[i]->getRow());
                int cd = absv(rooms[j][s]->getCol()-temp[i]->getCol());
                if (rd<=1&&cd<=1){
                    rooms[j].push_back(temp[i]);
                    if_break = true;
                    break;//add the ith tile into room j
                }
            }
            if(if_break){
                break;
            }else{
                is_newroom=true;
            }
        }
        if(is_newroom){
        vector<Cell *> tmp;
        tmp.push_back(temp[i]);
        rooms.push_back(tmp);
        }
    }
    bool is_break=false;;
    for(int i=0; i<rooms.size();i++){
        for(int j=i+1;j<rooms.size();j++){
            for(int k=0;k<rooms[i].size();k++){
                for(int l=0;l<rooms[j].size();l++){
                    int row_diff=abs(rooms[i][k]->getRow()-rooms[j][l]->getRow());
                    int col_diff=abs(rooms[i][k]->getCol()-rooms[j][l]->getCol());
                    if(row_diff<=1&&col_diff<=1){
                        for(int m=0;m<rooms[j].size();m++){
                            rooms[i].push_back(rooms[j][m]);
                        }
                        rooms.erase(rooms.begin()+j);
                        is_break=true;
                        break;
                    }
                }
                if(is_break){
                    break;
                }
            }
           if(is_break){
                break;
           } 
        }
        if(is_break){
            break;
        }
    }

    for(int i=0; i<rooms.size();i++){
        is_break=false;
        for(int j=i+1;j<rooms.size();j++){
            for(int k=0;k<rooms[i].size();k++){
                for(int l=0;l<rooms[j].size();l++){
                    int row_diff=abs(rooms[i][k]->getRow()-rooms[j][l]->getRow());
                    int col_diff=abs(rooms[i][k]->getCol()-rooms[j][l]->getCol());
                    if(row_diff<=1&&col_diff<=1){
                        for(int m=0;m<rooms[j].size();m++){
                            rooms[i].push_back(rooms[j][m]);
                        }
                        rooms.erase(rooms.begin()+j);
                        is_break=true;
                        break;
                    }
                }
                if(is_break){
                    break;
                }
            }
           if(is_break){
                break;
           } 
        }
        if(is_break){
            break;
        }
    }


    for(int i=0; i<rooms.size();i++){
        is_break=false;
        for(int j=i+1;j<rooms.size();j++){
            for(int k=0;k<rooms[i].size();k++){
                for(int l=0;l<rooms[j].size();l++){
                    int row_diff=abs(rooms[i][k]->getRow()-rooms[j][l]->getRow());
                    int col_diff=abs(rooms[i][k]->getCol()-rooms[j][l]->getCol());
                    if(row_diff<=1&&col_diff<=1){
                        for(int m=0;m<rooms[j].size();m++){
                            rooms[i].push_back(rooms[j][m]);
                        }
                        rooms.erase(rooms.begin()+j);
                        is_break=true;
                        break;
                    }
                }
                if(is_break){
                    break;
                }
            }
           if(is_break){
                break;
           } 
        }
        if(is_break){
            break;
        }
    }

    for(int i=0; i<rooms.size();i++){
        is_break=false;
        for(int j=i+1;j<rooms.size();j++){
            for(int k=0;k<rooms[i].size();k++){
                for(int l=0;l<rooms[j].size();l++){
                    int row_diff=abs(rooms[i][k]->getRow()-rooms[j][l]->getRow());
                    int col_diff=abs(rooms[i][k]->getCol()-rooms[j][l]->getCol());
                    if(row_diff<=1&&col_diff<=1){
                        for(int m=0;m<rooms[j].size();m++){
                            rooms[i].push_back(rooms[j][m]);
                        }
                        rooms.erase(rooms.begin()+j);
                        is_break=true;
                        break;
                    }
                }
                if(is_break){
                    break;
                }
            }
           if(is_break){
                break;
           } 
        }
        if(is_break){
            break;
        }
    }

    for(int i=0; i<rooms.size();i++){
        is_break=false;
        for(int j=i+1;j<rooms.size();j++){
            for(int k=0;k<rooms[i].size();k++){
                for(int l=0;l<rooms[j].size();l++){
                    int row_diff=abs(rooms[i][k]->getRow()-rooms[j][l]->getRow());
                    int col_diff=abs(rooms[i][k]->getCol()-rooms[j][l]->getCol());
                    if(row_diff<=1&&col_diff<=1){
                        for(int m=0;m<rooms[j].size();m++){
                            rooms[i].push_back(rooms[j][m]);
                        }
                        rooms.erase(rooms.begin()+j);
                        is_break=true;
                        break;
                    }
                }
                if(is_break){
                    break;
                }
            }
           if(is_break){
                break;
           } 
        }
        if(is_break){
            break;
        }
    }



    return rooms;
}

void Floor::unsetCell(int row, int col){
    (*thefloor)[row][col]->unsetCell();
}

void Floor::setCell(int row, int col, Type type){
        (*thefloor)[row][col]->setCell(type);
}

bool Floor::valid(int i, int j){
    Type a = (*thefloor)[i][j]->GetCtype();
    if ((a==Type::Tile)||
        (a==Type::Passage)||
        (a==Type::Door)||
        (a==Type::Gold)||
        (a==Type::Stair)){
        return true;
    }
    return false;
}

bool Floor::isValidMove(int row, int col, string dir){
    if ((dir=="no"&&(!(valid(row-1,col))))||
        (dir=="so"&&(!(valid(row+1,col))))||
        (dir=="ea"&&(!(valid(row,col+1))))||
        (dir=="we"&&(!(valid(row,col-1))))||
        (dir=="ne"&&(!(valid(row-1,col+1))))||
        (dir=="nw"&&(!(valid(row-1,col-1))))||
        (dir=="se"&&(!(valid(row+1,col+1))))||
        (dir=="sw"&&(!(valid(row+1,col-1))))){
        return false;
    }
    return true;
}

bool is_valid(int row, int col, string command){
    if(command=="no"){
        if((row-1)<0){
            return false;
        }
        return true;
    }else if(command=="ea"){
        if((col+1)>78){
            return false;
        }
        return true;
    }else if(command=="so"){
        if((row+1)>24){
            return false;
        }
        return true;
    }else if(command=="we"){
        if((col-1)<0){
            return false;
        }
        return true;
    }else if(command=="ne"){
        if(((row-1)<0)||((col+1)>78)){
            return false;
        }
        return true;
    }else if(command=="se"){
        if(((row+1)>24)||((col+1)>78)){
            return false;
        }
        return true;
    }else if(command=="sw"){
        if(((row+1)>24)||((col-1)<0)){
            return false;
        }
        return true;
    }else{
        if(((row-1)<0)||((col-1)<0)){
        return false;
        }
        return true;
    }
}

bool Floor::isValidEnemyMove(int row, int col, string command, Type type){
    if(!is_valid(row, col, command)){
          return false;
    }
    if ((command == "no")&&((*thefloor)[row-1][col]->GetCtype()==Type::Tile)){
        setCell(row-1,col,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "so")&&((*thefloor)[row+1][col]->GetCtype()==Type::Tile)){
        setCell(row+1,col,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "ea")&&((*thefloor)[row][col+1]->GetCtype()==Type::Tile)){
        setCell(row,col+1,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "we")&&((*thefloor)[row][col-1]->GetCtype()==Type::Tile)){
        setCell(row,col-1,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "ne")&&((*thefloor)[row-1][col+1]->GetCtype()==Type::Tile)){
        setCell(row-1,col+1,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "nw")&&((*thefloor)[row-1][col-1]->GetCtype()==Type::Tile)){
        setCell(row-1,col-1,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "se")&&((*thefloor)[row+1][col+1]->GetCtype()==Type::Tile)){
        setCell(row+1,col+1,type);
        unsetCell(row,col);
        return true;
    } else if ((command == "sw")&&((*thefloor)[row+1][col-1]->GetCtype()==Type::Tile)){
        setCell(row+1,col-1,type);
        unsetCell(row,col);
        return true;
    } else {
        return false;
    }
    return false;
}


void Floor::playerMove(string command, character &player){
    int pr = player.getRow();
    int pc = player.getCol();
    int delta_row=0;
    int delta_col=0;
    if (!isValidMove(pr,pc,command)){
        player.setAction("Invalid movement.");
        return;
    }
    string actionInfo;
    if (command == "no"){
        delta_row = -1;
        actionInfo = "You moves North.";
    } else if (command == "so"){
        delta_row = 1;
        actionInfo = "You move South.";
    } else if (command == "ea"){
        delta_col = 1;
        actionInfo = "You move East.";
    } else if (command == "we"){
        delta_col = -1;
        actionInfo = "You move West.";
    } else if (command == "ne"){
        delta_row = -1;
        delta_col = 1;
        actionInfo = "You move Northeast.";
    } else if (command == "nw"){
        delta_row = -1;
        delta_col = -1;
        actionInfo = "You move Northwest.";
    } else if (command == "se"){
        delta_row = 1;
        delta_col = 1;
        actionInfo = "You move Southeast.";
    } else if (command == "sw"){
        delta_row = 1;
        delta_col = -1;
        actionInfo = "You move Southwest.";
    }
    int new_r = pr+delta_row;
    int new_c = pc+delta_col;
    int unknown_p = 0;
    int known_p = 0;
    vector<string> pList;
    //check if there is any potions around
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if((*thefloor)[new_r+i][new_c+j]->GetCtype() == Type::Potion){
                for(int k=0; k<potions.size();k++){
                    if(potions[k]->getRow() == new_r+i && potions[k]->getCol() == new_c+j){
                        string ptype = potions[k]->getType();
                        if(ptype == "RH"){
                            if(player.getRH() == 0){
                                unknown_p++;

                            }else{
                                known_p++;
                                pList.push_back("RH");
                            }
                        }else if(ptype == "WA"){
                            if(player.getWA() == 0){
                                unknown_p++;

                            }else{
                                known_p++;
                                pList.push_back("WA");
                            }
                        }else if(ptype == "WD"){
                            if(player.getWD() == 0){
                                unknown_p++;

                            }else{
                                known_p++;
                                pList.push_back("WD");
                            }
                        }else if(ptype == "BA"){
                            if(player.getBA() == 0){
                                unknown_p++;

                            }else{
                                known_p++;
                                pList.push_back("BA");
                            }
                        }else if(ptype == "BD"){
                            if(player.getBD() == 0){
                                unknown_p++;
     
                            }else{
                                known_p++;
                                pList.push_back("BD");
                            }
                        }else if(ptype == "PH"){
                            if(player.getPH() == 0){
                                unknown_p++;

                            }else{
                                known_p++;
                                pList.push_back("PH");
                            }
                        }                      
                    }
                }
            }
        }
    }
    if(unknown_p == 1){
        actionInfo += " An unknown potion is seen.";
    }else if(unknown_p > 1){
        actionInfo += " Some unknown potions are seen.";
    }
    if(known_p == 1){
        actionInfo += " A "+pList[0]+" potion is seen.";
    }else if(known_p > 1){
        actionInfo += "Potions ";
        for(int i=0; i<pList.size();i++){
            if(i != pList.size()-1){
                actionInfo = actionInfo + pList[i] + ", ";
            }else{
                actionInfo = actionInfo + pList[i] + " ";
            }
        }
        actionInfo += " are seen.";
    }
    player.setAction(actionInfo);
    if((*thefloor)[new_r][new_c]->GetCtype() == Type::Stair){
        for(int i=0;i<25;i++){
            for(int j=0;j<79;j++){
                unsetCell(i,j);
            }
        }
        player.clearAtk();
        player.clearDef();
        player.setAction("You reached Floor "+to_string(level+1));
        throw out_of_range("xia lou le!");
    }
    if ((*thefloor)[new_r][new_c]->GetCtype()==Type::Gold){
        for (int i = 0; i<treasures.size(); i++){
            if((treasures[i]->getRow()== pr+delta_row)&&(treasures[i]->getCol()==pc+delta_col)){
                if (treasures[i]->getPickable()){
                    unsetCell(pr+delta_row,pc+delta_col);
                    player.pickGold(treasures[i]->getValue());
                    player.setAction("You picked up "+to_string(treasures[i]->getValue())+" golds.");
                } else {
                    player.setAction("You need to kill dragon first to pick it up!");
		    return;
                }
            }
        }
    }
    unsetCell(pr,pc);
    setCell(pr+delta_row,pc+delta_col,Type::Player);
    player.setRow(player.getRow()+delta_row);
    player.setCol(player.getCol()+delta_col);
    if(player.getType() == "Troll"){
        player.setHp(5);
    }
    //player.move(command);
}


void Floor::pick(int row, int col, character *pc){
    if (!((*thefloor)[row][col]->GetCtype()==Type::Potion || (*thefloor)[row][col]->GetCtype()==Type::Gold)){
        pc->setAction("Your action is invalid to your target.");
        return;
    }
    if ((*thefloor)[row][col]->GetCtype()==Type::Potion){
        for(int i=0; i<potions.size();i++){
            if(potions[i]->getRow()==row&&potions[i]->getCol()==col&&!potions[i]->getStatus()){
                potions[i]->effect();
                potions[i]->setStatus();
                unsetCell(row,col);
                pc->setAction("You used "+potions[i]->getType()+".");
            }
        }
        unsetCell(row,col);
    }
    if ((*thefloor)[row][col]->GetCtype()==Type::Gold){
        for (int i = 0; i<treasures.size(); i++){
            if ((treasures[i]->getRow() == row)&&(treasures[i]->getCol() == col && !treasures[i]->getStatus())){
                if (treasures[i]->getPickable()){
                    unsetCell(row,col);
                    treasures[i]->setStatus();
                    pc->pickGold(treasures[i]->getValue());
                    pc->setAction("You picked up "+to_string(treasures[i]->getValue())+" golds.");
                } else {
                    pc->setAction("You have to defeat the dragon first.");
                    return;
                }
            }
        }
    } else {
        return;
    }
}

int Floor::getHeight() const{
    return height;
}
int Floor::getWidth() const{
    return width;
}

std::vector<std::vector<Cell *>> & Floor::getFloor() const{
    return (*thefloor);
}


void Floor::notified(enemy &e, character &c){
    srand(time(NULL));
    int r=e.getRow();
    int col=e.getCol();
    unsetCell(r,col);
    if(c.getType()=="Goblin"){
        c.addGold(5);
    }
    if(e.getType()==Type::Human){
        treasure *htmp = new midgold{r,col};
        treasures.push_back(htmp);
        setCell(r,col,Type::Gold);
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
            if((*thefloor)[r+i][col+j]->GetCtype()==Type::Tile){
                   treasure *htmp2 = new midgold({r+i,col+j});
                   treasures.push_back(htmp2);
                   setCell(r+i,col+j,Type::Gold);
                   return;
               }   
            }

        }
    }else if(e.getType()==Type::Dragon){
        int h_r=e.getHRow();
        int h_c=e.getHCol();
        for(int i=0;i<treasures.size();i++){
	        if((h_r==treasures[i]->getRow())&&(h_c==treasures[i]->getCol())){
		        treasures[i]->picky();
		        break;
            }   
        }	
    }else if(e.getType()==Type::Merchant){
        treasure *mhd= new mhoard{r,col};
        treasures.push_back(mhd);
        setCell(r,col,Type::Gold);

    }else{
        int val=rand()%2;
        c.addGold(val+1);
    }   
    for(int i=0;i<enemies.size();i++){
        if((r==enemies[i]->getRow())&&(col==enemies[i]->getCol())){
            enemies[i]->dead();
            break;
        }
    }
    return;
}

void Floor::attack(int row, int col, character *pc){
    Type fType = ((*thefloor)[row][col])->GetCtype();
    if(fType==Type::Dragon||fType == Type::Halfling||
       fType==Type::Merchant||fType==Type::Orcs||
       fType==Type::Elf||fType==Type::Dwarf||
       fType==Type::Human){
        for(int i=0;i<enemies.size();i++){
            if(enemies[i]->getRow()==row&&enemies[i]->getCol()==col&&(!enemies[i]->isDead())){
                int eoHp = enemies[i]->getHp();
                int coHp = pc->getHp();
		        try{
                    enemies[i]->beAttackedBy(*pc);
	        	}catch(invalid_argument& ia){
	            	pc->setAction("You missed.");
	            	return;
		        }
                int enHp = enemies[i]->getHp();
                int cnHp = pc->getHp();
                int diffHp=max(0,eoHp-enHp);
                int diffHp2=max(0,coHp-cnHp);
                pc->setAction("You dealt "+to_string(diffHp)+" damage to "+(enemies[i]->getSType())+" ("+to_string(max(0,enHp))+" HP).");
               // pc->addAction(" "+(enemies[i]->getSType())+" deals "+to_string(diffHp2)+" damage to you.");
                return;
            }
        }
	//pc->setAction(" ");
    }
	pc->setAction("Your attemp to attack failed. Can't attack something that's not an enemy.");
    return; 
        
}


void Floor::enemyAutoMove(character &c){
    for(int i=0;i<enemies.size();i++){
        enemies[i]->move(c);
    }
    return;
}

void Floor::enemyAutoAttack(character &c){
    for(int i=0;i<enemies.size();i++){
        enemies[i]->autoAttack(c);
    }
    return;
}








