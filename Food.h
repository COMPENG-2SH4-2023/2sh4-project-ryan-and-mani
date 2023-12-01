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
        objPos foodPos; 
        GameMechs* mainGameMechsRef;  // Reference to GameMechs for accessing board size
        objPosArrayList* arrayListRef;




    public:
        Food(GameMechs* mainGameMechsRef); 
        void generateFood(objPosArrayList* arrayListRef); //input playerPos -> you need to upgrade this somehow  
        //need to accept the play body arraylist 
        //go through each arraylist element ot make sure they are all blocked off from random food generation 
        void getFoodPos(objPos &returnPos);


        ~Food();



};

#endif