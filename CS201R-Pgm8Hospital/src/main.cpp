// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "heart_clinic.h"
#include "pulmonary_clinic.h"
#include "plastic_surgery_clinic.h"
#include "file_handler.h"
#include "menu.h"
#include "queue.h"
#include "functions.h"
using namespace std;

int main()
{	
	
    int choice = displayMenu(); // Display the menu and get the user's choice
    while (choice != 4) {
        if (choice == 1) {
            // Heart Clinic
            cout << "Heart Clinic" << endl;
            // Add code to handle Heart Clinic
        }
        else if (choice == 2) {
            // Pulmonary Clinic
            cout << "Pulmonary Clinic" << endl;
            // Add code to handle Pulmonary Clinic
        }
        else if (choice == 3) {
            // Plastic Surgery
            cout << "Plastic Surgery" << endl;
            // Add code to handle Plastic Surgery
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << "New choice: ";
        cin >> choice;
    }
    
    return 0;

}

