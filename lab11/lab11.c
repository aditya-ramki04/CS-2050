#include "lab11.h"

//defines each node of bst (the value, and the left and right pointers)
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

//defines bst, and its root node and the size of the tree
struct BST {
    Node *root;
    int size;
};

//DONE
BST *initBST() {
    //inits tree and sets root node to null and size of tree to 0
    BST *tree = (BST *)malloc(sizeof(BST));
    //checks if malloc failed
    if(tree == NULL) return NULL;
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

//helper function for insert function DONE
Node * insertBSTHelper(Node* root, Node* node){
    //checks if node is null
    if (root == NULL) {
        return node;
    }
    //checks for if data is less than that of root data of subtree, and calls helper function
    if (node->data < root->data) {
        root->left = insertBSTHelper(root->left, node);
    }
    //checks for if data is more than that of root data of subtree, and calls helper function
    else {
        root->right = insertBSTHelper(root->right, node);
    }
    return root;
}
//DONE
int insertBST(BST *tree, int data){
    //creates new node and sets its data and left and right pointers
    Node * newNode = (Node*)malloc(sizeof(Node));
    //checks if malloc failed
    if(newNode == NULL) return 1;
    //set all node parameters accordingly
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    //calls insertBST helper function and sets it equal to root node of tree
    tree->root = insertBSTHelper(tree->root, newNode);
    //increases size of bst by 1
    tree->size++;

    return 0;
}

//DONE
int getSizeBST(BST *tree){
    //access BST size value
    return tree->size;
}

//DONE this function just traverses to the right most leaf node in BST which would be the max and returns that data
int getMaxBST(BST *tree){
    while(tree->root->right != NULL){
        tree->root = tree->root->right;
    }
    return tree->root->data;
}

//helper function for postOrderPrintBST DONE
void printHelper(Node* node){
    if(node != NULL){
    //checks for left subtree and prints out all those values
    printHelper(node->left);
    //checks for right subtree and prints out all those values
    printHelper(node->right);
    printf("%d ", node->data);
    }
}

//DONE
void postOrderPrintBST(BST *tree){
    //just calls helper function
    printHelper(tree->root);
}

//helper function for freeBST DONE
void freeHelper(Node *node){

    if (node != NULL) {
        //post order traversal of bst and frees every node
        freeHelper(node->left);
        freeHelper(node->right);
        free(node);
    }
}

//DONE
void freeBST(BST *tree){
    //frees all the nodes in the tree we allocated mem for by malloc
    freeHelper(tree->root);
    //frees BST mem allocated by malloc in init function
    free(tree);
}
