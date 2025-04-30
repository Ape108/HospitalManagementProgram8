# KC Research Hospital - Patient Management System

## Project Overview
This project involves developing a patient management system for Research Hospital with three departments: Heart Clinic, Pulmonary Clinic, and Plastic Surgery Clinic. The system will track patients in each department's queue, handle regular and critically ill patients with appropriate prioritization, and maintain transaction logs of all operations.

## Project Requirements

### Core Functionality
- Implement a custom queue using linked list nodes/pointers (no built-in containers like vectors)
- Manage patients in three different clinic departments
- Support both regular and critically ill patients with priority handling
- Process input from a CSV file for scheduled patients
- Generate transaction logs and reports
- Provide interactive menu system for clinic operations

### Specific Features
1. **Patient Management**
   - Add regular patients to the end of the queue
   - Add critically ill patients with priority over regular patients
   - Take patients to operation room (with critical patients given priority)
   - Cancel patients by SSN
   - List all current patients in a clinic

2. **File Operations**
   - Read initial patients from patient.csv
   - Log all transactions (successful and failed)
   - Generate end-of-day report of remaining patients

3. **Data Validation**
   - Validate clinic names (HC, PC, PSC)
   - Ensure SSN is numeric
   - Enforce clinic capacity limits (max 10 patients per clinic)

### Interface Requirements
- Main menu for department selection
- Department-specific menu for operations
- Console-based user interface

## Class Structure Plans
- Patient class/struct for storing patient information
- Custom queue implementation using nodes and pointers
- Base Clinic class with derived classes for each department
- File handling functionality for I/O operations

## Input/Output Specifications

### Input File Format (patient.csv)
```
clinicName,firstName,lastName,SSN
```
Where:
- clinicName: HC (Heart Clinic), PC (Pulmonary Clinic), or PSC (Plastic Surgery Clinic)
- firstName: Patient's first name
- lastName: Patient's last name
- SSN: Social Security Number (must be numeric)

### Output Files
- Transaction log: Records of all operations grouped by clinic
- End-of-day file: Remaining patients to be used as input for the next day

## Project Team
This project is being developed by a team of three students, with responsibilities divided into:
1. Data structures and patient operations
2. Queue management and file I/O
3. Program integration and transaction logging

## Academic Context
This project is part of a programming course focusing on:
- Object-oriented programming concepts
- Custom data structure implementation
- File I/O operations
- Group programming practices