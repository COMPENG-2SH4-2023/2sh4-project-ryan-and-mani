#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player(); //deconstructor 

        objPosArrayList* getPlayerPos(); //playerBody arrayList
        void updatePlayerDir(); //movement input
        void movePlayer(); //player movement 
        bool checkSelfCollision(); //collison check 

    private:
        objPosArrayList* playerPosList; //making an instance of the class on the heap 
        enum Dir myDir;
        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif