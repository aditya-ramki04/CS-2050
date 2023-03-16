#include "lab5.h"

int makeList(Node **list){
    //initalizes empty list pointer
    *list = NULL;
    return 0;
}

int getSize(Node *list){
    //sets count variable
    int count = 0;
    //traverses list and counts 1 for each list element
    while(list != NULL){
        list = list->next;
        count++;
    }
    //returns count
    return count;
}

int insertAtTail(Node **list, void *data){\
    //create new node to add to end
    Node *new;
    new = malloc(sizeof(Node));

    //creates temp to access end of list
    Node *temp = *list;

    if(new){
        new->data = data;
        new->next = NULL;

        //if list is empty make first node the new node we created
        if((*list) == NULL){
            (*list) = new;
            return 0;
        }
        //if list is not empty traverse to the end
        while(temp->next != NULL){
            temp = temp->next;
        }
        //add new node to the end of the list
        temp->next = new;
        return 0;
    }
    //if malloc doesnt work
    else{
        return 1;
    }
}

void * removeFromHead(Node **list){
    //returns null if list is empty
    if((*list) == NULL){
        return NULL;
    }
    //if list is not empty, set head data value to a temp value
     void * res = (void*)((*list)->data);
     //traverse head by one so the next node is now the head
    *list = (*list)->next;

    //return the temp value of the original head data
    return res;
}

void freeList(Node **list){
    //creates temp to access end of list
    Node *temp = *list;
    //traverse list
    while((*list) != NULL){
        //frees each list element
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}
