#include <iostream>

#include "testes/testes_main.h"
#include "agenda/ArvoreAgenda.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int op;
    cout << "(1) - Testes" << endl;
    cout << "(2) - Agenda" << endl;
    cout << "Informe a opcao: ";
    cin >> op;
    cout << endl;

    switch( op ) {
        case 1:
            executaTodosOsTestes();
            break;
        case 2:
            ArvoreAgenda* agenda = new ArvoreAgenda();
            agenda->exec();
            break;

    }

	return 0;
}
