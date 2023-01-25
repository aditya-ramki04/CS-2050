#include "prelab1.h"

void getArrayInfo(int *arr, int size, int *min, int *max, int *count){
    *min = arr[0];
    *max = arr[0];
    int c = 1; //counter
    for(int i = 1; i < size; i++){
        int j = 0;
        //checks current value with min value
        if(arr[i] < *min){
            *min = arr[i];
        }
        //checks current value with max value
        if(arr[i] > *max){
            *max = arr[i];
        }
    //second loop, checks each value with whole array
    for(j = 0; j < i; j++){
        //if its equal, exit array
        if(arr[i] == arr[j]) break;
    }
    //if indexes are equal, then increase count
    if(i == j) c++;
    }
    *count = c;

    return;
}
