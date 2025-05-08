#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "clinic.h"

using namespace std;

// Get current timestamp in a formatted string
string getCurrentTimestamp();

// Log a transaction with timestamp
void logTransaction(ofstream& logFile, const string& message, bool success = true);

// Reads patient data from a CSV file and distributes patients to appropriate clinic queues
void readFile(ifstream& inFile, Clinic& heartClinic, Clinic& pulmonaryClinic, Clinic& plasticSurgeryClinic);

// Generate end-of-day report in CSV format for next day's input
void generateEndOfDayReport(const Queue& HC, const Queue& PC, const Queue& PSC, ofstream& reportFile);
