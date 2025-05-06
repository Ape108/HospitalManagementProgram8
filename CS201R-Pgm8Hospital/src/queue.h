#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct dataType {
	string type;
	string lname;
	string fname;
	int age;

	dataType() : type(""),lname(""), fname(""),age(0) {}
	dataType(string t, string ln, string fn, int a) : type(t), lname(ln), fname(fn), age(a) {}
};

struct Node {
	dataType data;
	Node* nextPtr;

	Node() : data(), nextPtr(nullptr) {}
	Node(dataType d) {
		data = d;
		nextPtr = nullptr;
	}
};

class LinkedList {
protected:
	Node* headPtr;
	Node* tailPtr;
public:
	LinkedList();
	LinkedList(dataType);
  ~LinkedList() {
		Node* curr = headPtr;
		while (curr) {
			Node* temp = curr;
			curr = curr->nextPtr;
			delete temp;
		}
	}
	virtual void addNode(Node* newNode););
	void addNodeOrdered(dataType d);
	virtual void delNode();
	void printList();
};

LinkedList::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
}
LinkedList::LinkedList(dataType d) {
	Node* newNode = new Node(d);
	headPtr = tailPtr = newNode;
}


class Queue : public LinkedList {
private:
	int max_size = 10;
	int count = 0; //Tracks number of people in queue
public:
	Queue() : LinkedList() {}
	Queue(dataType d) : LinkedList(d) {count++;}
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
