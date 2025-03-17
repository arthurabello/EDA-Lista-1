# List 1 - TAD PatientArray

## Introduction
This repository contains the solution for [**List 1 - TAD PatientArray**](https://github.com/matwerner/fgv-ed/blob/main/listas/lista1.md), developed in **C++**, The objective of this project is to implement an Abstract Data Type (**ADT**) to store and dynamically manage a list of patients, ensuring efficient memory usage.

## Data Structures

### `Patient` Structure
Each patient is represented by the following structure:

```cpp
struct Patient {
    char name[50];       // Patient's name
    int severity;        // Severity index (higher value indicates more severe condition)
    char arrival_time[6]; // Arrival time in the format "XXhYY"
};
```

### `PatientArray` Structure
The `PatientArray` structure manages a dynamic array of patients and follows these rules:
- Initially, it has a capacity of **4 slots**.
- When the array reaches **75% of its capacity**, its size is **doubled**.
- When the occupancy falls below **25% of capacity**, the size is **halved**, but never smaller than **4 slots**.

```cpp
struct PatientArray {
    Patient *patients; // Pointer to the dynamic array of patients
    int size;          // Current number of stored patients
    int capacity;      // Total capacity of the array
};
```

## File Structure
The code is organized as follows:
- [**`main.cpp`**](https://github.com/arthurabello/eda-lista-1/blob/main/main.cpp): Main file containing tests for all implemented functions.
- [**`PatientArray.h`**](https://github.com/arthurabello/eda-lista-1/blob/main/PatientArray.h): Header file with declarations of functions and structures of the ADT.
- [**`PatientArray.cpp`**](https://github.com/arthurabello/eda-lista-1/blob/main/PatientArray.cpp): Implementation of the ADT functions.

## Implemented Features
The `PatientArray` library includes the following functions:

### 1. ADT Initialization
Initializes an empty `PatientArray` with an initial capacity of **4 patients**.
```cpp
PatientArray * initializePatientArray();
```

### 2. Displaying the List of Patients
Displays stored patients, formatting the output correctly.
```cpp
void printPatients(PatientArray *patient_array);
```
Expected output format:
```
Capacity: <X>
Current size: <Y>

Patients:
* <Time> | <Severity> | <Name>
* ...
```

### 3. Inserting Patients
Adds a patient to the end of the array and expands capacity if necessary.
```cpp
void insertPatient(PatientArray *patient_array, Patient patient);
```

### 4. Finding the Next Patient to be Attended
Finds the index of the most urgent patient based on severity and arrival time.
```cpp
int findNextPatient(PatientArray *patient_array);
```

### 5. Removing Patients
Removes a patient from a specific position and reduces the array capacity when necessary.
```cpp
void removePatient(PatientArray *patient_array, int index_of_patient_to_be_removed);
```

### 6. Removing and Returning the Next Patient
Finds and removes the most urgent patient, returning them by value.
```cpp
Patient popNextPatient(PatientArray *patient_array);
```

## Compilation and Execution
To compile the code, use the [**Makefile**](https://github.com/arthurabello/eda-lista-1/blob/main/Makefile) built to compile and run the code, do this by using:

```sh
make
```

To execute the program:

```sh
./patient_manager
```

## Author
This repository was developed by **[me](https://github.com/arthurabello)** for the [**Data Structures and Algorithms**](https://github.com/matwerner/fgv-ed) course.

## License
This project is licensed under the [**GNU** License](https://github.com/arthurabello/EDA-Lista-1/blob/main/LICENSE)