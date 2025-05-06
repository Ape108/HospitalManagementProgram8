#include "functions.h"

int displayMenu() {
  cout << "KC Research Hospital" << endl;
  cout << "1. Heart Clinic" << endl;
  cout << "2. Pulmonary Clinic" << endl;
  cout << "3. Plastic Surgery" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter your choice: ";

  int choice;
  cin >> choice;
  return choice;
}
int displayClinicMenu() {
    cout << "1. Add Patient" << endl;
    cout << "2. Add Critical Patient" << endl;
    cout << "3. Take out Patient for Operation" << endl;
    cout << "4. Cancel Patient" << endl;
    cout << "5. List Patients in Queue" << endl;
    cout << "6. Change Departments or Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}
