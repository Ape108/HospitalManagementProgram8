#include "menu.h"

// Displays the main menu of the hospital system
// Returns the user's choice (1-4)
int displayMenu() {
    int choice = 0;
    while (choice < 1 || choice > 4) {
        cout << "KC Research Hospital" << endl;
        cout << "1. Heart Clinic" << endl;
        cout << "2. Pulmonary Clinic" << endl;
        cout << "3. Plastic Surgery" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Error: Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input (AI helped error handling)
            choice = 0;  // Reset choice
            continue;
        }
        
        if (choice < 1 || choice > 4) {
            cout << "Error: Please enter a number between 1 and 4." << endl;
        }
    }
    return choice;
}

// Displays the clinic-specific menu for patient management
// Returns the user's choice (1-6)
int displayClinicMenu() {
    int choice = 0;
    while (choice < 1 || choice > 6) {
        cout << "1. Add Patient" << endl;
        cout << "2. Add Critical Patient" << endl;
        cout << "3. Take out Patient for Operation" << endl;
        cout << "4. Cancel Patient" << endl;
        cout << "5. List Patients in Queue" << endl;
        cout << "6. Change Departments or Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Error: Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input (AI helped error handling)
            choice = 0;  // Reset choice
            continue;
        }
        
        if (choice < 1 || choice > 6) {
            cout << "Error: Please enter a number between 1 and 6." << endl;
        }
    }
    return choice;
}
