#include "PatientArray.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace PatientArrayTAD;

void testPatientArray(int cycle) {
    cout << "==== CICLO " << cycle << " ====\n";

    PatientArray* pa = initializePatientArray();
    
    cout << "== Inicialização do PatientArray ==\n";
    printPatients(pa);
    cout << endl;

    Patient p1 = {"Alice", 5, "10h30"};
    Patient p2 = {"Bob", 3, "09h15"};
    Patient p3 = {"Charlie", 8, "08h45"};
    Patient p4 = {"David", 6, "11h00"};
    Patient p5 = {"Eve", 10, "07h30"};
    Patient p6 = {"Frank", 7, "08h00"};
    Patient p7 = {"Grace", 4, "12h15"};
    Patient p8 = {"Hank", 9, "06h45"};

    cout << "== Inserindo Pacientes ==\n";
    insertPatient(pa, p1);
    insertPatient(pa, p2);
    insertPatient(pa, p3);
    insertPatient(pa, p4);
    insertPatient(pa, p5);
    insertPatient(pa, p6);
    insertPatient(pa, p7);
    insertPatient(pa, p8);
    printPatients(pa);
    cout << endl;

    cout << "== Buscando Paciente Mais Urgente ==\n";
    int most_urgent_index = findNextPatient(pa);
    if (most_urgent_index != -1) {
        cout << "Paciente mais urgente: " << pa->patients[most_urgent_index].name << endl;
    }
    cout << endl;

    cout << "== Removendo o Paciente Mais Urgente ==\n";
    removePatient(pa, most_urgent_index);
    printPatients(pa);
    cout << endl;

    cout << "== Removendo Pacientes com popNextPatient ==\n";
    for (int i = 0; i < 3; i++) {
        if (pa->size > 0) {
            Patient next = popNextPatient(pa);
            cout << "Paciente removido: " << next.name << endl;
            printPatients(pa);
            cout << endl;
        } else {
            cout << "Nenhum paciente restante!\n";
            break;
        }
    }

    cout << "== Reinserindo Pacientes Após Remoções ==\n";
    insertPatient(pa, {"Isaac", 6, "14h00"});
    insertPatient(pa, {"Julia", 3, "15h30"});
    insertPatient(pa, {"Kevin", 10, "05h50"});
    printPatients(pa);
    cout << endl;

    cout << "== Removendo Todos os Pacientes Restantes ==\n";
    while (pa->size > 0) {
        Patient next = popNextPatient(pa);
        cout << "Paciente removido: " << next.name << endl;
    }
    printPatients(pa);
    cout << endl;

    destroyPatientArray(pa);
    cout << "== Estrutura destruída com sucesso ==\n\n";
}

int main() {
    testPatientArray(1);
    testPatientArray(2);
    testPatientArray(3);

    return 0;
}
