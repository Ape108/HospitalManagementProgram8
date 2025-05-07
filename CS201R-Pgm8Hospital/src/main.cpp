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
    Node* tempNode;
    while (choice != 4) {  // 4 is the exit option
        if (choice == 1) {
            while (choice2!=6){
                // Heart Clinic operations
                cout << "Welcome to the Heart Clinic" << endl;
                int choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    heartClinic.addPatient(HC, logFile);
                }
                else if (choice2==2){
                    // Add Critical Patient
                    heartClinic.addCriticalPatient(HC, logFile);
                }
                else if (choice2==3){
                    // Operate Patient
                    heartClinic.operatePatient(logFile);
                }
                else if (choice2==4){
                    // Cancel Patient
                    heartClinic.cancelPatient(logFile);
                }
                else if (choice2==5){
                    // Print Patients
                    heartClinic.printPatients();
                }
            }
        }
        else if (choice == 2) {
            while (choice2!=6){
                // Pulmonary Clinic operations
                cout << "Welcome to the Pulmonary Clinic" << endl;
                int choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    pulmonaryClinic.addPatient(HC, logFile);
                }
                else if (choice2==2){
                    // Add Critical Patient
                    pulmonaryClinic.addCriticalPatient(HC, logFile);
                }
                else if (choice2==3){
                    // Operate Patient
                    pulmonaryClinic.operatePatient(logFile);
                }
                else if (choice2==4){
                    // Cancel Patient
                    pulmonaryClinic.cancelPatient(logFile);
                }
                else if (choice2==5){
                    // Print Patients
                    pulmonaryClinic.printPatients();
                }
            }
        }
        else if (choice == 3) {
            while (choice2!=6){
                // Plastic Surgery Clinic operations
                cout << "Welcome to the Plastic Surgery" << endl;
                int choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    plasticSurgeryClinic.addPatient(HC, logFile);
                }
                else if (choice2==2){
                    // Add Critical Patient
                    plasticSurgeryClinic.addCriticalPatient(HC, logFile);
                }
                else if (choice2==3){
                    // Operate Patient
                    plasticSurgeryClinic.operatePatient(logFile);
                }
                else if (choice2==4){
                    // Cancel Patient
                    plasticSurgeryClinic.cancelPatient(logFile);
                }
                else if (choice2==5){
                    // Print Patients
                    plasticSurgeryClinic.printPatients();
                }
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << "New choice: ";
        cin >> choice;
    }
    
    cout << "Have a good day!" << endl;
    return 0;

}

