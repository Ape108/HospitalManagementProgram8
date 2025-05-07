#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Display the main menu of the hospital system
// Returns the user's choice (1-4)
int displayMenu();

// Display the clinic-specific menu for patient management
// Returns the user's choice (1-6)
int displayClinicMenu();

