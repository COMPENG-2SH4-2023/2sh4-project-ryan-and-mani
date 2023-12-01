#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{

    input = 0;
    exitFlag = false;
    boardSizeX = 30; //default board size x 
    boardSizeY = 15; //default board size y 
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}


// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{

    return exitFlag;

}

//bool GameMechs::getLoseFlagStatus(){
    //return loseflag; 
//}
void GameMechs::setLoseFlag(){
     loseflag = 1; 
}


char GameMechs::getInput()
{
    
    if (MacUILib_hasChar() != 0){

        input = MacUILib_getChar(); 
    }

    return input; 

}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY; 
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput() 
{
    input = -1; //a non ascii value 
}



int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(int incVal){
    score += incVal; 
}










 GameMechs::~GameMechs(){ //DESTRUCTOR 
    //delete myGM; 
        }