#include "lab5.h"

int main(){
    Node *head;
    makeList(&head);

    int num = 10;
    insertAtTail(&head, &num);
    insertAtTail(&head, &num);
    insertAtTail(&head, &num);
    insertAtTail(&head, &num);

    removeFromHead(&head);
    removeFromHead(&head);

    freeList(&head);
    int size = getSize(head);
    printf("Size: %d\n", size);




}
