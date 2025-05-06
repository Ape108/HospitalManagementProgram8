#include "file_handler.h"

void readFile(ifstream& inFile, Queue& L, Queue& HC, Queue& PC, Queue& PSC) {
    Patient tempPerson;
    string inStr, tempStr;
    vector <string> row;
    while (getline(inFile, inStr)) {
        stringstream inSS(inStr);
        row.clear();
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }
        tempPerson.type = row[0];
        if (tempPerson.type== "ERR") throw logic_error("Error in Type");
        tempPerson.firstName = row[1];
        tempPerson.lastName = row[2];
        try {
            tempPerson.ssn = stoi(row[3]);
            Node* temp = new Node(tempPerson);
            L.addNode(temp);

        }
        catch (logic_error& err) {
            cout << err.what() << endl;
            continue;
        }
        catch (...) {
            cout << "Unknown Error" << endl;
            continue;
        }
    }
    Node* current = L.getHeadPtr();
    while (current!=nullptr){
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
