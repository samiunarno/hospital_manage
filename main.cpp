#include <iostream>
#include <limits>
#include "services/HospitalSystem.h"
#include "models/user.h"  // Make sure to include User.h

using namespace std;

int main() {
    HospitalSystem s;
    s.loadAllData();
    int choice;

    while (true) {
        cout << "\n--- Login / Register ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password, role;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Role (admin/doctor/patient): ";
            cin >> role;

            s.registerUser(User(username, password, role));
        }

        else if (choice == 2) {
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (s.loginUser(username, password)) {
                
if (s.getCurrentUser().role == "admin") {
    s.adminMenu();
}
else if (s.getCurrentUser().role == "doctor") {
    s.doctorMenu();
}
else if (s.getCurrentUser().role == "patient") {
    s.patientMenu();
}
                break;  // exit login loop
            }
            else {
                cout << "Invalid login. Please try again.\n";
            }
        }
        else if (choice == 0) {
            s.saveAllData();
            break;
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }

    while (true) {
        cout << "\n--- Hospital System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Department\n";
        cout << "3. Add Doctor\n";
        cout << "4. Add Bed\n";
        cout << "5. Assign Bed\n";
        cout << "6. Show Patients\n";
        cout << "7. Show Doctors\n";
        cout << "8. Show Beds\n";
        cout << "9. Check Dept Rule\n";
        cout << "10. Add Medical Record\n";
        cout << "11. Show Patient Records\n";
        cout << "12. Add Prescription\n";
        cout << "13. Show Prescriptions\n";
        cout << "14. Add Medicine\n";
        cout << "15. Show Medicines\n";
        cout << "16. Stock In\n";
        cout << "17. Stock Out\n";
        cout << "18. Search Patient\n";
        cout << "19. Search Doctor\n";
        cout << "20. Search Medicine\n";
        cout << "21. Total Patients Report\n";
        cout << "22. Bed Report\n";
        cout << "23. Medicine Report\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, gender;

            cout << "ID: "; cin >> id;
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Gender: "; cin >> gender;

            s.addPatient(Patient(id, name, age, gender));
        }

        else if (choice == 2) {
            int id;
            string name;

            cout << "Dept ID: "; cin >> id;
            cout << "Name: "; cin >> name;

            s.addDepartment(Department(id, name));
        }

        else if (choice == 3) {
            int id, deptId;
            string name;

            cout << "Doctor ID: "; cin >> id;
            cout << "Name: "; cin >> name;
            cout << "Dept ID: "; cin >> deptId;

            s.addDoctor(Doctor(id, name, deptId));
        }

        else if (choice == 4) {
            int id;
            cout << "Bed ID: ";
            cin >> id;

            s.addBed(Bed(id));
        }

        else if (choice == 5) {
            int pid;
            cout << "Patient ID: ";
            cin >> pid;

            s.assignBed(pid);
        }

        else if (choice == 6) {
            s.showPatients();
        }

        else if (choice == 7) {
            s.showDoctors();
        }

        else if (choice == 8) {
            s.showBeds();
        }

        else if (choice == 9) {
            s.checkDepartmentDoctorRule();
        }

        else if (choice == 10) {
            int pid;
            string type, details;

            cout << "Patient ID: ";
            cin >> pid;

            cout << "Type (registration/consultation/examination/inpatient): ";
            cin >> type;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Details: ";
            getline(cin, details);

            s.addRecord(MedicalRecord(pid, type, details));
        }

        else if (choice == 11) {
            int pid;
            cout << "Patient ID: ";
            cin >> pid;

            s.showRecords(pid);
        }

        else if (choice == 12) {
            int pid, did, n;

            cout << "Patient ID: ";
            cin >> pid;

            cout << "Doctor ID: ";
            cin >> did;

            Prescription p(pid, did);

            cout << "Number of medicines: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                string med;
                cout << "Medicine " << i + 1 << ": ";
                cin >> med;
                p.addMedicine(med);
            }

            s.addPrescription(p);
        }

        else if (choice == 13) {
            int pid;
            cout << "Patient ID: ";
            cin >> pid;

            s.showPrescriptions(pid);
        }

        else if (choice == 14) {
            int id;
            string name, category;

            cout << "Medicine ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Category: ";
            cin >> category;

            Medicine m(id, name, category);

            int n;
            cout << "Number of aliases: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                string a;
                cout << "Alias: ";
                cin >> a;
                m.addAlias(a);
            }

            s.addMedicine(m);
        }

        else if (choice == 15) {
            s.showMedicines();
        }

        else if (choice == 16) {
            int id, qty;
            cout << "Medicine ID: ";
            cin >> id;
            cout << "Quantity: ";
            cin >> qty;

            s.stockInMedicine(id, qty);
        }

        else if (choice == 17) {
            int id, qty;
            cout << "Medicine ID: ";
            cin >> id;
            cout << "Quantity: ";
            cin >> qty;

            s.stockOutMedicine(id, qty);
        }

        else if(choice == 18){
            int id;
            cout<<"Patient ID";
            cin>>id;
            s.searchPatient(id);
        }

        else if(choice == 19){
            int id;
            cout<<"Doctor ID: ";
            cin>>id;
            s.searchDoctor(id);
        }

        else if(choice == 20){
            string name;
            cout<<"Medicine Name: ";
            cin>>name;
            s.searchMedicine(name);
        }

        else if(choice == 21){
            s.reportTotalPatients();
        }

        else if(choice == 22){
            s.reportBedStatus();
        }

        else if(choice == 23){
            s.reportMedicineStock();
        }

        else if(choice ==0){
            s.saveAllData();
            break;
        }

        else {
            break;
        }
    }

    return 0;
}