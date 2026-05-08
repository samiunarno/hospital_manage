#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include "../models/Patient.h"
#include "../models/Doctor.h"
#include "../models/Medicine.h"
#include "../models/user.h"

using namespace std;
class FileHandler {
public:
    static void saveUsers(const std::vector<User>& users);
    static std::vector<User> loadUsers();
    static void savePatients(vector<Patient>& patients);
    static vector<Patient> loadPatients();

    static void saveDoctors(vector<Doctor>& doctors);
    static vector<Doctor> loadDoctors();

    static void saveMedicines(vector<Medicine>& medicines);
    static vector<Medicine> loadMedicines();
};


#endif