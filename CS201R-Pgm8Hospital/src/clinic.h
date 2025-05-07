#pragma once

#include <string>
#include <fstream>

#include "queue.h"

using namespace std;

// Clinic class to manage a specific medical clinic and its patient queue
class Clinic {
private:
  string clinicName;    // Name of the clinic (e.g., "Heart Clinic")
  Queue patientQueue;   // Queue to manage patients waiting for treatment

public:
  // Default constructor initializes an empty clinic
  Clinic();
  
  // Constructor that creates a clinic with a specific name and initial patient queue
  Clinic(string name, Queue& q);

  // Add a regular patient to the clinic's queue
  // Returns true if successful, false if queue is full
  bool addPatient(Patient& patient, ofstream& logFile);
  
  // Add a critical patient to the clinic's queue
  // Critical patients are prioritized in the queue
  void addCriticalPatient(Patient& patient, ofstream& logFile);
  
  // Process the next patient in the queue for treatment
  void operatePatient(ofstream& logFile);
  
  // Cancel a patient's appointment using their SSN
  void cancelPatient(ofstream& logFile);

  // Display all patients currently in the queue
  void printPatients();
};
