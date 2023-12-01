#include "Player.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    this->foodRef = foodRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos; //initial position 
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@'); //initalze position -> may need to change to take into account board size 
     
    playerPosList = new objPosArrayList(); //dynamically allocate memory for an objPosArrayList object (calls constructor) and save its adress to playerPosList
    playerPosList->insertHead(tempPos); //tempPos is inserted at the "Head"/beginning of the playerPostList
}


Player::~Player()
{
    // delete any heap members here
    //we can leave it empty for now since no new keyword 
    delete playerPosList; //dont need square brackets since we didnt use new[]
}

objPosArrayList* Player::getPlayerPos()   
{
    return playerPosList; 
    //instead of void, this will return a pointer to an objPosArrayList object 
    //playerPosList is a pointer to an instance of objPosArrayList  
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

    //holds the position information of the current head
    objPos currentHead; 
    playerPosList->getHeadElement(currentHead);

    objPos foodPostion;
    foodRef->getFoodPos(foodPostion);

    switch (myDir)
        {
            case UP:  
                currentHead.y -= 1;
                break;
            case DOWN:
                currentHead.y += 1;
                break;
            case LEFT:
                currentHead.x -= 1;
                break;
            case RIGHT:
                currentHead.x += 1;
                break;
            default:
                break;
        }

    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    int widthX = boardSizeX - 2;
    int widthY = boardSizeY - 2;

    // Wrap around on the X-axis using the modulus operator
    currentHead.x = (((currentHead.x - 1) + widthX) % widthX) + 1; //(1-28)
    // Wrap around on the Y-axis using the modulus operator
    currentHead.y = (((currentHead.y - 1) + widthY) % widthY) + 1; //(1-13)

    //insert the updated position at the head of the lisgt
    playerPosList->insertHead(currentHead);

    checkSelfCollision();

    if(currentHead.x == foodPostion.x && currentHead.y == foodPostion.y)
    {
        mainGameMechsRef->incrementScore(1);
        foodRef->generateFood(playerPosList);
    }
    else
    {
    //then, remove tail at the end of the list 
    playerPosList->removeTail();
    }  
}


bool Player::checkSelfCollision()
{
    //if collided set lose flag and and exit flag to true (through GM)
    //this will break program loop and end the game
    objPos currentHead;
    objPos currentPos;

    playerPosList->getHeadElement(currentHead); 

    for(int i = 2; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(currentPos,i);
        if(currentHead.x == currentPos.x && currentHead.y == currentPos.y)
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }
}