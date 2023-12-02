#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{

    private:
        char input; //Key input 
        bool exitFlag; //Exit flag to end program loop 
        int score; //Score for tracking how many foods have been consumed 
        bool loseflag; //Lose flag to show when the player has lost 

        int boardSizeX; 
        int boardSizeY;

    public:
        GameMechs();//Default constructor 
        GameMechs(int boardX, int boardY);//Constructor 1 
        
        bool getExitFlagStatus(); //Returns exit flag status: true or false 
        bool getLoseFlagStatus(); //Returns lose flag status: true or false 
        void setExitTrue(); //Sets exit flag to true (1)
        void setLoseFlag(); //Set lose flag to true (1)

        char getInput(); //Get player key input if theres an input 
        void setInput(char this_input); 
        void clearInput();

        int getBoardSizeX();//Return board x size 
        int getBoardSizeY();//Return board y size 

        int getScore(); //Return score
        void incrementScore(int incVal);//Add inVal to the score 

 
    //    ~GameMechs(); Destructor Not Needed 


};

#endif