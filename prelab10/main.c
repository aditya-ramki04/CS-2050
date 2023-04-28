#include "pl10.h"

int main() {
    Employee e1 = { 100, 12 };
    Employee e2 = { 50, 16 };
    Employee e3 = { 75, 20};
    Employee* arr[] = { &e1, &e2, &e3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    EmpDatabase db = createSearchableEmployeeDB(arr, n);

    //test id search
    Employee *res = findEmpByID(20, db);
    printf("%d\n", res->ssn); //75


    freeEmpDatabase(db);

    Employee *res2 = findEmpBySSN(100, db);
    printf("%d\n", res2->id); //12
    return 0;
}
