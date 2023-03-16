#include "lab6.h"

int main(){
    Node *head;
    makeList(&head);

    int num = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    insertAtTail(head, &num);
    insertAtTail(head, &num2);
    insertAtTail(head, &num3);
    insertAtTail(head, &num4);
    insertAtTail(head, &num4);
    insertAtTail(head, &num4);
    insertAtTail(head, &num4);
    insertAtTail(head, &num4);

    int size = getSize(head);
    printf("Size: %d\n", size);

    int ele = *((int*)getAtIndex(head, 3));
    printf("%d\n", ele);

    int res = *((int*)removeFromHead(head));
    printf("%d\n", res);

    int s = getSize(head);
    printf("Size: %d\n", s);

    freeList(&head);
    int t = getSize(head);
    printf("Size: %d\n", t);


}
