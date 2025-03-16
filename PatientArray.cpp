#include "PatientArray.h"
#include <iostream>
#include <cstring>

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
        patient_array->size++;  // updates the size (one more     int findNextPatient(PatientArray *pa);fella)
    }
    
    int comparePatients(Patient patient_1, Patient patient_2) { 
        if (patient_1.severity > patient_2.severity) {
            return 1;

        } else if (patient_1.severity < patient_2.severity) {
            return -1;
        }
        return 0; //same severity
    }
    
    int findNextPatient(PatientArray *patient_array) {
        if (!patient_array || patient_array->size == 0) return -1; 

        int most_urgent_index = 0; 

        for (int i = 1; i < patient_array->size; i++) {
            int comparison = comparePatients(patient_array->patients[i], patient_array->patients[most_urgent_index]);

            if (comparison == 1) {
                most_urgent_index = i; //more urgent than the previous one

            } else if (comparison == 0) {
                if (strcmp(patient_array->patients[i].arrival_time, patient_array->patients[most_urgent_index].arrival_time) < 0) {
                    most_urgent_index = i; 
                }
            }
        }
        return most_urgent_index;
    }

    void removePatient(PatientArray *patient_array, int index_of_patient_to_be_removed) {
        if (!patient_array || index_of_patient_to_be_removed < 0 || index_of_patient_to_be_removed >= patient_array->size) { //checking for unvalid entries
            return; 
        }
    
        for (int i = index_of_patient_to_be_removed; i < patient_array->size - 1; i++) {
            patient_array->patients[i] = patient_array->patients[i + 1]; //realocating every entry to the right and overwriting the one to be deleted
        }
    
        patient_array->size--; //updating the size
    
        if (patient_array->size < (patient_array->capacity / 4) && patient_array->capacity > 4) {
            int new_capacity = patient_array->capacity / 2;
            Patient* new_array = new Patient[new_capacity]; //creating a new array with half the size and sending every patient to the new array

            for (int i = 0; i < patient_array->size; i++) {
                new_array[i] = patient_array->patients[i];
            }
    
            delete[] patient_array->patients; //deleting the old array
            patient_array->patients = new_array;
            patient_array->capacity = new_capacity;
        }
    }
    

