#include "pl11.h"

//inits struct
EmpDatabase createSearchableEmployeeDB() {
    //init the database and set root node to null and ec to 0
    EmpDatabase db;
    db.root = NULL;
    return db;
}

// Insert a new Employee into the EmpDatabase
EmpDatabase insertEmp(Employee* emp, EmpDatabase db) {
    // Create a new BST node for the Employee
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->emp = emp;
    newNode->left = NULL;
    newNode->right = NULL;

    //call helper function
    db.root = insertEMPHelper(db.root, newNode);
    return db;
}

//recursive helper function for insertEMP
Node* insertEMPHelper(Node* root, Node* node) {
    //checks if node is null
    if (root == NULL) {
        return node;
    }
    //checks for left subtree, and calls helper function
    if (node->emp->salary < root->emp->salary) {
        root->left = insertEMPHelper(root->left, node);
    }
    //checks for left subtree, and calls helper function
    else {
        root->right = insertEMPHelper(root->right, node);
    }
    return root;
}


int countEmpsInSalaryRange(int min, int max, EmpDatabase db){
    int count = 0;
    //start of with passing in root
    countSalaryRangeHelper(db.root, min, max, &count);
    return count;
}

void countSalaryRangeHelper(Node *node, int min, int max, int *count){
    //if root is null just return nothing
    if (node == NULL) {
        return;
    }
    //check if node is in range, if so increment count
    if (node->emp->salary >= min && node->emp->salary <= max) {
        (*count)++;
    }
    //check left subtree
    countSalaryRangeHelper(node->left, min, max, count);
    //check right subtree
    countSalaryRangeHelper(node->right, min, max, count);
}


//changed it to pass in root node
void freeEmpDatabase(Node *root) {
    if (root != NULL) {
        freeEmpDatabase(root->right);
        freeEmpDatabase(root->left);
        //frees employee struct
        free(root->emp);
        //frees node itself
        free(root);
    }
}
