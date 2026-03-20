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



