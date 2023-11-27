#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

//objPos myPos;

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

    //myPos.setObjPos(2,3,'@')


    myGM = new GameMechs(26,13);
    myPlayer = new Player(myGM);
    objPos myPlayerO;
    myPlayer->getPlayerPos(myPlayerO);

    myFood = new Food(myGM);
    myFood->generateFood(myPlayerO);

}

void GetInput(void)
{

   //preformed in the the player class updatePlayerDir
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
    //Should clear input be here instead ???

  
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    objPos tempPos;  
    myPlayer->getPlayerPos(tempPos);

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y,tempPos.symbol);

    objPos foodPos;
    myFood->getFoodPos(foodPos);


   int i,j;

   for (i = 0; i <= myGM->getBoardSizeY()-1; i++){
        for (j = 0; j <= myGM->getBoardSizeX()-1; j++){
            //Frame 
            if (i == 0 || i == myGM->getBoardSizeY()-1 || j == 0 || j == myGM->getBoardSizeX()-1){ //for placing down the border
                MacUILib_printf("#");
            }
            else if((i == tempPos.y) && (j == tempPos.x)){ //for placing down the player 
                MacUILib_printf("%c", tempPos.symbol); 
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

        //MacUILib_printf("The direction of movmeent: %s", playerPos.myDir);

  
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    //Remove heap instances 
    delete myGM;
    delete myPlayer;
    delete myFood;
}
