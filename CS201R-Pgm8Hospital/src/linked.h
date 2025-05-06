#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Patient structure
struct Patient {
    string type;
    string firstName;
    string lastName;
    string ssn;
    bool status; // true = critical, false = non-critical

    Patient() : type(""), firstName(""), lastName(""), ssn(""), status(false) {}
    Patient(string type, string fn, string ln, string s, bool status = false)
        : type(type), firstName(fn), lastName(ln), ssn(s), status(status) {}
};

// Node structure
struct Node {
    Patient data;
    Node* nextPtr;

    Node() : data(), nextPtr(nullptr) {}
    Node(Patient p) : data(p), nextPtr(nullptr) {}
};

// Abstract LinkedList base class
class LinkedList {
protected:
    Node* headPtr;
    Node* tailPtr;

public:
    LinkedList() : headPtr(nullptr), tailPtr(nullptr) {}
    LinkedList(Patient p) {
        Node* newNode = new Node(p);
        headPtr = tailPtr = newNode;
    }
    virtual ~LinkedList() {
        Node* curr = headPtr;
        while (curr) {
            Node* temp = curr;
            curr = curr->nextPtr;
            delete temp;
        }
    }

    virtual void addNode(Node* newNode) = 0;
    virtual void delNode() = 0;

    Node* getHeadPtr() const { return headPtr; }
    Node* getTailPtr() const { return tailPtr; }
};
