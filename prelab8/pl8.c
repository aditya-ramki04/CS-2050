#include "pl8.h"

int pqGetErrorCode(PQueue init){
    if(init.info == NULL) return 1;
    else{
        return (init.info)->ec;
    }
}

Queue pqInit(){
    PQueue init;
    init.info = malloc(sizeof(queueInfo));

    if(init.info == NULL) {
        printf("Malloc Failed");
    }
    else{
        queueInfo *in = init.info;
        in->front = NULL;
        in->rear = NULL;
        in->ec = 0;
        in->size = 0;
    }
    return init;
}
