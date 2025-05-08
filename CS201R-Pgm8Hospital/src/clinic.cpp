#include "clinic.h"
#include <iostream>
#include <iomanip>

// Default constructor initializes an empty clinic
Clinic::Clinic() {
    clinicName = "";
    patientQueue = Queue();
}

// Constructor that creates a clinic with a specific name and initial patient queue
Clinic::Clinic(string name, Queue& q) {
    clinicName = name;
    patientQueue = q;
}

// Helper function to validate clinic type
bool isValidClinicType(const string& type) {
    return type == "HC" || type == "PC" || type == "PSC";
}

// Adds a regular patient to the queue and logs the action
// Returns true if successful, false if queue is full
bool Clinic::addPatient(Patient& patient, ofstream& logFile) {
    // Validate clinic type
    if (!isValidClinicType(patient.type)) {
        logFile << "Error: Invalid clinic type: " << patient.type << endl;
        return false;
    }

    if (patientQueue.isFull()) {
        logFile << "Clinic is full, cannot add patient: " << patient.firstName << " " << patient.lastName << endl;
        return false;
    }

    // Create a new node for the patient and add to queue
    Node* newNode = new Node();
    newNode->data = patient;
    patientQueue.addNode(newNode);
    logFile << "Added patient: " << patient.firstName << " " << patient.lastName << endl;

    return true;
}

// Adds a critical patient to the queue with priority and logs the action
void Clinic::addCriticalPatient(Patient& patient, ofstream& logFile) {
    // Validate clinic type
    if (!isValidClinicType(patient.type)) {
        logFile << "Error: Invalid clinic type: " << patient.type << endl;
        return;
    }

    // Create a new node for the critical patient
    Node* newNode = new Node();
    newNode->data = patient;
    patientQueue.addCriticalPatient(newNode);
    logFile << "Added critical patient: " << patient.firstName << " " << patient.lastName << endl;
}

// Processes the next patient in the queue for treatment and logs the operation
void Clinic::operatePatient(ofstream& logFile) {
    if (patientQueue.isEmpty()) {
        logFile << "No patients available for operation." << endl;
        return;
    }

    // Get the next patient and remove them from the queue
    Patient operatedPatient = patientQueue.getHeadPtr()->data;
    patientQueue.delNode();

    logFile << "Operated on patient: " << operatedPatient.firstName << " " << operatedPatient.lastName << endl;
}

// Cancels a patient's appointment using their SSN and logs the cancellation
void Clinic::cancelPatient(ofstream& logFile) {
    // Get the SSN from user input
    string ssn;
    cout << "Enter the SSN of the patient to cancel: ";
    cin >> ssn;

    // Search for the patient in the queue
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
        // Attempt to cancel the patient's appointment
        bool worked = patientQueue.cancelPatientBySSN(temp.ssn);
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

// Displays all patients currently in the queue
void Clinic::printPatients() {
    cout << "Patients in Queue:" << endl;
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" 
         << setw(20) << "SSN" << "Status" << endl << endl;

    // Get the first patient in the queue
    Node* currentNode = patientQueue.getHeadPtr();

    // Check if the queue is empty
    if (currentNode == nullptr) {
        cout << "No patients in the queue." << endl;
        return;
    }

    // Print each patient's information
    while (currentNode != nullptr) {
        Patient& p = currentNode->data;

        // Determine patient status
        string status = p.status ? "Critical" : "Regular";

        // Print patient information in formatted columns
        cout << left << setw(20) << p.firstName << setw(20) << p.lastName 
             << setw(20) << p.ssn << status << endl;

        currentNode = currentNode->nextPtr;
    }
}

