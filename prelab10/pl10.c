#include "pl10.h"

void quicksortById(Employee **idEmp, int left, int right) { // O(nlog(n))
  int i = left, j = right;
  Employee *pivot = idEmp[(left + right) / 2];

  while (i <= j) {
    while (idEmp[i]->id < pivot->id) {
      i++;
    }
    while (idEmp[j]->id > pivot->id) {
      j--;
    }
    if (i <= j) {
      Employee *temp = idEmp[i];
      idEmp[i] = idEmp[j];
      idEmp[j] = temp;
      i++;
      j--;
    }
  }

  if (left < j) {
    quicksortById(idEmp, left, j);
  }
  if (i < right) {
    quicksortById(idEmp, i, right);
  }
}

void quicksortBySsn(Employee **ssnEmp, int left, int right) { // O(nlog(n))
  int i = left, j = right;
  Employee *pivot = ssnEmp[(left + right) / 2];

  while (i <= j) {
    while (ssnEmp[i]->ssn < pivot->ssn) {
      i++;
    }
    while (ssnEmp[j]->ssn > pivot->ssn) {
      j--;
    }
    if (i <= j) {
      Employee *temp = ssnEmp[i];
      ssnEmp[i] = ssnEmp[j];
      ssnEmp[j] = temp;
      i++;
      j--;
    }
  }

  if (left < j) {
    quicksortBySsn(ssnEmp, left, j);
  }
  if (i < right) {
    quicksortBySsn(ssnEmp, i, right);
  }
}

EmpDatabase createSearchableEmployeeDB(Employee **employees,
                                       int N) { // O(nlog(n))
  EmpDatabase db;
  db.size = N;

  // Allocate memory for array of pointers to emp structs
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

  // Sort by ssn using quicksort
  quicksortBySsn(db.ssnEmp, 0, db.size - 1);

  // Sort by id using quicksort
  quicksortById(db.idEmp, 0, db.size - 1);

  return db;
}

Employee *findEmpBySSN(int ssn, EmpDatabase db) { // O(log(n))
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

Employee *findEmpByID(int id, EmpDatabase db) { // O(log(n))
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

void freeEmpDatabase(EmpDatabase db) { // O(n)
  for (int i = 0; i < db.size; i++) {
    free(db.idEmp[i]);
    free(db.ssnEmp[i]);
  }
  db.size = 0;
}
