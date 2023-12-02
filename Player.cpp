#include "Player.h"
#include "Food.h"


//player Class Constructor 
Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef; //set the reference to the GameMechs object 
    this->foodRef = foodRef; //Set the reference to the Food object
    myDir = STOP; //Initialize the player's direction to STOP (idle state)

   
    objPos tempPos; // Temporary variable to hold the initial position 

    // Set the initial position to the center of the game board
    // The symbol '@' represents the player
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@'); 
     
    playerPosList = new objPosArrayList(); // Create a new list to store the player's positions
    playerPosList->insertHead(tempPos); //tempPos is inserted at the "Head"/beginning of the playerPostList
}


//Play Class Deconstructor
Player::~Player()
{
    delete playerPosList; 
}

objPosArrayList* Player::getPlayerPos()   
{
    return playerPosList; //return a pointer to an objPosArrayList object 
}

void Player::updatePlayerDir()
{
    //get the user input using the GameMechs
    char input = mainGameMechsRef->getInput();
    
    //switch statement to handle input characters 
    switch(input)     
    {
        case ' ': //exit the game if spacebar is pressed 
            mainGameMechsRef->setExitTrue(); // Set the game exit flag to true to indicate the game should end.
            break;
        case 'w':
            // Change the direction to UP unless the current direction is already DOWN.
            // Prevents the snake from reversing on itself.
            if(myDir != UP && myDir != DOWN) 
            {
                myDir = UP;
            }
            break;
        case 'a':
            // Change the direction to LEFT unless the current direction is already RIGHT.
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
        case 's':
            // Change the direction to DOWN unless the current direction is already UP.
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case 'd':
            // Change the direction to RIGHT unless the current direction is already LEFT.
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;

        default:
            break;
    }     

    // Clear the input in the GameMechs object to prepare for the next input.
    mainGameMechsRef->clearInput(); 
}

void Player::movePlayer()
{
    //holds the position information of the current head
    objPos currentHead; 
    playerPosList->getHeadElement(currentHead);

    //holds the positions information of the generated food
    objPos foodPostion;
    foodRef->getFoodPos(foodPostion);

    //increase or decrease head movement depenedent on myDir from updatePlayerDir
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

    //initalize the board size
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    //initalize the width of the board, neglecting the boarder 
    int widthX = boardSizeX - 2;
    int widthY = boardSizeY - 2;

    // Wrap around on the X-axis using the modulus operator
    currentHead.x = (((currentHead.x - 1) + widthX) % widthX) + 1; //(1-28)
    // Wrap around on the Y-axis using the modulus operator
    currentHead.y = (((currentHead.y - 1) + widthY) % widthY) + 1; //(1-13)

    //insert the updated position at the head of the list
    playerPosList->insertHead(currentHead);

    //call the self collison 
    checkSelfCollision();

    //If the head pos collides with the food increment the score by one and generate a new food position 
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

    objPos currentHead; //holds the current head position 
    objPos currentPos; //holds the current position being checked 

    playerPosList->getHeadElement(currentHead); //get the current head position 

    for(int i = 2; i < playerPosList->getSize(); i++)
    {
        // Check if the head's position matches the current segment's position.
        if(currentHead.x == currentPos.x && currentHead.y == currentPos.y) {
            // If a match is found, it means the head has collided with the body.
            // Set the lose flag in the game mechanics to indicate the player has lost.
            mainGameMechsRef->setLoseFlag();
            // Also set the exit flag to true to indicate the game should end.
            mainGameMechsRef->setExitTrue();
            // Break the loop as the collision has been detected and handled.
            break;
        }
    }
}