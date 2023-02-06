#include "pl2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length){
    int size;
    //declare float array pointer
    float *p;

    //finds how many floats in file from first integer
    fscanf(fptr,"%d", &size);
    *length = size;

    //if malloc works, allocate memory for array of size mentioned above
    if((p = malloc(size * sizeof(float)))){ 
        //scans float from file and sets it to array
        for(int i = 0; i < size; i++){
        fscanf(fptr,"%f", &p[i]);
        }
        //returns float array pointer
        return p;
    }
    else{
        return NULL;
    }
}

void freeFloatArray(float **p){
    //frees array and sets it to null
    free(*p);
    *p = NULL;
}
