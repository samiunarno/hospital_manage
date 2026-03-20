#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
using namespace std;

class Patient {
    public:
         int id;
         string name;
         int age;
         string gender;

         Patient(){}
          Patient(int id, string name, int age, string gender) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
            
            void display(){
                cout<< "Patient ID :"<<id
                << "Patient Name :"<<name
                << "Patient Age :"<<age
                << "Patient Gender :"<<gender<<endl;
            }
         }

;

#endif