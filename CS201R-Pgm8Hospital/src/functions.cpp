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
