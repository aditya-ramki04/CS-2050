#include "lab1.h"

int getAverage(int array[], int size, float *result){
    //will return failure error code if array is empty
    if(size == 0){
        return 1;
    }
    //gets average of array if array isn't empty, and returns success error code
    else{
    *result = 0;

    for(int i = 0; i < size; i++){
        //gets sum of array
        *result+=array[i];
    }
    //divides sum by size to get average
    *result = *result/size;
    return 0;
    }

}

int sumOdd(int array[], int size, int *result){
    //will return failure error code if array is empty
    if(size == 0){
        return 1;
    }
    //sums all odd with modulus and returns success error code
    else{
    *result = 0;

    for(int i = 0; i < size; i++){
        //checks if each element is odd, and adds it to total sum if it is
        if(array[i]%2 == 1 || array[i]%2 == -1){
            *result += array[i];
        }
    }
    if(*result == 0){
        return 1;
    }
    else{
        return 0;
    }
    }

}
