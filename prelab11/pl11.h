#include <stdio.h>
#include <stdlib.h>



typedef struct {
  int salary;
} Employee;

typedef struct Node {
    Employee* emp;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
  Node *root;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(); // Just inits your struct
EmpDatabase insertEmp(Employee *, EmpDatabase);
Node* insertEMPHelper(Node* , Node* );
int countEmpsInSalaryRange(int min, int max, EmpDatabase);
void countSalaryRangeHelper(Node *, int, int, int*);
void freeEmpDatabase(Node *);
