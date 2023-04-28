#include "lab9.h"

int main(){
     Flight *array = makeArray(5, sizeof(Flight));
     Flight f1 = {1,1200,50};
     Flight f2 = {2,2300,120};
     Flight f3 = {3,2400,270};
     Flight f4 = {4,5500,550};
     Flight f5 = {5,7600,770};

     array[0] = f1;
     array[1] = f2;
     array[2] = f3;
     array[3] = f4;
     array[4] = f5;

     printf("Size: %d\n", getSize(array));

     int res = searchFlights(array, &f3);
     printf("%d\n", res);

     freeArray(array);

     int res2 = searchFlights(array, &f1);
     printf("%d\n", res2);

}
