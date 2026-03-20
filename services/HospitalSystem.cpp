#include "HospitalSystem.h"
#include <iostream>

using namespace std;

void HospitalSystem::addPatient(Patient p){
    patients.push_back(p);
}
void HospitalSystem::showPatients(){
    for(auto &p : patients){
        p.display();
    }
}
void HospitalSystem::addDepartment(Department d) {
    departments.push_back(d);
}

void HospitalSystem::showDepartments() {
    for (auto &d : departments) {
        d.display();
    }
}

void HospitalSystem::addDoctor(Doctor d) {
    doctors.push_back(d);
}

void HospitalSystem::showDoctors() {
    for (auto &d : doctors) {
        d.display();
    }
}

void HospitalSystem::checkDepartmentDoctorRule() {
    for (auto &dept : departments) {
        int count = 0;

        for (auto &doc : doctors) {
            if (doc.deptId == dept.id) {
                count++;
            }
        }
        cout << dept.name << " -> " << count << " doctors found" << endl;
        if (count < 3) {
            cout << "Warning: Less than 3 doctors in department " << dept.name << endl;
        }
        else {
            cout << "Sufficient doctors in department " << dept.name << endl;
        };
    }
}
void HospitalSystem::addWard(Ward w) {
    wards.push_back(w);
}

void HospitalSystem::showWards() {
    for (auto &w : wards) {
        w.display();
    }
}

void HospitalSystem::addBed(Bed b) {
    beds.push_back(b);
}

void HospitalSystem::showBeds() {
    for (auto &b : beds) {
        b.display();
    }
}

void HospitalSystem::assignBed(int patientId) {
    for (auto &b : beds) {
        if (!b.occupied) {
            b.assignPatient(patientId);
            cout << "Bed assigned!\n";
            return;
        }
    }
    cout << "No available beds!\n";
}

void HospitalSystem::releaseBed(int bedId) {
    for (auto &b : beds) {
        if (b.id == bedId) {
            b.release();
            cout << "Bed released!\n";
            return;
        }
    }
    cout << "Bed not found!\n";
}

void HospitalSystem::addMedicine(Medicine m) {
    medicines.push_back(m);
}

void HospitalSystem::showMedicines() {
    for (auto &m : medicines) {
        m.display();
    }
}

void HospitalSystem::addRecord(MedicalRecord r) {
    records.push_back(r);
}
void HospitalSystem::showRecords(int patientId) {
    for (auto &r : records) {
        if (r.patientId == patientId) {
            r.display();
        }
    }
}
void HospitalSystem::addPrescription(Prescription p) {
    prescriptions.push_back(p);
}

void HospitalSystem::showPrescriptions(int patientId) {
    for (auto &p : prescriptions) {
        if (p.patientId == patientId) {
            p.display();
        }
    }
}

void HospitalSystem::stockInMedicine(int medId, int qty) {
    for (auto &m : medicines) {
        if (m.id == medId) {
            m.stockIn(qty);
            cout << "Stock added!\n";
            return;
        }
    }
    cout << "Medicine not found!\n";
}

void HospitalSystem::stockOutMedicine(int medId, int qty) {
    for (auto &m : medicines) {
        if (m.id == medId) {
            m.stockOut(qty);
            return;
        }
    }
    cout << "Medicine not found!\n";
}
void HospitalSystem::addPrescription(Prescription p) {
    prescriptions.push_back(p);

    
    for (auto &medName : p.medicines) {
        for (auto &m : medicines) {
            if (m.name == medName) {
                m.stockOut(1); 
            }
        }
    }

    cout << "Prescription added & stock updated!\n";
}

void HospitalSystem::searchPatient(int id){
    for(auto &p : patients){
        if(p.id == id){
            p.display();
            return;
        }
    }
    cout << "Patient not found!\n";
}

void HospitalSystem::searchDoctor(int id){
    for(auto &d : doctors){
        if(d.id == id){
            d.display();
            return;
        }
    }
    cout << "Doctor not found!\n";
}

void HospitalSystem::searchMedicine(string name){
    for(auto &m : medicines){
        if(m.name == name){
            m.display();
            return;
        }
        for (auto &a : m.aliases) {
            if (a == name) {
                m.display();
                return;
            }
        }
    }
    
    cout << "Medicine not found!\n";
}

void HospitalSystem::reportTotalPatients() {
    cout << "Total patients: " << patients.size() << endl;
}

void HospitalSystem::reportBedStatus() {
    int occupied = 0;
    for (auto &b : beds) {
        if (b.occupied) {
            occupied++;
        }
    }
    cout << "Total Beds: " << beds.size() << endl;
    cout << "Occupied: " << occupied << endl;
    cout << "Available: " << beds.size() - occupied << endl;
}

void HospitalSystem::reportMedicineStock() {
    for (auto &m : medicines) {
        cout << "Medicine: " << m.name << ", Stock: " << m.stock << endl;
    }
}

void HospitalSystem::saveAllData() {
    FileHandler::savePatients(patients);
    FileHandler::saveDoctors(doctors);
    FileHandler::saveMedicines(medicines);

    cout << "Data Saved Successfully!" << endl;
}

void HospitalSystem::loadAllData() {
    patients = FileHandler::loadPatients();
    doctors = FileHandler::loadDoctors();
    medicines = FileHandler::loadMedicines();

    cout << "Data Loaded Successfully!" << endl;
}
void HospitalSystem::registerUser(User u) {
    for (auto &user : users) {
        if (user.username == u.username) {
            cout << "Username exists!\n";
            return;
        }
    }

    users.push_back(u);
    cout << "Registered successfully!\n";
}

bool HospitalSystem::loginUser(string username, string password) {
    for (auto &u : users) {
        if (u.username == username && u.password == password) {
            currentUser = u;
            cout << "Login success! Role: " << u.role << endl;
            return true;
        }
    }

    cout << "Invalid login!\n";
    return false;
}