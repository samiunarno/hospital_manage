#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <iostream>
using namespace std;

class MedicalRecord {
public:
    int patientId;
    string type;  
    string details;

    MedicalRecord() {}

    MedicalRecord(int pid, string type, string details) {
        this->patientId = pid;
        this->type = type;
        this->details = details;
    }

    void display() {
        cout << "Patient ID: " << patientId
             << ", Type: " << type
             << ", Details: " << details << endl;
    }
};

#endif