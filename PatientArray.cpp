#include "PatientArray.h"
#include <iostream>

namespace PatientArrayTAD {

    PatientArray* initializePatientArray() {

        PatientArray* patient_array = new PatientArray; //allocating memory for the struct

        patient_array->capacity = 4;
        patient_array->size = 0;

        patient_array->patients = new Patient[patient_array->capacity]; //allocating memory for the array
        return patient_array;

        }

    void destroyPatientArray(PatientArray* patient_array) {

        if (patient_array) { //checks if it's null 
        delete[] patient_array->patients; //frees the array
            delete patient_array;  //frees the struct
        }

    }
        
    
    void printPatients(PatientArray *patient_array) {

        cout << "Capacity: " << patient_array->capacity << endl;
        cout << "Current size: " << patient_array->size << endl;
        cout << "Patients: " << endl;

        for(int i = 0 ; i < patient_array->size ; i++) {

            cout << "* <" << patient_array->patients[i].arrival_time 
            << "> | <" << patient_array->patients[i].severity 
            << "> | <" << patient_array->patients[i].name << ">" << endl;

        }
    }
}
