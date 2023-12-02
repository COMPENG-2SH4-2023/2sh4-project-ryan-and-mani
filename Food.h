#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;


class Food{

    private: 
        objPos foodPos; //Refrence to objPos to generate food around the board
        GameMechs* mainGameMechsRef;  // Reference to GameMechs for accessing board size
        objPosArrayList* arrayListRef; //Refrence to objPosArrayList for accessing player body positions




    public:
        Food(GameMechs* mainGameMechsRef); //Constructor
        void generateFood(objPosArrayList* arrayListRef); //Generates a random food item, takes the arrayListRef so that food is not generated on the player body
        void getFoodPos(objPos &returnPos); //Returns the food position


        //~Food(); Destructor Not Needed 



};

#endif