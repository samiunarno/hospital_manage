#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <iostream>
#include <vector>
using namespace std;

class Prescription {
public:
    int patientId;
    int doctorId;
    vector<string> medicines;

    Prescription() {}

    Prescription(int patientId, int doctorId) {
        this->patientId = patientId;
        this->doctorId = doctorId;
    }

    void addMedicine(string med) {
        medicines.push_back(med);
    }

    void display() {
        cout << "Patient ID: " << patientId
             << ", Doctor ID: " << doctorId << endl;

        cout << "Medicines:\n";
        for (auto &m : medicines) {
            cout << "- " << m << endl;
        }
    }
};

#endif