#pragma once

#include <string>
#include <fstream>

#include "queue.h"

using namespace std;

struct Patient {
    string firstName;
    string lastName;
    string ssn;
    bool status;

    Patient(string fn, string ln, string s, bool status = false);
};

class Clinic { //Starter code, you can change the function names and parameters as you like -- Mason
private:
  string clinicName;
  Queue patientQueue;

public:
  Clinic(string name);

  bool addPatient(Patient& patient, ofstream& logFile);
  void addCriticalPatient(Patient& patient, ofstream& logFile);
  void operatePatient(ofstream& logFile);
  void cancelPatient(string lname, ofstream& logFile);

  void printPatients();
};
