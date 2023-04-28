#include <stdio.h>
#include <stdlib.h>

//ADTS
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
}PQueue;

//Prototypes
int pqGetErrorCode(PQueue);
Queue pqInit();
int pqInsert(void *, int, PQueue);
void * pqRemoveMax(PQueue);
int pqGetSize(PQueue);
void pqFree(PQueue) ;
