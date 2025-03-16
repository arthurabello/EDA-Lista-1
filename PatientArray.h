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

    int findNextPatient(PatientArray *patient_array);

        /**
     * @brief Finds the index of the next patient to be attended.
     * 
     * The function determines the most urgent patient based on severity.
     * If two or more patients have the same severity, the patient who arrived first is chosen.
     * 
     * @param patient_array Pointer to the PatientArray structure.
     * @return The index of the most urgent patient, or -1 if the list is empty.
     */

    int comparePatients(Patient patient_1, Patient patient_2);

        /**
     * @brief Compares two patients based on severity.
     * 
     * A patient with higher severity is considered more urgent.
     * If both have the same severity, they are considered equal.
     * 
     * @param patient_1 First patient to compare.
     * @param patient_2 Second patient to compare.
     * @return 1 if patient_1 is more urgent, -1 if patient_2 is more urgent, 0 if they are equally urgent.
     */

    void removePatient(PatientArray *patient_array, int index_of_patient_to_be_removed);

        /**
     * @brief Removes a patient from the PatientArray at the specified index.
     * 
     * - All subsequent patients are shifted left to maintain contiguity.
     * - The array size is reduced by 1.
     * - If the number of patients falls below 25% of the capacity, the array shrinks
     *   by half, ensuring that its capacity never drops below 4.
     * 
     * @param patient_array Pointer to the PatientArray structure.
     * @param index_of_patient_to_be_removed The index of the patient to be removed.
     */

    Patient popNextPatient(PatientArray *patient_array);

        /**
     * @brief Removes and returns the next patient to be attended.
     * 
     * - Finds the most urgent patient using `findNextPatient()`.
     * - Removes the patient from the array while maintaining contiguity.
     * - Returns the removed patient.
     * - If the array is empty, returns a default "empty" patient.
     * 
     * @param patient_array Pointer to the PatientArray structure.
     * @return The Patient struct of the removed patient.
     */

}

#endif
