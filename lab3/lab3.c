#include "lab3.h"

char * strAlloc(int size){
    int *array;
    //allocates memory for char array of whatever size is passed in argument plus int for storing the size
    if((array=malloc((size*sizeof(char))+sizeof(int)))){
        //stores size in first element
    array[0] = size;
    //iterates array + 1 so the size is now stored in ((int*)array)[-1]
    return (char *)(array+1);
    }
    //if malloc fails
    else{
        return NULL;
    }
}
int strLen(char *str){
    //returns int value at the [-1] position of array where size is stored from strAlloc
    return ((int*)str)[-1];
}

void strCpy(char *source, char *dest){
    //iterates through array
    for(int i = 0; i < strLen(source); i++){
        //sets each element of dest char array to value of coressponding source array
        dest[i] = source[i];
    }
}

int strCmp(char *source, char *dest){
    //iterates through array
    for(int i = 0; i < strLen(source); i++){
        //checks if each element of source is equal to element of dest, and if not return 0 code representing the strings are not equal
        if(source[i] != dest[i]){
            return 0;
        }
    }
    return 1;
}

void strFree(char *str){
    //frees array from starting position allocated by strAlloc
    free(((int*)str)-1);
    //sets pointer to null
    str = NULL;
}
