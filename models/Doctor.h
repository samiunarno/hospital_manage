#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

class Doctor{
    public:
    int id;
    string name;
    int deptId;

    Doctor(){}
    Doctor(int id, string name, int deptId){
        this->id = id;
        this->name = name;
        this->deptId = deptId;
    }
    void display(){
        cout << "Doctor ID: " << id 
        << "Doctor Name: " << name 
        << "Department ID: " << deptId << endl;
    }
};

#endif