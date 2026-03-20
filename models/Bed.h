#ifndef BED_H
#define BED_H

#include <iostream>
using namespace std;

class Bed {
public:
    int id;
    bool occupied;
    int patientId;

    Bed() {
        occupied = false;
        patientId = -1;
    }

    Bed(int id) {
        this->id = id;
        occupied = false;
        patientId = -1;
    }

    void assignPatient(int pid) {
        occupied = true;
        patientId = pid;
    }

    void release() {
        occupied = false;
        patientId = -1;
    }

    void display() {
        cout << "Bed ID: " << id
             << (occupied ? " (Occupied)" : " (Available)") << endl;
    }
};

#endif