#include "pl7.h"

//done O(1)
int getQueueErrorCode(Queue init){
    if(init.info == NULL) return 1;
    else{
        return (init.info)->ec;
    }
}

//done O(1)
Queue queueInit(){
    Queue init;
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

//done O(1)
int enqueue(void *data, Queue init){
    //create node
    Node *new;
    new = malloc(sizeof(Node));
    if(new == NULL) return 1;
    new->data = data;
    new->next = NULL;

    //access queue info
    queueInfo *in = init.info;
    //if queue empty, make front and rear equal to node
    if(in->size == 0){
        in->front = new;
        in->rear = new;
        in->ec = 0;
    }
    //make rear->next now point to new node linking the new node to the queue, then make rear equal to the new node
    else{
        in->rear->next = new;
        in->rear = new;
        in->ec = 0;
    }
    //increase size by 1
    in->size = (in->size) + 1;
    return 0;
}
//done O(1)
void * dequeue(Queue init){
    //access queue info
    queueInfo *in = init.info;
    //if queue empty return null
    if(in->size == 0){
        in->ec = 2;
        return NULL;
    }
    //if queue has 1 node
    else if(in->size == 1){
        Node* temp = in->front;
        void* data = in->front->data;
        in->size = (in->size) - 1;
        free(temp);
        return data;
    }
    //if queue has more than 1 node
    else{
        Node* temp = in->front;
        void* data = in->front->data;
        in->front = in->front->next;
        in->size = (in->size) - 1;
        free(temp);
        return data;
    }
}
//done O(1)
int getQueueSize(Queue init){
    return init.info->size;
}

//done O(n)
void freeQueue(Queue init){
    if(getQueueSize(init) == 0) return;

   //creates temp to access end of list
    Node *temp = init.info->front;
    //traverse list
    while((init.info->front) != NULL){
        //frees each list element
        temp = init.info->front;
        init.info->front = (init.info->front)->next;
        free(temp);
    }
    init.info->size = 0;
}
