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



    public:
        Food(GameMechs* mainGameMechsRef); 
        void generateFood(objPos blockOff); //input playerPos 
        void getFoodPos(objPos &returnPos);


        ~Food();



};

#endif