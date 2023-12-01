#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        bool checkSelfCollision();
    


        //lastly add self collision check 
        //if self collided -> set lose flag and exit to true through GM
        // this will break the program loop and end the game

        //- if ending you need to diferentiate the end game state 
        //LOST -> display lost message
        //otherwise -> display end gam message 

    private:
        objPosArrayList* playerPosList; //making an instance of the class on the heap -> storing a list of positions rather than a single position 
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif