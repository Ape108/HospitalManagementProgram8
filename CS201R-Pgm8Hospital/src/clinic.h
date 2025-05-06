#pragma once

#include <string>
#include <fstream>

#include "queue.h"

using namespace std;

class Clinic { //Starter code, you can change the function names and parameters as you like -- Mason
private:
  string clinicName;
  Queue patientQueue;

public:
  Clinic();
  Clinic(string name, Queue& q);

  bool addPatient(Patient& patient, ofstream& logFile);
  void addCriticalPatient(Patient& patient, ofstream& logFile);
  void operatePatient(ofstream& logFile);
  void cancelPatient(string lname, ofstream& logFile);

  void printPatients();
};
