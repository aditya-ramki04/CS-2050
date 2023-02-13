//gcc main.c pl4.c -Wall -Werror
#include "pl4.h"


int main(){
    FILE *fptr;
    fptr = fopen("records.txt", "r");

    Employee *records = readEmployeeArray(fptr);
    Employee * person = getEmployeeByID(records, 18);
    printf("%f ", person->salary);

    setEmpSalary(records, 18, 12.00);

    float salary;
    getEmpSalary(records, 18, &salary);
    //test
    printf("%f ", salary);

    setEmpJobType(records, 18, 8);
    int job;
    getEmpJobType(records,18,&job);
    //test
    printf("%d ", job);

    freeArray(records);
    //test
    printf("%f ", records[0].salary);

    return 0;
}
