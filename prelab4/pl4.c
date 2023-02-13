#include "pl4.h"

Employee * readEmployeeArray(FILE *fp){
    int size;
    int *p;

    fscanf(fp,"%d", &size);
    p = malloc((size*sizeof(Employee))+sizeof(int));
    p[0] = size;
    p++;

    Employee *pp = (void *)p;


    for(int i = 0; i < size; i++){
        fscanf(fp, "%d %d %f", &(pp[i].empID), &(pp[i].jobType), &(pp[i].salary));
    }

    return pp;
}

Employee * getEmployeeByID(Employee *r, int empID){
    Employee *res = NULL;
    for(int i = 0; i < getArraySize(r); i++){
        if(r[i].empID == empID) res = &r[i];
    }
    if(res!=NULL) return res;
    else return NULL;
}

int setEmpSalary(Employee *r, int empID, float salary){
    Employee * person = getEmployeeByID(r, empID);
    if(person == NULL) return 1;
    else{
        person->salary = salary;
        return 0;
    }
}

int getEmpSalary(Employee *r, int empID, float *salary){
    Employee * person = getEmployeeByID(r, empID);
    if(person == NULL) return 1;
    else{
        *salary = person->salary;
        return 0;
    }
}

int setEmpJobType(Employee *r, int empID, int job){
    Employee * person = getEmployeeByID(r, empID);
    if(person == NULL) return 1;
    else{
        person->jobType = job;
        return 0;
    }
}

int getEmpJobType(Employee *r, int empID, int *job){
    Employee * person = getEmployeeByID(r, empID);
    if(person == NULL) return 1;
    else{
        *job = person->jobType;
        return 0;
    }
}
int getArraySize(void *array){
   return ((int*)array)[-1];
}

void freeArray(Employee *r){
    free(((int*)r)-1);
    r = NULL;
}
