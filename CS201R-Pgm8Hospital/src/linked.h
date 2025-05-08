#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Patient structure to store patient information
struct Patient {
    string type;      // Type of clinic (HC, PC, PSC)
    string firstName; // Patient's first name
    string lastName;  // Patient's last name
    string ssn;       // Social Security Number (unique identifier)
    bool status;      // true = critical patient, false = non-critical patient

    // Default constructor initializes all fields to empty/false
    Patient() : type(""), firstName(""), lastName(""), ssn(""), status(false) {}
    
    // Parameterized constructor to create a patient with specific information
    Patient(string type, string fn, string ln, string s, bool status = false)
        : type(type), firstName(fn), lastName(ln), ssn(s), status(status) {}
};

// Node structure for the linked list implementation
struct Node {
    Patient data;     // Stores the patient information
    Node* nextPtr;    // Pointer to the next node in the list

    // Default constructor initializes nextPtr to nullptr
    Node() : data(), nextPtr(nullptr) {}
    
    // Constructor that creates a node with a specific patient
    Node(Patient p) : data(p), nextPtr(nullptr) {}
};

// Abstract base class for LinkedList implementation
class LinkedList {
protected:
    Node* headPtr;    // Pointer to the first node in the list
    Node* tailPtr;    // Pointer to the last node in the list

public:
    // Default constructor initializes an empty list
    LinkedList() : headPtr(nullptr), tailPtr(nullptr) {}
    
    // Constructor that creates a list with one patient
    LinkedList(Patient p) {
        Node* newNode = new Node(p);
        headPtr = tailPtr = newNode;
    }
    
    // Virtual destructor to properly clean up the linked list
    virtual ~LinkedList() {
        // The Queue class will handle node deletion
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    // Pure virtual functions that must be implemented by derived classes
    virtual void addNode(Node* newNode) = 0;  // Add a new node to the list
    virtual void delNode() = 0;              // Remove a node from the list

    // Accessor methods for the head and tail pointers
    Node* getHeadPtr() const { return headPtr; }
    Node* getTailPtr() const { return tailPtr; }
};
