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
    int flag = 0; //Flag variable for tracking if the randomely generated food position overlaps with any of the body items in the arrayListRef

    srand(time(NULL));

    while(flag == 0)
    {
        Rx = (rand() % (mainGameMechsRef->getBoardSizeX() - 2)) + 1; //Used to keep the range within boundaries of the board 
        Ry = (rand() % (mainGameMechsRef->getBoardSizeY() - 2)) + 1; //Used to keep the range within boundaries of the board 

        for(int i = 0; i < arrayListRef->getSize(); i++) //For every item in the snake body, check if the x and y cords are equal to random x and random y.
                                                              
        {
            flag = 1;
            objPos currentPos;
            arrayListRef->getElement(currentPos,i);

            if(currentPos.x == Rx && currentPos.y == Ry) //If equal: set flag to 0 to generate new random values. 
            {
                flag = 0;
                break;
            }
        }

         if(flag == 1) //if the flag is 1 (so the random values didnt overlap) use the randomely generated x and y values as the food positions
            {
                  foodPos.x = Rx;
                  foodPos.y = Ry;
                  break;
            }
    }
}


void Food::getFoodPos(objPos &returnPos){ //Returns position of food

   returnPos = foodPos; 
}




//Food::~Food(){ Destructor Not Needed 

//}