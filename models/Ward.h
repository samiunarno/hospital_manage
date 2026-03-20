#ifndef WARD_H
#define WARD_H
#include <iostream>
using namespace std;

class Ward {
    public:
    int id;
    string type;
    int deptId;

    Ward(){}
    Ward(int id, string type, int deptId){
        this->id = id;
        this->type = type;
        this->deptId = deptId;
    }
    void display(){
        cout << "Ward ID: " << id 
        << "Ward Type: " << type 
        << "Department ID: " << deptId << endl;
    }
};

#endif