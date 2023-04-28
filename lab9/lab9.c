#include "lab9.h"
//helper for binary search
int searchFlightsHelper(Flight *array, Flight *query, int left, int right);

//done
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

//done
int getSize(void *array){
    //returns int value at the [-1] position of array where size is stored from makeArray
   return ((int*)array)[-1];
}

int searchFlightsHelper(Flight *array, Flight *query, int left, int right){
    //returns error code of -1 if flight isn't found
    if(left > right){
        return -1;
    }
    //sets mid value from left and right values passed in
    int mid = (left + right) / 2;

    //using compareFlights, check if the flights is before or after query Flight using distance value using conditionals
    if(compareFlights(&array[mid], query) == 0){ //if equal return index (mid)
        return mid;
    }
    else if(compareFlights(&array[mid], query) < 0){ //if less, pass in the midpoint + 1 as the left value and run again
        return searchFlightsHelper(array, query, mid + 1, right);
    }
    else{//if more, pass in the midpoint - 1 as the right value and run again
        return searchFlightsHelper(array, query, left, mid - 1);
    }
}

int searchFlights(Flight *array, Flight *query){
    //returns whatever value is returned from helper function
    return searchFlightsHelper(array, query, 0, getSize(array) - 1);
}

//done
int compareFlights(Flight *a, Flight *b){
    if(a->distance < b->distance){ //a<b return negative number
        return -1;

    }
    else if(a->distance > b->distance){ //a>b return positive number
        return 1;
    }
    else{ //if they are equal
        return 0;
    }
}

void freeArray(void *array){
    //frees array from starting position allocated by makeArray
    free(((int*)array)-1);
    //sets pointer to NULL
    array = NULL;
}
