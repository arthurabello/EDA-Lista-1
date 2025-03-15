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

    void insertPatient(PatientArray *patient_array, Patient patient) {

        if (!patient_array) return; // if not nullptr
    
        if (patient_array->size >= (3.0 / 4.0) * patient_array->capacity) { // checks if capacity is at 75% full
            int new_patient_array_capacity = patient_array->capacity * 2;
            Patient* new_patient_array = new Patient[new_patient_array_capacity]; // allocates a bigger one
    
            for (int i = 0; i < patient_array->size; i++) {
                new_patient_array[i] = patient_array->patients[i]; // sends everyone to the new array
            }
    
            delete[] patient_array->patients; // frees the previous one
            patient_array->patients = new_patient_array; // changes the pointer to the new array
            patient_array->capacity = new_patient_array_capacity; // updates the capacity
        }
    
        patient_array->patients[patient_array->size] = patient; // inserts the new fella
        patient_array->size++;  // updates the size (one more fella)
    }    
    
}
