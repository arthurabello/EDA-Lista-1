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
     * @brief Initializes an empty PatientArray structure.
     * 
     * Allocates memory for a dynamic array of patients with an initial capacity of 4.
     * The structure starts empty (`size = 0`).
     * 
     * @return A pointer to the newly allocated PatientArray.
     */

    void printPatients(PatientArray *patient_array);

        /**
     * @brief Displays the list of patients stored in the PatientArray structure.
     * 
     * Prints the capacity, current size, and the list of patients in the following format:
     * 
     * ```
     * Capacity: <X>
     * Current size: <Y>
     * 
     * Patients:
     * * <Arrival_Time> | <Severity> | <Name>
     * * ...
     * ```
     * 
     * If there are no patients, a message indicating that the list is empty is displayed.
     * 
     * @param patient_array Pointer to the PatientArray structure to be displayed.
     */

    void insertPatient(PatientArray *patient_array, Patient patient);

        /**
     * @brief Inserts a new patient at the end of the array.
     * 
     * If the array reaches 75% of its current capacity, it dynamically expands
     * by doubling its size to accommodate more patients.
     * 
     * @param patient_array Pointer to the PatientArray structure where the patient will be inserted.
     * @param patient The Patient struct containing the patient's information.
     */

    void destroyPatientArray(PatientArray* patient_array);

        /**
     * @brief Frees the memory allocated for a PatientArray structure.
     * 
     * - Deallocates the dynamic array of patients.
     * - Deallocates the PatientArray structure itself.
     * - Ensures no memory leaks occur.
     * 
     * @param patient_array Pointer to the PatientArray structure to be destroyed.
     */


    int findNextPatient(PatientArray *pa);
    void removePatient(PatientArray *pa, int index);
    Patient popNextPatient(PatientArray *pa);

}

#endif
