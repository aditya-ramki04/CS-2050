#include "lab7.h"


int main(){
    Stack start = initStack();
    int startSize = getSize(start);
    printf("Starting size is: %d\n", startSize);

    int a = 5;
    int b = 10;
    int c = 50;
    int d = 100;

    pushStack(start, &a);
    pushStack(start, &b);
    pushStack(start, &c);
    pushStack(start, &d);

    int middleSize = getSize(start);
    printf("Middle size is: %d\n", middleSize);

    int ele = *((int*)peekStack(start));
    printf("%d\n", ele);

    popStack(start);

    int ele2 = *((int*)peekStack(start));
    printf("Element after popping stack: %d\n", ele2);

    int endSize = getSize(start);
    printf("End size is: %d\n", endSize);

    freeStack(start);
    int ele3 = *((int*)getAtIndex(start, 1));
    printf("Element at index 1: %d\n", ele3);



}
