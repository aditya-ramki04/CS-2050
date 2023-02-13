#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int empID, jobType;
 float salary;
} Employee;


Employee * readEmployeeArray(FILE *fp);
Employee * getEmployeeByID(Employee *, int empID);
int setEmpSalary(Employee *, int empID, float salary);
int getEmpSalary(Employee *, int empID, float *salary);
int setEmpJobType(Employee *, int empID, int job);
int getEmpJobType(Employee *, int empID, int *job);



//misc
int getArraySize(void *array);
void freeArray(Employee *r);
