#include "PatientArray.h"
#include <iostream>
#include <cstring>

namespace PatientArrayTAD {

    PatientArray* initializePatientArray() {

        PatientArray* patient_array = new PatientArray;  //allocating memory for the struct
        if (!patient_array) return nullptr;

        patient_array->capacity = 4;
        patient_array->size = 0;

        patient_array->patients = new Patient[patient_array->capacity]; //allocating memory for the array
        return patient_array;

        }

    void destroyPatientArray(PatientArray* patient_array) {

        if (patient_array) { //checks if it's null 
            delete[] patient_array->patients; //frees the array
            delete patient_array; //frees the struct
        }

    }
    
    void printPatients(PatientArray *patient_array) {
        if (!patient_array) return; //checking for unvalid entries

        std::cout << "Capacity: " << patient_array->capacity << std::endl;
        std::cout << "Current size: " << patient_array->size << std::endl;
        std::cout << "Patients: " << std::endl;

        for(int i = 0; i < patient_array->size; i++) {
            std::cout << "* <" << patient_array->patients[i].arrival_time 
                      << "> | <" << patient_array->patients[i].severity 
                      << "> | <" << patient_array->patients[i].name << ">" << std::endl;
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
    
    int comparePatients(Patient patient_1, Patient patient_2) {
        if (patient_1.severity > patient_2.severity) return 1;
        if (patient_1.severity < patient_2.severity) return -1;
        return strcmp(patient_1.arrival_time, patient_2.arrival_time) < 0 ? 1 : -1; //checking the arrival time
    }
    
    int findNextPatient(PatientArray *patient_array) {
        if (!patient_array || patient_array->size == 0) return -1;

        int most_urgent_index = 0;

        for (int i = 1; i < patient_array->size; i++) {
            if (comparePatients(patient_array->patients[i], patient_array->patients[most_urgent_index]) > 0) {
                most_urgent_index = i;
            }
        }
        return most_urgent_index;
    }

    void removePatient(PatientArray *patient_array, int index_of_patient_to_be_removed) {
        if (!patient_array || index_of_patient_to_be_removed < 0 || index_of_patient_to_be_removed >= patient_array->size) {
            return; 
        }
    
        for (int i = index_of_patient_to_be_removed; i < patient_array->size - 1; i++) {
            patient_array->patients[i] = patient_array->patients[i + 1];
        }
    
        patient_array->size--;
    
        if (patient_array->size <= patient_array->capacity / 4 && patient_array->capacity > 4) {
            int new_capacity = patient_array->capacity / 2;
            Patient* new_array = new Patient[new_capacity];
    
            std::copy(patient_array->patients, patient_array->patients + patient_array->size, new_array);
    
            delete[] patient_array->patients;
            patient_array->patients = new_array;
            patient_array->capacity = new_capacity;
    
       }
    }
    
    Patient popNextPatient(PatientArray *patient_array) {
        if (!patient_array || patient_array->size == 0) {
            static const Patient EMPTY_PATIENT = { "", 0, "00h00" }; //returns empty patient
            return EMPTY_PATIENT;
        }

        int index_of_most_urgent = findNextPatient(patient_array);
        Patient next_patient = patient_array->patients[index_of_most_urgent];

        removePatient(patient_array, index_of_most_urgent);
        return next_patient;
    }
}