#include "pl11.h"

int main() {
  // Create a new EmpDatabase
    EmpDatabase db = createSearchableEmployeeDB();

    // Insert some Employees into the database
    Employee* emp1 = (Employee*)malloc(sizeof(Employee));
    emp1->salary = 50000;
    db = insertEmp(emp1, db);

    Employee* emp2 = (Employee*)malloc(sizeof(Employee));
    emp2->salary = 60000;
    db = insertEmp(emp2, db);

    Employee* emp3 = (Employee*)malloc(sizeof(Employee));
    emp3->salary = 55000;
    db = insertEmp(emp3, db);

    Employee* emp4 = (Employee*)malloc(sizeof(Employee));
    emp4->salary = 45000;
    db = insertEmp(emp4, db);

    Employee* emp5 = (Employee*)malloc(sizeof(Employee));
    emp5->salary = 35000;
    db = insertEmp(emp5, db);

    Employee* emp6 = (Employee*)malloc(sizeof(Employee));
    emp6->salary = 65000;
    db = insertEmp(emp6, db);

    Employee* emp7 = (Employee*)malloc(sizeof(Employee));
    emp7->salary = 75000;
    db = insertEmp(emp7, db);

    freeEmpDatabase(db.root);

    //printf("%d\n", db.root->left->left->emp->salary);
    int res = countEmpsInSalaryRange(34000, 56000, db);
    printf("%d\n", res);

  return 0;
}
