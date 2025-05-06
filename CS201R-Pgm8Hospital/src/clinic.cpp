#include "clinic.h"
#include <iostream>

// Constructor for Clinic, initializes clinic name and patient queue
Clinic::Clinic() {
    clinicName = "";
    patientQueue = Queue();
}
Clinic::Clinic(string name, Queue& q) {
    clinicName = name;
    patientQueue = q;
}

// Adds a patient to the queue, logs the action in the log file
bool Clinic::addPatient(Patient& patient, ofstream& logFile) {
    if (patientQueue.isFull()) {
        logFile << "Clinic is full, cannot add patient: " << patient.firstName << " " << patient.lastName << endl;
        return false;  // Clinic is full
    }

    // Create a new node for the patient
    Node* newNode = new Node();
    newNode->data = patient;

    patientQueue.addNode(newNode);  // Add the patient to the queue
    logFile << "Added patient: " << patient.firstName << " " << patient.lastName << endl;

    return true;
}

// Adds a critical patient to the front of the queue, logs the action in the log file
void Clinic::addCriticalPatient(Patient& patient, ofstream& logFile) {
    // Create a new node for the critical patient
    Node* newNode = new Node();
    newNode->data = patient;
    patientQueue.addCriticalPatient(newNode);
    // Log the action
    logFile << "Added critical patient: " << patient.firstName << " " << patient.lastName << endl;
}

// Operates on the first patient in the queue and logs the operation
void Clinic::operatePatient(ofstream& logFile) {
    if (patientQueue.isEmpty()) {
        logFile << "No patients available for operation." << endl;
        return;
    }

    Patient operatedPatient = patientQueue.getHeadPtr()->data;
    patientQueue.delNode();  // Remove patient from the queue

    logFile << "Operated on patient: " << operatedPatient.firstName << " " << operatedPatient.lastName << endl;
}

// Cancels a patient from the queue based on last name, logs the cancellation
void Clinic::cancelPatient(string ssn, ofstream& logFile) {
    // Ask the user for the SSN of the patient to cancel
    cout << "Enter the SSN of the patient to cancel: ";
    cin >> ssn;

    // Call the cancelPatient method from Queue to remove the patient
    Node* currentNode = patientQueue.getHeadPtr();
    bool patientFound = false;
    Patient temp;
    while (currentNode != nullptr) {
        if (currentNode->data.ssn == ssn) {
            patientFound = true;
            temp = currentNode->data;
            break;
        }
        currentNode = currentNode->nextPtr;
    }

    if (patientFound) {
        bool worked = false;
        // If the patient is found, remove them from the queue and log the cancellation
        worked = patientQueue.cancelPatientBySSN(temp.ssn);
        if (!worked) {
          cout << "Patient Does Not Exist." << endl;
          logFile << "Patient Does Not Exist. SSN: " << ssn << endl;
        }
        else {
          cout << "Patient with SSN " << ssn << " has been canceled." << endl;
          logFile << clinicName << " patient: " << temp.firstName << " " << temp.lastName
            << " has been removed from the waiting list." << endl;
        }
    }
}

// Prints all patients in the queue to the console
void Clinic::printPatients() {
    cout << "Patients in Queue:" << endl;
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" 
         << setw(20) << "SSN" << "Status" << endl << endl;

    // Traverse the queue and print each patient
    Node* currentNode = patientQueue.getHeadPtr();

    // Check if the queue is empty
    if (currentNode == nullptr) {
        cout << "No patients in the queue." << endl;
        return;
    }

    while (currentNode != nullptr) {
        Patient& p = currentNode->data;

        string status;
        if (p.status) {
            status = "Critical";
        }
        else {
            status = "Regular";
        }

        // Print patient information
        cout << left << setw(20) << p.firstName << setw(20) << p.lastName 
             << setw(20) << p.ssn << status << endl;

        // Move to the next node in the queue
        currentNode = currentNode->nextPtr;
    }
}

