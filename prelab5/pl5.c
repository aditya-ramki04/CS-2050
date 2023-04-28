#include "pl5.h"

List * initList(int* ec){
    List *p;
    if(!(p = malloc(sizeof(List)))){
        return NULL;
    }
    else{
        p->next = NULL;
        ec = 0;
        return p;
    }
}

List * insertAtHead(int val, List* head, int* ec){
    List *new;
    new = malloc(sizeof(List));
    if(new){
        new->object = val;
        new->next = head;
        ec = 0;
    }
    return new;
}

int getAtIndex(int index, List* head){
    List *temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    return (temp->object);
}

int getListLength(List* head){
    List *temp = head;
    int count = 0;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

List * freeList(List* head){
   List *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
    return NULL;
}
