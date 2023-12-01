#include "Food.h"
#include "MacUILib.h"
#include <cstdlib>
#include <time.h>

Food::Food(GameMechs* mainGameMechsRef_){  //Default constructor 
    foodPos.setObjPos(-1,-1,'j'); 
    mainGameMechsRef = mainGameMechsRef_;
}


void Food::generateFood(objPosArrayList* arrayListRef){

    int Rx;
    int Ry; 
    int flag = 0;

    srand(time(NULL));

    while(flag == 0)
    {
        Rx = (rand() % (mainGameMechsRef->getBoardSizeX() - 2)) + 1;
        Ry = (rand() % (mainGameMechsRef->getBoardSizeY() - 2)) + 1;

        for(int i = 0; i < arrayListRef->getSize(); i++)
        {
            flag = 1;
            objPos currentPos;
            arrayListRef->getElement(currentPos,i);

            if(currentPos.x == Rx && currentPos.y == Ry)
            {
                flag = 0;
                break;
            }
        }

         if(flag == 1)
            {
                  foodPos.x = Rx;
                  foodPos.y = Ry;
                  break;
            }
    }
}


void Food::getFoodPos(objPos &returnPos){

   returnPos = foodPos; 
}




Food::~Food(){

}