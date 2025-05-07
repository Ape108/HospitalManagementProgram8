// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "file_handler.h"
#include "queue.h"
#include "menu.h"
#include "clinic.h"
#include "linked.h"

using namespace std;

int main() {
    // Open and validate the patient data file
    ifstream inFile;
    inFile.open("patient_data.csv");
    if (!inFile.good()) {
        cout << "File not found" << endl;
        return 0;
    }

    // Initialize queues for different clinics
    Queue L, HC, PC, PSC;  // L = main list, HC = Heart Clinic, PC = Pulmonary Clinic, PSC = Plastic Surgery Clinic
    
    // Read patient data from file and distribute to appropriate queues
    readFile(inFile, L, HC, PC, PSC);
    inFile.close();

    // Open log file for tracking operations
    ofstream logFile;
    logFile.open("log.txt");
    if (!logFile.good())
        cout << "Log file not found" << endl;

    // Initialize clinic objects with their respective queues
    Clinic heartClinic("Heart Clinic", HC);
    Clinic pulmonaryClinic("Pulmonary Clinic", PC);
    Clinic plasticSurgeryClinic("Plastic Surgery Clinic", PSC);
    
    // Main program loop
    int choice = displayMenu();
    Patient tempPatient;
    string first= "Enter Patients First Name: ", last= "\nEnter Patients Last Name: ", ssn= "\nEnter Patients SSN: ";
    while (choice != 4) {  // 4 is the exit option
        if (choice == 1) {
            // Heart Clinic operations
            cout << "Welcome to the Heart Clinic" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
                HC.addPatient(HC, logFile);
            }
            else if (choice2==2){
                cin >> first;
                cin >> last;
                cin >> ssn;
                tempPatient.firstName=first;
                tempPatient.lastName=last;
                tempPatient.ssn=ssn;
                tempPatient.type="HC";
                HC.addNode(tempPatient);

            }
            else if (choice2==3){
                
            }
            else if (choice2==4){
                HC.cancelPatient();

            }
            else if (choice2==5){

            }
            else if(choice2==6){

            }
        }
        else if (choice == 2) {
            // Pulmonary Clinic operations
            cout << "Welcome to the Pulmonary Clinic" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
                cin >> first;
                cin >> last;
                cin >> ssn;
                tempPatient.firstName=first;
                tempPatient.lastName=last;
                tempPatient.ssn=ssn;
                tempPatient.type="PC";
                HC.addNode(tempPatient);
            }
            // Add code to handle Pulmonary Clinic
        }
        else if (choice == 3) {
            // Plastic Surgery Clinic operations
            cout << "Welcome to the Plastic Surgery" << endl;
            int choice2 = displayClinicMenu();
            if (choice2 == 1) {
                // Add Patient
                cin >> first;
                cin >> last;
                cin >> ssn;
                tempPatient.firstName=first;
                tempPatient.lastName=last;
                tempPatient.ssn=ssn;
                tempPatient.type="PSC";
                HC.addNode(tempPatient);

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

