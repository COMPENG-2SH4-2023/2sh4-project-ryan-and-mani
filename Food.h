#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class Food{

    private: 
        objPos foodPos; 



    public:
        Food(); 
        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);


        ~Food();



};

#endif