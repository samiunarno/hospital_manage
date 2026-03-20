#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Medicine.h"

using namespace std;
class FileHandler {
public:
    static void savePatients(vector<Patient>& patients);
    static vector<Patient> loadPatients();

    static void saveDoctors(vector<Doctor>& doctors);
    static vector<Doctor> loadDoctors();

    static void saveMedicines(vector<Medicine>& medicines);
    static vector<Medicine> loadMedicines();
};


#endif