#include "file_handler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Get current timestamp in a formatted string
string getCurrentTimestamp() {
    auto now = time(nullptr);
    auto tm = *localtime(&now);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Log a transaction with timestamp
void logTransaction(ofstream& logFile, const string& message, bool success) {
    logFile << "[" << getCurrentTimestamp() << "] ";
    logFile << (success ? "SUCCESS: " : "ERROR: ");
    logFile << message << endl;
}

// Reads patient data from a CSV file and distributes patients to appropriate clinic queues
void readFile(ifstream& inFile, Clinic& heartClinic, Clinic& pulmonaryClinic, Clinic& plasticSurgeryClinic) {
    string line;
    // Skip header line
    getline(inFile, line);
    
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, firstName, lastName, ssn, statusStr;
        
        // Parse CSV line
        getline(ss, type, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, ssn, ',');
        getline(ss, statusStr, ',');
        
        // Validate data
        if (type.empty() || firstName.empty() || lastName.empty() || ssn.empty()) {
            cerr << "Warning: Skipping invalid patient data: " << line << endl;
            continue;
        }
        
        // Validate SSN
        if (!all_of(ssn.begin(), ssn.end(), ::isdigit)) {
            cerr << "Warning: Invalid SSN format for patient: " << firstName << " " << lastName << endl;
            continue;
        }
        
        // Create patient object
        Patient patient;
        patient.type = type;
        patient.firstName = firstName;
        patient.lastName = lastName;
        patient.ssn = ssn;
        patient.status = (statusStr == "true" || statusStr == "1");
        
        // Add to appropriate clinic
        ofstream dummyLog;  // Create a dummy log file for initial patient loading
        if (type == "HC") {
            if (patient.status) heartClinic.addCriticalPatient(patient, dummyLog);
            else heartClinic.addPatient(patient, dummyLog);
        }
        else if (type == "PC") {
            if (patient.status) pulmonaryClinic.addCriticalPatient(patient, dummyLog);
            else pulmonaryClinic.addPatient(patient, dummyLog);
        }
        else if (type == "PSC") {
            if (patient.status) plasticSurgeryClinic.addCriticalPatient(patient, dummyLog);
            else plasticSurgeryClinic.addPatient(patient, dummyLog);
        }
        else {
            cerr << "Warning: Unknown clinic type: " << type << endl;
        }
    }
}

// Generate end-of-day report in CSV format for next day's input
void generateEndOfDayReport(const Queue& HC, const Queue& PC, const Queue& PSC, ofstream& reportFile) {
    // Write CSV header
    reportFile << "clinicName,firstName,lastName,SSN,status" << endl;
    
    // Helper function to write queue data
    auto writeQueueData = [&reportFile](const Queue& queue, const string& clinicType) {
        Node* current = queue.getHeadPtr();
        while (current != nullptr) {
            reportFile << clinicType << ","
                      << current->data.firstName << ","
                      << current->data.lastName << ","
                      << current->data.ssn << ","
                      << (current->data.status ? "true" : "false") << endl;
            current = current->nextPtr;
        }
    };
    
    // Write data for each clinic
    writeQueueData(HC, "HC");
    writeQueueData(PC, "PC");
    writeQueueData(PSC, "PSC");
}
