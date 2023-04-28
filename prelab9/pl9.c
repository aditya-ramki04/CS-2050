#include "pl9.h"

EmpDatabase createSearchableEmployeeDB(Employee ** employees, int N){

    EmpDatabase db;
    db.size = N;

    //allocate mem for array of pointers to emp structs
    db.idEmp = (Employee **)malloc(N * sizeof(Employee *));
    if (db.idEmp == NULL) {
        db.size = 0;
        return db;
    }
    db.ssnEmp = (Employee **)malloc(N * sizeof(Employee *));
    if (db.ssnEmp == NULL) {
        db.size = 0;
        return db;
    }

    // Copy the input array of employee structs to the allocated array
    for (int i = 0; i < N; i++) {
        db.idEmp[i] = employees[i];
    }
     for (int i = 0; i < N; i++) {
        db.ssnEmp[i] = employees[i];
    }

    //sort by ssn bubblesort
    for (int i = 0; i < db.size - 1; i++) {
        for (int j = 0; j < db.size - i - 1; j++) {
            if (db.ssnEmp[j]->ssn > db.ssnEmp[j + 1]->ssn) {
                // swap pointers
                Employee* temp = db.ssnEmp[j];
                db.ssnEmp[j] = db.ssnEmp[j + 1];
                db.ssnEmp[j + 1] = temp;
            }
        }
    }
    //sort by id bubblesort
    for (int i = 0; i < db.size - 1; i++) {
        for (int j = 0; j < db.size - i - 1; j++) {
            if (db.idEmp[j]->ssn > db.idEmp[j + 1]->ssn) {
                // swap pointers
                Employee* temp = db.idEmp[j];
                db.idEmp[j] = db.idEmp[j + 1];
                db.idEmp[j + 1] = temp;
            }
        }
    }

    return db;
}

Employee * findEmpBySSN(int ssn, EmpDatabase db){
    // Search the database by employee SSN using binary search
    int left = 0;
    int right = db.size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (db.ssnEmp[mid]->ssn == ssn) {
            return db.ssnEmp[mid];
        } else if (db.ssnEmp[mid]->ssn < ssn) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

Employee * findEmpByID(int id, EmpDatabase db){
    // Search the database by employee ID using binary search
    int left = 0;
    int right = db.size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (db.idEmp[mid]->id == id) {
            return db.idEmp[mid];
        } else if (db.idEmp[mid]->id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

void freeEmpDatabase(EmpDatabase db){
    for(int i = 0; i < db.size; i++){
        free(db.idEmp[i]);
        free(db.ssnEmp[i]);
    }
    db.size = 0;
}
