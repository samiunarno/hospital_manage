#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h> 

void createDirectoryIfNotExists(const string& dir) {
    struct stat info;
    if (stat(dir.c_str(), &info) != 0) {
        // Directory does not exist, create it
        cout << "Directory does not exist. Creating directory: " << dir << endl;
        mkdir(dir.c_str(), 0777);  
    }
}

void FileHandler::savePatients(vector<Patient>& patients) {
    ofstream file("../data/patients.txt");

    for (auto &p : patients) {
        file << p.id << "," << p.name << "," << p.age << "," << p.gender << endl;
    }

    file.close();
}

vector<Patient> FileHandler::loadPatients() {
    vector<Patient> list;
    ifstream file("../data/patients.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age, gender;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, gender, ',');

        list.push_back(Patient(stoi(id), name, stoi(age), gender));
    }

    return list;
}
void FileHandler::saveDoctors(vector<Doctor>& doctors) {
    ofstream file("../data/doctors.txt");

    for (auto &d : doctors) {
        file << d.id << "," << d.name << "," << d.deptId << endl;
    }

    file.close();
}
vector<Doctor> FileHandler::loadDoctors() {
    vector<Doctor> list;
    ifstream file("../data/doctors.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, dept;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, dept, ',');

        list.push_back(Doctor(stoi(id), name, stoi(dept)));
    }

    return list;
}

void FileHandler::saveUsers(const vector<User>& users) {
    ofstream file("../data/user.txt");

    if (!file.is_open()) {
        cout << "Error opening users file for writing." << endl;
        return;
    }

    for (const auto &u : users) {
        file << u.username << "," << u.password << "," << u.role << endl;
    }

    file.close();
}

vector<User> FileHandler::loadUsers() {
    vector<User> list;
    ifstream file("../data/user.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, role;

        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');

        list.push_back(User(username, password, role));
    }

    return list;
}

void FileHandler::saveMedicines(vector<Medicine>& medicines) {
    ofstream file("../data/medicines.txt");

    for (auto &m : medicines) {
        file << m.id << "," << m.name << "," << m.category << "," << m.stock << endl;
    }

    file.close();
}

vector<Medicine> FileHandler::loadMedicines() {
    vector<Medicine> list;
    ifstream file("../data/medicines.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, cat, stock;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, cat, ',');
        getline(ss, stock, ',');

        Medicine m(stoi(id), name, cat);
        m.stock = stoi(stock);

        list.push_back(m);
    }

    return list;
}