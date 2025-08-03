
#include "testes_main.h"

#include "arvore_testes.h"
#include "lista_testes.h"

#include "testesunit/TestesSuite.h"
#include "testesunit/TestesMenu.h"

#include <iostream>

using namespace std;

void executaTodosOsTestes() {
    TestesSuite* testes = new TestesSuite();
    testes->add( arvore_testes::executaTodosOsTestes() );
    testes->add( lista_testes::executaTodosOsTestes() );

    TestesResult* result = testes->executa();
    cout << result->getMensagem();
}

void executaUmTeste() {
    TestesSuite* testes = new TestesSuite();
    testes->add( arvore_testes::executaTodosOsTestes() );
    testes->add( lista_testes::executaTodosOsTestes() );

    TestesMenu* menu = new TestesMenu( testes );
    menu->executa();
}
