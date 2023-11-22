#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"


Food::Food(){  //Default constructor 
    foodPos.objPos(5,5,'m'); 

}

Food::Food(int initX, int initY, char initS){  //Constructor 2
    foodPos.objPos(initX,initY,initS); 

}

Food:generateFood(objPos blockOff){

    int Rx;
    int Ry; 
    int BitVecX[GameMechs.getBoardSizeX-2] = {0}; //for food position x
    int BitVecY[GameMechs.getBoardSizeY-2] = {0}; //for food position y 
    //int BitVecR[94] = {0}; //for random character symbol between 33-126

    srand(time(NULL));

    Rx = (rand() % GameMechs.getBoardSizeX-2)+1;
    Ry = (rand() % GameMechs.getBoardSizeY-2)+1;

    if (Rx != blockOff.x && Ry != blockOff.y)





}




Food::~Food(){

}
