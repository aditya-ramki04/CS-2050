#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node {
Node *next;
void *data;
};

typedef struct {
Node *front, *rear;
int ec, size;
}queueInfo;

typedef struct { //pointerWrapper
queueInfo *info;
}Queue;


int getQueueErrorCode(Queue);
Queue queueInit();
int enqueue(void *, Queue);
void * dequeue(Queue);
int getQueueSize(Queue);
void freeQueue(Queue);
