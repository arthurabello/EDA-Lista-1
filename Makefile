all: patient_manager

patient_manager: main.o PatientArray.o
		g++ main.o PatientArray.o -o patient_manager

main.o: main.cpp PatientArray.cpp
		g++ -c main.cpp -o main.o

PatientArray.o: PatientArray.cpp PatientArray.h
		g++ -c PatientArray.cpp -o PatientArray.o

clean:
		rm -rf *.o patient_manager
