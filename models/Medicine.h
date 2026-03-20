#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <vector>
using namespace std;

class Medicine {
public:
    int id;
    int stock;
    string name;
    string category;
    vector<string> aliases;

    Medicine() {}

    Medicine(int id, string name, string category) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->stock = 0;
    }

    void addAlias(string alias) {
        aliases.push_back(alias);
    }
    void stockIn(int qty){
        stock += qty;
    }

    void stockOut(int qty){
        if(stock >= qty){
            stock -= qty;
        }
        else{
            cout<<"Not Enough Stock \n";
        }
    }


    void display() {
        cout << "Medicine ID: " << id
             << ", Name: " << name
             << ", Category: " << category 
             << ", Stock: " << stock << endl;

        if (!aliases.empty()) {
            cout << "Aliases: ";
            for (auto &a : aliases) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
};

#endif