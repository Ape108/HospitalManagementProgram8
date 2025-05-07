#include "file_handler.h"

// Reads patient data from a CSV file and distributes patients to appropriate clinic queues
void readFile(ifstream& inFile, Queue& L, Queue& HC, Queue& PC, Queue& PSC) {
    Patient tempPerson;
    string inStr, tempStr;
    vector<string> row;

    // Read the file line by line
    while (getline(inFile, inStr)) {
        stringstream inSS(inStr);
        row.clear();

        // Parse each line into comma-separated values
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        // Extract patient information from the parsed data
        tempPerson.type = row[0];
        if (tempPerson.type == "ERR") throw logic_error("Error in Type");
        tempPerson.firstName = row[1];
        tempPerson.lastName = row[2];

        try {
            // Convert SSN to integer and create a new patient node
            tempPerson.ssn = stoi(row[3]);
            Node* temp = new Node(tempPerson);
            L.addNode(temp);  // Add to main list
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

    // Distribute patients to their respective clinic queues
    Node* current = L.getHeadPtr();
    while (current != nullptr) {
        if (current->data.type == "HC") {
            HC.addNode(current);  // Add to Heart Clinic queue
        }
        else if (current->data.type == "PC") {
            PC.addNode(current);  // Add to Pulmonary Clinic queue
        }
        else if (current->data.type == "PSC") {
            PSC.addNode(current);  // Add to Plastic Surgery Clinic queue
        }
        current = current->nextPtr;
    }
}
