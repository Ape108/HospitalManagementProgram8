// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
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
    
    // Initialize clinic objects with their respective queues
    Clinic heartClinic("Heart Clinic", HC);
    Clinic pulmonaryClinic("Pulmonary Clinic", PC);
    Clinic plasticSurgeryClinic("Plastic Surgery Clinic", PSC);
    
    // Read patient data from file and distribute to appropriate queues
    readFile(inFile, heartClinic, pulmonaryClinic, plasticSurgeryClinic);
    inFile.close();

    // Open log file for tracking operations
    ofstream logFile;
    logFile.open("log.txt");
    if (!logFile.good()) {
        cout << "Error: Could not open log file" << endl;
        return 1;
    }
    logTransaction(logFile, "Program started successfully");

    // Main program loop
    int choice = displayMenu();
    int choice2 = 0;  // Initialize choice2
    while (choice != 4) {  // 4 is the exit option
        if (choice == 1) {
            logTransaction(logFile, "Entered Heart Clinic menu");
            choice2 = 0;  // Reset choice2 for new clinic
            while (choice2 != 6) {
                // Heart Clinic operations
                cout << "\n=== Heart Clinic ===" << endl;
                choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    Patient newPatient;
                    cout << "\nEnter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "HC";
                    newPatient.status = false;
                    if (heartClinic.addPatient(newPatient, logFile)) {
                        logTransaction(logFile, "Added regular patient to Heart Clinic: " + newPatient.firstName + " " + newPatient.lastName);
                    } else {
                        logTransaction(logFile, "Failed to add patient to Heart Clinic: Queue full", false);
                    }
                }
                else if (choice2 == 2) {
                    // Add Critical Patient
                    Patient newPatient;
                    cout << "Enter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add critical patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "HC";
                    newPatient.status = true;
                    heartClinic.addCriticalPatient(newPatient, logFile);
                }
                else if (choice2 == 3) {
                    // Operate Patient
                    heartClinic.operatePatient(logFile);
                }
                else if (choice2 == 4) {
                    // Cancel Patient
                    heartClinic.cancelPatient(logFile);
                }
                else if (choice2 == 5) {
                    // Print Patients
                    heartClinic.printPatients();
                }
            }
            choice = displayMenu();  // Get new main menu choice after exiting clinic
        }
        else if (choice == 2) {
            logTransaction(logFile, "Entered Pulmonary Clinic menu");
            choice2 = 0;  // Reset choice2 for new clinic
            while (choice2 != 6) {
                // Pulmonary Clinic operations
                cout << "\n=== Pulmonary Clinic ===" << endl;
                choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    Patient newPatient;
                    cout << "\nEnter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "PC";
                    newPatient.status = false;
                    if (pulmonaryClinic.addPatient(newPatient, logFile)) {
                        logTransaction(logFile, "Added regular patient to Pulmonary Clinic: " + newPatient.firstName + " " + newPatient.lastName);
                    } else {
                        logTransaction(logFile, "Failed to add patient to Pulmonary Clinic: Queue full", false);
                    }
                }
                else if (choice2 == 2) {
                    // Add Critical Patient
                    Patient newPatient;
                    cout << "Enter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add critical patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "PC";
                    newPatient.status = true;
                    pulmonaryClinic.addCriticalPatient(newPatient, logFile);
                }
                else if (choice2 == 3) {
                    // Operate Patient
                    pulmonaryClinic.operatePatient(logFile);
                }
                else if (choice2 == 4) {
                    // Cancel Patient
                    pulmonaryClinic.cancelPatient(logFile);
                }
                else if (choice2 == 5) {
                    // Print Patients
                    pulmonaryClinic.printPatients();
                }
            }
            choice = displayMenu();  // Get new main menu choice after exiting clinic
        }
        else if (choice == 3) {
            logTransaction(logFile, "Entered Plastic Surgery Clinic menu");
            choice2 = 0;  // Reset choice2 for new clinic
            while (choice2 != 6) {
                // Plastic Surgery Clinic operations
                cout << "\n=== Plastic Surgery Clinic ===" << endl;
                choice2 = displayClinicMenu();
                if (choice2 == 1) {
                    // Add Patient
                    Patient newPatient;
                    cout << "\nEnter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "PSC";
                    newPatient.status = false;
                    if (plasticSurgeryClinic.addPatient(newPatient, logFile)) {
                        logTransaction(logFile, "Added regular patient to Plastic Surgery Clinic: " + newPatient.firstName + " " + newPatient.lastName);
                    } else {
                        logTransaction(logFile, "Failed to add patient to Plastic Surgery Clinic: Queue full", false);
                    }
                }
                else if (choice2 == 2) {
                    // Add Critical Patient
                    Patient newPatient;
                    cout << "Enter patient first name: ";
                    cin >> newPatient.firstName;
                    cout << "Enter patient last name: ";
                    cin >> newPatient.lastName;
                    cout << "Enter patient SSN (numbers only): ";
                    cin >> newPatient.ssn;
                    // Validate SSN
                    if (!all_of(newPatient.ssn.begin(), newPatient.ssn.end(), ::isdigit)) {
                        cout << "Error: SSN must contain only numbers." << endl;
                        logTransaction(logFile, "Failed to add critical patient: Invalid SSN format", false);
                        continue;
                    }
                    newPatient.type = "PSC";
                    newPatient.status = true;
                    plasticSurgeryClinic.addCriticalPatient(newPatient, logFile);
                }
                else if (choice2 == 3) {
                    // Operate Patient
                    plasticSurgeryClinic.operatePatient(logFile);
                }
                else if (choice2 == 4) {
                    // Cancel Patient
                    plasticSurgeryClinic.cancelPatient(logFile);
                }
                else if (choice2 == 5) {
                    // Print Patients
                    plasticSurgeryClinic.printPatients();
                }
            }
            choice = displayMenu();  // Get new main menu choice after exiting clinic
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            logTransaction(logFile, "Invalid menu choice entered", false);
            choice = displayMenu();
        }
    }

    // Generate end-of-day report
    ofstream reportFile;
    reportFile.open("next_day_patients.csv");
    if (reportFile.good()) {
        generateEndOfDayReport(heartClinic.getQueue(), pulmonaryClinic.getQueue(), plasticSurgeryClinic.getQueue(), reportFile);
        logTransaction(logFile, "Generated next day's patient list");
        reportFile.close();
    } else {
        logTransaction(logFile, "Failed to generate next day's patient list", false);
    }

    // Print final status
    cout << "\n=== Final Status ===" << endl;
    cout << "Heart Clinic Patients:" << endl;
    heartClinic.printPatients();
    cout << "\nPulmonary Clinic Patients:" << endl;
    pulmonaryClinic.printPatients();
    cout << "\nPlastic Surgery Clinic Patients:" << endl;
    plasticSurgeryClinic.printPatients();
    
    logTransaction(logFile, "Program ended successfully");
    logFile.close();
    cout << "\nHave a good day!" << endl;
    return 0;
}

