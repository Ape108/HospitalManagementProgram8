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
            L.addNode(tempPerson);
            //L.addNodeOrdered(tempPerson);
        }
        catch (logic_error) {
            cout << "error in input" << endl;
            continue;
        }
    }
    Node* current = L.headPtr;
    while(current!=nullptr){
        if (current->type == "HC"){
            HC.addNode(current);
        }
        else if (current->type=="PC"){
            PC.addNode(current);
        }
        else if (current->type=="PSC"){
            PSC.addNode(current);
        }
        current=current->nextPtr;
    }

}
