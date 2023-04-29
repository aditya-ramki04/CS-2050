#include "lab11.h"


int main(){
    BST* tree = initBST();

    insertBST(tree, 4);
    insertBST(tree, 2);
    insertBST(tree, 5);
    insertBST(tree, 1);
    insertBST(tree, 3);
    insertBST(tree, 6);

    //check size
    printf("%d\n", getSizeBST(tree));

    //freeBST(tree);

    //check print
    postOrderPrintBST(tree);

    //check max
    printf("\nMax: %d\n", getMaxBST(tree));

    return 0;
}
