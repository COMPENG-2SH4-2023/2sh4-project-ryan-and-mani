#include "Food.h"
#include "MacUILib.h"
#include <cstdlib>
#include <time.h>

Food::Food(GameMechs* mainGameMechsRef_){  //Default constructor 
    foodPos.setObjPos(-1,-1,'j'); 
    mainGameMechsRef = mainGameMechsRef_;
}


void Food::generateFood(objPos blockOff){

    int Rx;
    int Ry; 


    srand(time(NULL));

 
    
    do {
        Rx = (rand() % (mainGameMechsRef->getBoardSizeX() - 2)) + 1;
        Ry = (rand() % (mainGameMechsRef->getBoardSizeY() - 2)) + 1;
    } while (Rx == blockOff.x && Ry == blockOff.y);

    foodPos.x = Rx;
    foodPos.y = Ry;
}


void Food::getFoodPos(objPos &returnPos){

   returnPos = foodPos; 
}




Food::~Food(){

}