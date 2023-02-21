#include "lab4.h"

void * makeArray(int arraySize, int elementSize){
    int *array;
    //allocate memory for array of size arraySize, where each element is size elementSize, plus sizeof(int) for storing the arraySize value
    if((array=malloc((arraySize*elementSize)+sizeof(int)))){
        //store size in first element
    array[0] = arraySize;
    //increments array + 1 so the size is now stored in ((int*)array)[-1]
    return (void *)(array+1);
    }
    //if malloc fails
    else return NULL;
}

int countWithStock(InventoryItem *items, int stockCount){
    int count = 0; //declare count variable
    //iteriate through array, and checks if each item's stockCount is equal to the stockCount we passed in
    for(int i = 0; i < getSize(items); i++){
        if(items->stockCount == stockCount){
            //if true for logic stated in above comment, increase count variable
            count++;
        }
    }
    return count;
}

int getSize(void *array){
    //returns int value at the [-1] position of array where size is stored from makeArray
   return ((int*)array)[-1];
}

void freeArray(void *array){
    //frees array from starting position allocated by makeArray
    free(((int*)array)-1);
    //sets pointer to NULL
    array = NULL;
}
