#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


#include "clinic.h"

// Read patient data from a CSV file and distribute patients to appropriate clinic queues
// Parameters:
//   inFile: Input file stream containing patient data
//   L: Main list of all patients
//   HC: Queue for Heart Clinic patients
//   PC: Queue for Pulmonary Clinic patients
//   PSC: Queue for Plastic Surgery Clinic patients
void readFile(ifstream& inFile, Queue& L, Queue& HC, Queue& PC, Queue& PSC);
