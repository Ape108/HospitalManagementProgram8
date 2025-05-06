#include "file_handler.h"

void readFile(ifstream& inFile, Queue& L, Queue& HC, Queue& PC, Queue& PSC) {
    dataType tempPerson;
    string inStr, tempStr;
    vector <string> row;
    while (getline(inFile, inStr)) {
        stringstream inSS(inStr);
        row.clear();
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }
        tempPerson.type = row[0];
        if (tempPerson.type== "ERR") throw logic_error("invalid input");
        tempPerson.lname = row[1];
        tempPerson.fname = row[2];
        try {
            tempPerson.age = stoi(row[3]);
            Node* temp = new Node(tempPerson);
            L.addNode(temp);
            //L.addNodeOrdered(tempPerson);
        }
        catch (logic_error) {
            cout << "error in input" << endl;
            continue;
        }
    }
    Node* current = L.getHeadPtr();
    while(current!=nullptr){
        if (current->data.type == "HC"){
            HC.addNode(current);
        }
        else if (current->data.type=="PC"){
            PC.addNode(current);
        }
        else if (current->data.type=="PSC"){
            PSC.addNode(current);
        }
        current=current->nextPtr;
    }

}
