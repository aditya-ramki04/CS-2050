//gcc main.c lab2.c -Wall -Werror
#include "lab2.h"

int main(){
    int size = 5;
    int *array;

    makeArray(&array, size);
    initArray(array, size);
    multiplyPositive(array, size, 5);
    freeArray(&array);

}
