#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[arrayCapacity]; //200 elements on the heao 
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //[] deletes every element in the array -> without it only does the first element 
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //check if list size is equal to capacity 
    if(listSize == arrayCapacity)
    {
        return;
    }

    //shuffle elements one index to the right to free space at index zero to be filled with new element 
    //listSize size is the amount of content in the list which is one larger than the amount of elements 
    for(int i = listSize; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]); // this will shuffle all the elements towards the tail
    }
    aList[0].setObjPos(thisPos); //insert thisPos to the first element which holds an x,y,symbol
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize++].setObjPos(thisPos);
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < listSize -1; i++)
    {
        aList[i].setObjPos(aList[i+1]);
    } 
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}