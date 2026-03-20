#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
using namespace std;

class Department {
    public:
    int id;
    string name;

    Department(){}
    Department(int id, string name){
        this->id = id;
        this->name = name;
    }
    void display(){
        cout << "Department ID: " << id 
        << "Department Name: " << name << endl;
    }
};

#endif