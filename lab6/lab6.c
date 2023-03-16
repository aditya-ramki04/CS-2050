#include "lab6.h"

//done
int makeList(Node **list){
    *list = malloc(sizeof(Node));
    if(*list){
        (*list)->data = NULL;
        (*list)->next = NULL;
        return 0;
    }
    return 1;
}

//done
int getSize(Node *list){
    list = list->next;
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

//done
 void * getAtIndex(Node *list, int index){
    list = list->next;
    if(index >= 0 && index <= getSize(list)){
        for(int i = 0; i < index; i++){
            list = list->next;
        }
        return list->data;
    }
    return NULL;
}

//done
int insertAtTail(Node *list, void *data){
   //create new node to add to end
    Node *new;
    new = malloc(sizeof(Node));

    if(new){
        //add data to new node
        new->data = data;
        new->next = NULL;

        //traverse to the end of list
        while(list->next != NULL){
            list = list->next;
        }
        //add new node to the end of the list
        list->next = new;
        return 0;
    }
    //if malloc doesnt work
    else{
        return 1;
    }
}

//done
void * removeFromHead(Node *list){
    //returns null if list is empty
    if(getSize(list) == 0){
        return NULL;
    }
    //if list is not empty, set index 0 data value to a temp value
     void * res = list->next->data;
     //make dummy node point to the next next node
    list->next = list->next->next;
    //return the temp value of the original index 0 data
    return res;
}

//done
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
