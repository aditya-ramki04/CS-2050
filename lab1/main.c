//gcc main.c lab1.c -Wall -Werror
#include "lab1.h"

int main(){

    int arr[] = {2,2,2,2,2,2};
    int size = 6;
    int result = 0;


   int res = sumOdd(arr,size,&result);
    printf("%d\n", result);
    printf("Success: %d\n", res);
    return 0;
}
