#include <iostream>

#include "testes/testes_main.h"
#include "agenda/ArvoreAgenda.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int op;
    cout << "(1) - Todos os testes" << endl;
    cout << "(2) - Um teste" << endl;
    cout << "(3) - Agenda" << endl;
    cout << "Informe a opcao: ";
    cin >> op;
    cout << endl;

    switch( op ) {
        case 1:
            executaTodosOsTestes();
            break;
        case 2:
            executaUmTeste();
            break;
        case 3:
            ArvoreAgenda* agenda = new ArvoreAgenda();
            agenda->exec();
            break;

    }

	return 0;
}
