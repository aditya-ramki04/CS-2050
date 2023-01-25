//gcc main.c prelab1.c -Wall -Werror

#include "prelab1.h"

int main(){
    int array[] = {4,66,4,5,8,9};
    int size = 6;
    int min,max,count;
    getArrayInfo(array,size,&min,&max,&count);
    printf("%d %d %d\n", min,max,count);
    return 0;
}
