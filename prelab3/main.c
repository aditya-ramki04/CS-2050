//gcc main.c pl3.c -Wall -Werror

#include "pl3.h"

int main(){

    double *array = createArray(12, sizeof(double));
    printf("%lf ", *array);

    //testing get size
    int res = getArraySize(array);
    printf("%d ", res);

    freeArray(array);
    

    return 0;
}
