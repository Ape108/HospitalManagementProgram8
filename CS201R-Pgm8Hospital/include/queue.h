#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct dataType {
	char type;
	string lname;
	string fname;
	int age;

	dataType() : type(' '),lname(""), fname(""),age(0) {}
};

struct Node {
	dataType data;
	Node* nextPtr;

	Node()  {
		dataType();
		nextPtr = nullptr;
	}
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
	~LinkedList();  //destructor
	virtual void addNode(dataType d);
	void addNodeOrdered(dataType d);
	virtual void delNode(string name);
	void printList();
};

class Queue : public LinkedList {
public:
	void delNode() {
		//condition 1: queue is empty
		if (headPtr == nullptr) {
			cout << "the queue is empty" << endl;
			return;
		}
		Node* delNode = headPtr;
		headPtr = headPtr->nextPtr;
		if (headPtr == nullptr) {
			tailPtr = nullptr;
		}
		delete delNode;
		delNode = nullptr;
	}
};
