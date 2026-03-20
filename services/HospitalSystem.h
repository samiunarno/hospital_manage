#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Department.h"
#include "Ward.h"
#include "Bed.h"
#include "Medicine.h"
#include "MedicalRecord.h"
#include "Prescription.h"
#include "utils/FileHandler.h"
#include "user.h"

using namespace std;

class HospitalSystem {
    private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Department> departments;
    vector<Ward> wards;
    vector<Bed> beds;
    vector<Medicine> medicines;
    vector<MedicalRecord> records;
    vector<Prescription> prescriptions;
    vector<User> users;
    User currentUser;

    public:
    void addPatient(Patient p);
    void showPatients();

    void addDepartment(Department d);
    void showDepartments();

    void addDoctor(Doctor d);
    void showDoctors();
    void checkDepartmentDoctorRule();

    void addWard(Ward w);
    void showWards();

    void addBed(Bed b);
    void showBeds();
    void assignBed(int patientId);
    void releaseBed(int bedId);

    void addMedicine(Medicine m);
    void showMedicines();

    void addRecord(MedicalRecord r);
    void showRecords(int patientId);

    void addPrescription(Prescription p);
    void showPrescriptions(int patientId);

    void stockInMedicine(int medId, int qty);
    void stockOutMedicine(int medId, int qty);

    void searchPatient(int id);
    void searchDoctor(int id);
    void searchMedicine(string name);
    void reportTotalPatients();
    void reportBedStatus();
    void reportMedicineStock();

    void saveAllData();
    void loadAllData();

    void registrerUser(User u);
    bool loginUser(string username, string password);

    void adminMenu();
    void doctorMenu();
    void patientMenu();

    void showusers();
    void deleteUser(string username);
};
#endif
