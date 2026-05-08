#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include <vector>
#include <string>
#include "../models/Patient.h"
#include "../models/Doctor.h"
#include "../models/Department.h"
#include "../models/Ward.h"
#include "../models/Bed.h"
#include "../models/Medicine.h"
#include "../models/MedicalRecord.h"
#include "../models/Prescription.h"
#include "../models/user.h"
#include "../utils/FileHandler.h"

class HospitalSystem {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Department> departments;
    std::vector<Ward> wards;
    std::vector<Bed> beds;
    std::vector<Medicine> medicines;
    std::vector<MedicalRecord> records;
    std::vector<Prescription> prescriptions;
    std::vector<User> users;

    User currentUser;

public:
    // Methods
    void addPatient(Patient p);
    void showPatients();
    void addDepartment(Department d);
    void showDepartments();
    void addDoctor(Doctor d);
    void showDoctors();
    void checkDepartmentDoctorRule(); // FIX: Added missing declaration
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
    void searchMedicine(std::string name);
    void reportTotalPatients();
    void reportBedStatus();
    void reportMedicineStock();
    void saveAllData();
    void loadAllData();
    void registerUser(User u);
    bool loginUser(std::string username, std::string password);
    void showUsers();
    void deleteUser(std::string username);

    // Getter for currentUser
    User getCurrentUser() const;

    // Menu Methods
    void adminMenu();
    void doctorMenu();
    void patientMenu();
};

#endif