#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ssn, id;
} Employee;

typedef struct {
    Employee** idEmp;
    Employee** ssnEmp;
    int size;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee **, int);
Employee * findEmpBySSN(int, EmpDatabase);
Employee * findEmpByID(int, EmpDatabase);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);
