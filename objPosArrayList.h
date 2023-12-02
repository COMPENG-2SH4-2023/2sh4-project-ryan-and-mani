#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 256

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList; //object position array list
        int listSize; //amount of content in the list 
        int arrayCapacity; //capacity of the aList

    public:
        objPosArrayList(); //constuctor 
        ~objPosArrayList(); //deconstructor

        int getSize(); //getList size
        void insertHead(objPos thisPos); //insert head at beginning of list
        void insertTail(objPos thisPos); //insert last element of list
        void removeHead(); //remove head at beginning of list
        void removeTail(); //remove tail at end of list
        
        void getHeadElement(objPos &returnPos); //get position of the head 
        void getTailElement(objPos &returnPos); //get position of the tail
        void getElement(objPos &returnPos, int index); //get snake body element at a given index
};

#endif