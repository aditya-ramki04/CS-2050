//gcc main.c lab4.c -Wall -Werror

#include "lab4.h"

int main(){

    InventoryItem *array = makeArray(8, sizeof(InventoryItem));
    int res = countWithStock(array, 0);
    printf("%d ", res);
    
}
