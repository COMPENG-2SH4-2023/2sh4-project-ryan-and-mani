#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@'); //initalze position -> may need to change to take into account board size  
}


Player::~Player()
{
    // delete any heap members here
    //we can leave it empty for now since no new keyword 
}

void Player::getPlayerPos(objPos &returnPos) //getPlayerPos(postion1)   
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //where do i get the input -- how do i check for input 
    //not macui get char

    char input = mainGameMechsRef->getInput();
    
    //may need if input!=0 
    switch(input)     
    {
        case ' ':
            mainGameMechsRef->setExitTrue();
            break;
        case 'w':
            if(myDir != UP && myDir != DOWN) //if the direction in going isnt UP or Down then you are able to go UP
            {
                myDir = UP;
            }
            break;
        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
        case 's':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;

        default:
            break;
    }     

    mainGameMechsRef->clearInput(); 
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    //board size you can get from the gamemech

    switch (myDir)
        {
            case UP:  
                playerPos.y -= 1;
                break;
            case DOWN:
                playerPos.y += 1;
                break;
            case LEFT:
                playerPos.x -= 1;
                break;
            case RIGHT:
                playerPos.x += 1;
                break;
            default:
                break;
        }

    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    int widthX = boardSizeX - 2;
    int widthY = boardSizeY - 2;

    // Wrap around on the X-axis using the modulus operator
    playerPos.x = (((playerPos.x - 1) + widthX) % widthX) + 1; //(1-28)

    // Wrap around on the Y-axis using the modulus operator
    playerPos.y = (((playerPos.y - 1) + widthY) % widthY) + 1; //(1-13)


  //(1-28) -> when you use a modlous you are ranging it from 0 to the mod minus 1 
        //example % 20 will be (0-19)
        //so then if you want to increase the 


}

