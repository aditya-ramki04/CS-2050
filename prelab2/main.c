//gcc main.c pl2.c -Wall -Werror
#include "pl2.h"

int main(){

    FILE *fptr;
    fptr = fopen("file.txt", "r");

    int length;
    float *array;
    array = readFloatFileIntoArray(fptr,&length);

    //testing if function works by printing out values in returned array
    for(int i = 0; i < length; i++){
        printf("%f ", array[i]);
    }

    freeFloatArray(&array);
    fclose(fptr);

    return 0;
}
