# Project Structure

CS201R-Pgm8Hospital/
├── include/                        # Header files
│   ├── patient.h                   # Patient class definition
│   ├── node.h                      # Node class for queue implementation
│   ├── queue.h                     # Queue class using nodes/pointers
│   ├── clinic.h                    # Base Clinic class
│   ├── heart_clinic.h              # Heart Clinic derived class
│   ├── pulmonary_clinic.h          # Pulmonary Clinic derived class
│   ├── plastic_surgery_clinic.h    # Plastic Surgery Clinic derived class
│   ├── file_handler.h              # File I/O operations
│   └── menu.h                      # Menu system functions
│
├── src/                            # Implementation files
│   ├── patient.cpp                 # Patient class implementation
│   ├── node.cpp                    # Node class implementation
│   ├── queue.cpp                   # Queue class implementation  
│   ├── clinic.cpp                  # Base Clinic class implementation
│   ├── heart_clinic.cpp            # Heart Clinic implementation
│   ├── pulmonary_clinic.cpp        # Pulmonary Clinic implementation
│   ├── plastic_surgery_clinic.cpp  # Plastic Surgery Clinic implementation
│   ├── file_handler.cpp            # File I/O functions implementation
│   ├── menu.cpp                    # Menu system functions implementation
│   └── main.cpp                    # Program entry point
│
├── data/                           # Data files
│   ├── patient.csv                 # Input file with scheduled patients
│   ├── transaction_log.txt         # Transaction log output
│   └── next_day_patients.csv       # End-of-day output for next day
│
└── docs/                           # Documentation
    ├── team_roles.md               # Document explaining team roles
    └── design_notes.md             # Design decisions and notes