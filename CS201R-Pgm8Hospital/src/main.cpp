// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "file_handler.h"
#include "queue.h"
#include "linked.h"
#include "functions.h"
#include "clinic.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("patient_data.csv");
    if (!inFile.good()) {
        cout << "File not found" << endl;
        return 0;
    }
    Queue L, HC, PC, PSC;
    
    readFile(inFile, L, HC, PC, PSC);
    inFile.close();
    ofstream logFile;
    logFile.open("log.txt");
    if (!logFile.good())
        cout << "Log file not found" << endl;

    Clinic heartClinic("Heart Clinic", HC);
    Clinic pulmonaryClinic("Pulmonary Clinic", PC);
    Clinic plasticSurgeryClinic("Plastic Surgery Clinic", PSC);
    
    int choice = displayMenu();
    while (choice != 4) {
        if (choice == 1) {
            // Heart Clinic
            cout << "Welcome to the Heart Clinic" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
            }
        }
        else if (choice == 2) {
            // Pulmonary Clinic
            cout << "Welcome to the Pulmonary Clinic" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
            }
            // Add code to handle Pulmonary Clinic
        }
        else if (choice == 3) {
            // Plastic Surgery
            cout << "Welcome to the Plastic Surgery" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
            }
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

