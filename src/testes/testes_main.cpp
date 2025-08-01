
#include "testes_main.h"

#include "arvore_testes.h"
#include "lista_testes.h"

#include "testesunit/GrupoDeTestes.h"

void executaTodosOsTestes() {
    GrupoDeTestes* testes = new GrupoDeTestes();
    testes->add( arvore_testes::executaTodosOsTestes );
    testes->add( lista_testes::executaTodosOsTestes );
    testes->executa();
}
