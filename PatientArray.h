#ifndef PATIENTARRAY_H
#define PATIENTARRAY_H

namespace PatientArrayTAD {

    struct Patient {
        char name[50];
        int severity;         // Positive number. The higher the value, the more severe.
        char arrival_time[6]; // Format "XXhYY"
    };
    
    struct PatientArray {
        Patient *patients; // Pointer to the array of patients
        int size;          // Current number of stored patients
        int capacity;      // Total capacity of the array
    };

    PatientArray *initializePatientArray();

    /**
     * @brief Displays the list of patients stored in the PatientArray structure.
     * 
     * Prints the capacity, current size, and the list of patients in the following format:
     * 
     * Capacity: <X>
     * Current size: <Y>
     * 
     * Patients:
     * * <Arrival_Time> | <Severity> | <Name>
     * * ...
     * 
     * If there are no patients, a message indicating that the list is empty is displayed.
     * 
     * @param pa Pointer to the PatientArray structure to be displayed.
     */
    void printPatients(PatientArray *pa);
    
    void insertPatient(PatientArray *pa, Patient p);
    int findNextPatient(PatientArray *pa);
    void removePatient(PatientArray *pa, int index);
    Patient popNextPatient(PatientArray *pa);
    void destroyPatientArray(PatientArray* patient_array);

}

#endif
