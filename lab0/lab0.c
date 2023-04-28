#include "lab0.h"

//iterates through each element in array, and increases count if it is equal to the query number, and returns the count
int countOccurrences(int size, int testArr[], int query){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(testArr[i] == query){
            count++;
        }
    }

    return count;
}
