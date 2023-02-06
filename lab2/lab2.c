#include "lab2.h"

int makeArray(int **array, int size){
    //allocates memory to *array, which is being passed by reference with ** to main
    if((*array = malloc(size * sizeof(int)))){
       return 0;
    }
    //if malloc doesn't work return error code 1 for failure
    else{
        return 1;
    }
}

void initArray(int *array, int size){
    //sets all elements of array to 0
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
}

int multiplyPositive(int *array, int size, int multiplicand){
    int count = 0;
    for(int i = 0; i < size; i++){
        //checks if element is positive
        if(array[i] > 0){
            //multiplies element by mutliplicand and sets that value to array[i]
            array[i] = (array[i] * multiplicand);
            //increments count if we changed a value in the array
            count++;
        }
    }
    return count;
}

void freeArray(int **array){
    //free's array and sets the pointer to null
    free(*array);
    *array = NULL;
}
