//gcc main.c lab3.c -Wall -Werror

#include "lab3.h"

int main(){
    char *source = strAlloc(5);
    char *dest = strAlloc(5);



    int size = strLen(source);
    printf("%d ", size);

    for(int i = 0; i < size; i++){
        source[i] = 'y';
    }

    int res = strCmp(source,dest);
    printf("%d ", res);

    return 0;
}
