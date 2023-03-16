#include "pl7.h"

int main(){
    Queue start = queueInit();
    int test = 10;
    int test2 = 20;
    int test3 = 30;
    enqueue(&test, start);
    enqueue(&test2, start);
    enqueue(&test3, start);

    // int ele2 = *((int*)dequeue(start));
    // printf("%d\n", ele2);

    // int ele3 = *((int*)dequeue(start));
    // printf("%d\n", ele3);

    freeQueue(start);

    int size = getQueueSize(start);
    printf("Size: %d\n", size);

}
