#include "lab7.h"

//node struct
typedef struct Node Node;
struct Node {
Node *next;
void *data;
};

//stack info struct
struct Info{
Node *top;
int size;
};

//done
Stack initStack(){
    //initalizes stack
    Stack init;
    //allocate memory for info inside stack
    init.info = malloc(sizeof(Info));
    //print error code if malloc failed
    if(init.info == NULL) {
        printf("Malloc Failed");
    }
    //sets top to NULL, and size to 0
    else{
        Info *in = init.info;
        in->top = NULL;
        in->size = 0;
    }
    //returns stack
    return init;
}

//done
int getSize(Stack s){
    //since its O(1) I made a size variable and returned size
    return s.info->size;
}

//done
void * peekStack(Stack s){
    //returns the top node's data in the stack
    return s.info->top->data;
}

//done
int pushStack(Stack s, void *data){
    //allocates memory for node, sets node data to data passed in, and next to NULL
    Node *new;
    new = malloc(sizeof(Node));
    if(new == NULL) return 1;
    new->data = data;
    new->next = NULL;

    //access stack info
    Info *in = s.info;

    //if stack empty, make top equal to the new node created
    if(in->size == 0){
        in->top = new;
    }
    //push node into stack, make top equal to new node pushed in
    else{
        new->next = in->top;
        in->top = new;
    }
    //increment size by 1 for new node created
    in->size += 1;
    return 0;
}

//done
void * popStack(Stack s){
    //access stack info
    Info *in = s.info;

    //if stack empty print error message and return null
    if(in->size == 0){
        printf("Stack is empty.\n");
        return NULL;
    }
    //if stack has one node, set data of the node to variable, free top, and return data (and decrease size by 1)
    else if(in->size == 1){
        Node *temp = in->top;
        void *data = in->top->data;
        in->size -= 1;
        free(temp);
        return data;
    }
    //if stack has more than one node, set data of top node to variable, traverse stack by one, free original top, and return data (and decrease size by 1)
    else{
        Node *temp = in->top;
        void *data = in->top->data;
        in->top = in->top->next;
        in->size -= 1;
        free(temp);
        return data;
        }
}

//done
void * getAtIndex(Stack s, int index){
    Info *in = s.info;
    //if stack empty print error message and return null
    if(in->size == 0){
        printf("Stack is empty.\n");
        return NULL;
    }

    //check if index is a valid index (greater than 0 and less than stack size by 1)
    if(index >= 0 && index < getSize(s)){
        //iterate through stack till it reaches node at specified index
        for(int i = 0; i < index; i++){
            in->top = in->top->next;
        }
        //return node's data
        return in->top->data;
    }
    //if index is not valid return null
    return NULL;
}

//done
void freeStack(Stack s){
    Info *in = s.info;
    //if stack is empty quit function
    if(getSize(s) == 0) return;

    //set temp variable to top of stack node
    Node *temp = in->top;

    //iterate through stack and free every node the user pushed in the stack
    while(in->top != NULL){
        temp = in->top;
        in->top = in->top->next;
        free(temp);
    }
    //set size of stack equal to 0
    in->size = 0;
}
