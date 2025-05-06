#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct Patient {
		string type;
		string firstName;
		string lastName;
		string ssn;
		bool status; // true = critical, false = non-critical
		Patient() : type(""), firstName(""), lastName(""), ssn(""), status(false) {}
		Patient(string type, string fn, string ln, string s, bool status = false);
};

struct Node {
	Patient data;
	Node* nextPtr;

	Node() : data(), nextPtr(nullptr) {}
	Node(Patient p) {
		data = p;
		nextPtr = nullptr;
	}
};

class LinkedList {
protected:
	Node* headPtr;
	Node* tailPtr;
public:
	LinkedList();
	LinkedList(Patient p);
  virtual ~LinkedList();
	virtual void addNode(Node* newNode) = 0;
	virtual void delNode();
};

LinkedList::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
}
LinkedList::LinkedList(Patient p) {
	Node* newNode = new Node(p);
	headPtr = tailPtr = newNode;
}
LinkedList::~LinkedList() {
	Node* curr = headPtr;
	while (curr) {
		Node* temp = curr;
		curr = curr->nextPtr;
		delete temp;
	}
}



class Queue : public LinkedList {
private:
	int max_size = 10;
	int count = 0; //Tracks number of people in queue
public:
	Queue() : LinkedList() {}
	Queue(Patient d) : LinkedList(d) {count++;}
	void addNode(Node* newNode) override {
		if (isFull()) {
			cout << "The queue is full." << endl;
			return;
		}
		if (tailPtr) {
			tailPtr->nextPtr = newNode;
		} else {
			headPtr = newNode;
		}
		tailPtr = newNode;
		count++;
	}

	Node* getHeadPtr() {
		return headPtr;
	}

	void addCriticalPatient(Node* newNode) {
			if (isFull()) {
					cout << "The queue is full." << endl;
					return;
			}

			if (isEmpty()) {
					// If the queue is empty, simply add the critical patient at the top
					headPtr = tailPtr = newNode;
			} else {
					// Insert the new critical patient after the existing critical patients
					Node* current = headPtr;
					Node* previous = nullptr;

					while (current != nullptr && current->data.status == true) {
							previous = current;
							current = current->nextPtr;
					}

					// Insert the critical patient in the appropriate position
					if (previous == nullptr) {
							// If no critical patients exist, the new one becomes the head
							newNode->nextPtr = headPtr;
							headPtr = newNode;
					} else {
							// Insert the new critical patient after the last critical patient
							newNode->nextPtr = previous->nextPtr;
							previous->nextPtr = newNode;
					}
			}

			count++;  // Increment the queue size
	}
	bool cancelPatientBySSN(string ssn) {
			Node* current = headPtr;
			Node* previous = nullptr;
	
			// Traverse the list to find the patient by SSN
			while (current != nullptr) {
					if (current->data.ssn == ssn) {
							// Patient found, now delete the node
							if (previous == nullptr) { // Patient is at the head
									headPtr = current->nextPtr;
							} else { // Patient is in the middle or at the end
									previous->nextPtr = current->nextPtr;
							}
							if (current == tailPtr) { // If it's the last node
									tailPtr = previous;
							}
							delete current;
							count--;
							return true;  // Patient found and removed
					}
					previous = current;
					current = current->nextPtr;
			}
			return false;  // Patient not found
	}
	
	void delNode() override { // dequeue - removes a node from the front of the queue
		if (isEmpty()) {
			cout << "The queue is empty." << endl;
			return;
		}
		Node* del = headPtr;
		headPtr = headPtr->nextPtr;
		if (headPtr == nullptr) {
			tailPtr = nullptr;
		}
		delete del;
		count--;
	}
	
	bool isFull(){
		return count >= max_size;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	int size(){
		return count;
	}
};
