#include "objPos.h"

objPos::objPos() //default constructor 
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

objPos::objPos(objPos &o) //copy constructor 
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char sym) //specialized constructor 
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::setObjPos(objPos o) //sending an instance of the object 
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym) //overloaded with all feilds
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::getObjPos(objPos &returnPos) //pass by reference where you provide an empty objPos where obj instance will write its own x,y,symbol and return it 
{
    returnPos.setObjPos(x, y, symbol);
}

char objPos::getSymbol()
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) //checks if x,y cord of object is equal x and y from feild 
{
    return (refPos->x == x && refPos->y == y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}
