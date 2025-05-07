#pragma once
#include "linked.h"
#include <string>
#include <iostream>

// Queue class that inherits from LinkedList to implement a patient queue
class Queue : public LinkedList {
private:
	int max_size = 10;  // Maximum number of patients allowed in the queue
	int count = 0;      // Current number of patients in the queue

public:
	// Default constructor calls parent class constructor
	Queue() : LinkedList() {}
    
	// Override of addNode to implement queue-specific addition logic
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

	// Getter for the head pointer
	Node* getHeadPtr() {
		return headPtr;
	}

	// Special method to add a critical patient to the queue
	// Critical patients are added after other critical patients but before non-critical ones
	void addCriticalPatient(Node* newNode) {
		if (isFull()) {
			cout << "The queue is full." << endl;
			return;
		}

		if (isEmpty()) {
			// If queue is empty, add as first patient
			headPtr = tailPtr = newNode;
		} else {
			// Find the last critical patient
			Node* current = headPtr;
			Node* previous = nullptr;

			while (current != nullptr && current->data.status == true) {
				previous = current;
				current = current->nextPtr;
			}

			// Insert the new critical patient in the appropriate position
			if (previous == nullptr) {
				// If no critical patients exist, add at the front
				newNode->nextPtr = headPtr;
				headPtr = newNode;
			} else {
				// Insert after the last critical patient
				newNode->nextPtr = previous->nextPtr;
				previous->nextPtr = newNode;
			}
		}
		count++;
	}
    
	// Method to cancel a patient's appointment using their SSN
	bool cancelPatientBySSN(string ssn) {
		Node* current = headPtr;
		Node* previous = nullptr;

		// Search for the patient with matching SSN
		while (current != nullptr) {
			if (current->data.ssn == ssn) {
				// Remove the node from the list
				if (previous == nullptr) {
					headPtr = current->nextPtr;
				} else {
					previous->nextPtr = current->nextPtr;
				}
				if (current == tailPtr) {
					tailPtr = previous;
				}
				delete current;
				count--;
				return true;
			}
			previous = current;
			current = current->nextPtr;
		}
		return false;
	}
	
	// Override of delNode to implement queue-specific removal (FIFO)
	void delNode() override {
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
	
	// Check if the queue has reached its maximum capacity
	bool isFull() {
		return count >= max_size;
	}
	
	// Check if the queue is empty
	bool isEmpty() {
		return count == 0;
	}
	
	// Get the current number of patients in the queue
	int size() {
		return count;
	}
};
