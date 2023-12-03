#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

//Pointer Instances for 3 classes:
GameMechs* myGM;
Player* myPlayer; 
Food* myFood; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{
    Initialize();


    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


    //Memory Allocation for 3 instances
    myGM = new GameMechs(26,13); //Board Size 
    myFood = new Food(myGM);   
    myPlayer = new Player(myGM, myFood);

    myFood->generateFood(myPlayer->getPlayerPos()); //Generate the first food on the board 


}

void GetInput(void)
{
   //preformed in the the player class updatePlayerDir 
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer();
    

    //myGM->clearInput(); saw in the video idk if we need 
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 



    bool drawn;

    // objPos tempPos;  
    // myPlayer->getPlayerPos(tempPos);

    objPosArrayList* playerBody = myPlayer->getPlayerPos(); //playerBody is the entire playerPosArrayList
    objPos tempBody;
    
    objPos foodPos;
    myFood->getFoodPos(foodPos);


   int i,j;

   for (i = 0; i <= myGM->getBoardSizeY()-1; i++){ //j is rows i is cols
        for (j = 0; j <= myGM->getBoardSizeX()-1; j++){

            drawn = false;

            // else if((i == tempPos.y) && (j == tempPos.x)){ //for placing down the player 
            //     MacUILib_printf("%c", tempPos.symbol); 
            // }
            
            for(int k = 0; k < playerBody->getSize(); k++) //iterate through every element in the list 
            {
                playerBody->getElement(tempBody,k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn)
            {
                continue; //if player body was drawn dont draw, dont draw anything below 
            }

            //Frame -> needs to be below? 
            if (i == 0 || i == myGM->getBoardSizeY()-1 || j == 0 || j == myGM->getBoardSizeX()-1){ //for placing down the border
                MacUILib_printf("#");
            }

           else if ((i == foodPos.y) && (j == foodPos.x))
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else {
                MacUILib_printf(" ");
            }
        }
                  MacUILib_printf("\n");
 
        } 

        //all print functions
        MacUILib_printf("Score %d\n", myGM->getScore());

        MacUILib_printf("Player Positions:\n");

        playerBody->getElement(tempBody,0);
        MacUILib_printf("<%d %d> ",tempBody.x,tempBody.y);

        MacUILib_printf("\nFood Pos: <%d %d>\n",foodPos.x, foodPos.y);




}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

        if(myGM->getExitFlagStatus() == true && myGM->getLoseFlagStatus() == false) //End Message if player uses exit button (space)
        {
            MacUILib_printf("Game Ended!\n");
            MacUILib_printf("Score: %d\n", myGM->getScore());  
        }

        if(myGM->getLoseFlagStatus()) //End message if self collision happens 
        {
            MacUILib_printf("Game Over! You lose.\n");
            MacUILib_printf("Score: %d\n", myGM->getScore());
        }

    MacUILib_uninit();

    
    //Remove heap instances 
    delete myGM;
    delete myPlayer;
    delete myFood;
}
