#include "file_handler.h"
#include <iostream>
#include "clinic.h"
#include <fstream>
#include <sstream>

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
    for (int i= 0; i < L.size(); i++){
        if (L[i].type == "HC"){
            HC.addNode(L[i]);
        }
        else if (L[i].type=="PC"){
            PC.addNode(L[i]);
        }
        else if (L[i].type=="PSC"){
            PSC.addNode(L[i]);
        }
    }

}