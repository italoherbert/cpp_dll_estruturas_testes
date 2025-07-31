
#include "testes_main.h"

#include "arvore_testes.h"

#include <iostream>

using namespace std;

void executaTodosOsTestes() {
    bool sucesso = arvore_testes::executaTodosOsTestes();
    if ( sucesso )
        cout << "Todos os testes executados com sucesso." << endl;
}
