#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer; 

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

    myGM = new GameMechs(26,13);
    myPlayer = new Player(myGM);

}

void GetInput(void)
{

   
}

void RunLogic(void)
{

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    objPos tempPos;  
    myPlayer->getPlayerPos(tempPos);

    MacUILib_printf("BoardSize: %d%d, Player Pos: <%d %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y,tempPos.symbol);




   int i,j;

   for (i = 0; i <= myGM->getBoardSizeY-1; i++){
        for (j = 0; j <= myGM->getBoardSizeX-1; j++){
            //Frame 
            if (i == 0 || i == myGM->getBoardSizeY-1 || j == 0 || j == myGM->getBoardSizeX-1){
                MacUILib_printf("#");
            }
            else if((i == myObjPos.y) && (j == myObjPos.x)){ //Ryan 
                MacUILib_printf("%c", myObjPos.symbol);//Ryan 
            }
            else {
                MacUILib_printf(" ");
            }
        }
                  MacUILib_printf("\n");
 
        } 
   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
