#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5,5,'*'); //initalze position -> may need to change to take into account board size  
}


Player::~Player()
{
    // delete any heap members here
    //we can leave it empty for now since no new keyword 
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //where do i get the input -- how do i check for input 
    //not macui get char

    switch(mainGameMechsRef->getInput())     
    {
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

    //need wrap around 
    if (playerPos.x == mainGameMechsRef->getBoardSizeX)
    {
        playerPos.x = (playerPos % (mainGameMechsRef->getBoardSizeX) -2 ) + 1;
    }
    if (playerPos.y == mainGameMechsRef->getBoardSizeY)
    {
        playerPos.y = (playerPos % (mainGameMechsRef->getBoardSizeY) - 2) + 1;
    }

}

