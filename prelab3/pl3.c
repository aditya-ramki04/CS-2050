#include "pl3.h"

void * createArray(int n, int dataTypeSize){
   int *array;
    array=malloc((n*dataTypeSize)+sizeof(int));
    array=((int*)array)+1; //make hidden space for size
    ((int*)array)[-1]=n;//set size of array
    return array;
}

int getArraySize(void *array){
   return ((int*)array)[-1];
}

void freeArray(void *array){
   free(((int*)array)-1);
   array = NULL;
}
