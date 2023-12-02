#include "objPosArrayList.h"

// Constructor for objPosArrayList
objPosArrayList::objPosArrayList() {
    arrayCapacity = ARRAY_MAX_CAP;  // Set the capacity of the array to a predefined maximum
    listSize = 0;                   // Initialize the current size of the list to 0
    aList = new objPos[arrayCapacity]; // Dynamically allocate memory for 'arrayCapacity' number of objPos objects
}

// Destructor for objPosArrayList
objPosArrayList::~objPosArrayList() {
    delete[] aList;  // Delete the dynamically allocated array to prevent memory leaks
}

// Method to get the current size of the list
int objPosArrayList::getSize() {
    return listSize;  // Return the current number of meaningful elements in the list
}

// Method to insert an element at the head (beginning) of the list
void objPosArrayList::insertHead(objPos thisPos) {
    // Check if the list has reached its capacity
    if (listSize == arrayCapacity) {
        return;  // Do not insert if the list is full
    }

    // Shift all existing elements one position to the right to make room at the head
    for (int i = listSize; i > 0; i--) {
        aList[i].setObjPos(aList[i - 1]);
    }

    // Insert the new element at the head of the list
    aList[0].setObjPos(thisPos);
    listSize++;  // Increment the size of the list
}

// Method to insert an element at the tail (end) of the list
void objPosArrayList::insertTail(objPos thisPos) {
    // Insert the new element at the next available position at the end of the list
    aList[listSize++].setObjPos(thisPos);
}

// Method to remove an element from the head of the list
void objPosArrayList::removeHead() {
    // Shift all elements one position to the left, effectively removing the head
    for (int i = 0; i < listSize - 1; i++) {
        aList[i].setObjPos(aList[i + 1]);
    }
    listSize--;  // Decrement the size of the list
}

// Method to remove an element from the tail of the list
void objPosArrayList::removeTail() {
    listSize--;  // Simply decrement the size of the list, effectively removing the tail element
}

// Method to get the element at the head of the list
void objPosArrayList::getHeadElement(objPos &returnPos) {
    returnPos.setObjPos(aList[0]);  // Return the first element of the list
}

// Method to get the element at the tail of the list
void objPosArrayList::getTailElement(objPos &returnPos) {
    returnPos.setObjPos(aList[listSize - 1]);  // Return the last meaningful element of the list
}

// Method to get an element at a specific index
void objPosArrayList::getElement(objPos &returnPos, int index) {
    // Check if the index is within the bounds of the list
    if (index >= 0 && index < listSize) {
        returnPos.setObjPos(aList[index]);  // Set the returnPos to the element at the specified index
    }
    // You might want to handle the case where the index is out of bounds
}
