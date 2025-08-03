
#include "lista_testes.h"

#include "estrutura/IDObjeto.h"
#include "estrutura/IDLista.h"
#include "estrutura/perc/VectorIDPercIT.h"

#include "testesunit/testesunit.h"
#include "testesunit/TestesGrupo.h"

#include "util/vectutil.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace lista_testes {

    void insereTeste();
    void insereNoInicioTeste();
    void insereNoFimTeste();
    void iteradorTeste();
    void inversoIteradorTeste();
    void buscaTeste();
    void alteraTeste();
    void deletaTeste();
    void popTeste();
    void getTeste();
    void percorreTeste();
    void percorreOrdemInversaTeste();

    vector<int> criaIDs();
    IDLista* criaIDLista( vector<int> );
    IDObjeto* criaIDObjeto( int );
    vector<int> vectorIDs( IDLista* );

    TestesGrupo* executaTodosOsTestes() {
        TestesGrupo* testes = new TestesGrupo( "lista" );
        testes->add( "insereTeste", insereTeste );
        testes->add( "insereNoInicioTeste", insereNoInicioTeste );
        testes->add( "insereNoFimTeste", insereNoFimTeste );
        testes->add( "iteradorTeste", iteradorTeste );
        testes->add( "inversoIteradorTeste", inversoIteradorTeste );
        testes->add( "buscaTeste", buscaTeste );
        testes->add( "alteraTeste", alteraTeste );
        testes->add( "deletaTeste", deletaTeste );
        testes->add( "popTeste", popTeste );
        testes->add( "getTeste", getTeste );
        testes->add( "percorreTeste", percorreTeste );
        testes->add( "percorreOrdemInversaTeste", percorreOrdemInversaTeste );
        return testes;
    }

    void insereTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void insereNoInicioTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        lista->insereNoInicio( criaIDObjeto( 0 ) );
        ids.insert( ids.begin(), 0 );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void insereNoFimTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        lista->insereNoFim( criaIDObjeto( 0 ) );
        ids.push_back( 0 );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void iteradorTeste() {
        vector<int> ids = criaIDs();
        vector<int> inseridos;

        IDLista* lista = criaIDLista( ids );

        Iterador* it = lista->it();
        while( it->temProx() )
            inseridos.push_back( ((IDObjeto*)it->prox())->getId() );

        testesunit::devemSerIguais( ids, inseridos );
    }

    void inversoIteradorTeste() {
        vector<int> ids = criaIDs();
        vector<int> inseridos;

        IDLista* lista = criaIDLista( ids );

        Iterador* it = lista->inversoIt();
        while( it->temProx() )
            inseridos.push_back( ((IDObjeto*)it->prox())->getId() );

        reverse( ids.begin(), ids.end() );

        testesunit::devemSerIguais( ids, inseridos );
    }

    void buscaTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        IDObjeto* obj = lista->busca( 5 );
        testesunit::devemSerIguais( obj->getId(), 5 );

        obj = lista->busca( 0 );
        testesunit::deveSerNulo( obj );
    }

    void alteraTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        IDObjeto* obj = criaIDObjeto( 5 );
        lista->altera( obj );

        IDObjeto* obj2 = lista->busca( 5 );

        testesunit::devemSerIguais( obj, obj2 );
    }

    void deletaTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        testesunit::devemSerIguais( lista->getTamanho(), 10 );

        lista->deleta( 1 );
        lista->deleta( 10 );
        lista->deleta( 5 );

        ids.erase( ids.begin() + vectutil::indice( ids, 1 ) );
        ids.erase( ids.begin() + vectutil::indice( ids, 10 ) );
        ids.erase( ids.begin() + vectutil::indice( ids, 5 ) );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        bool deletado = lista->deleta( 0 );

        testesunit::deveSerFalso( deletado );
        testesunit::devemSerIguais( ids, inseridos );

        lista->deletaTodos();

        testesunit::devemSerIguais( lista->getTamanho(), 0 );
        testesunit::devemSerIguais( lista->tamanho(), 0 );

        delete lista;
    }

    void popTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        IDObjeto* obj = (IDObjeto*)lista->pop();

        testesunit::deveSerNaoNulo( obj );
        testesunit::devemSerIguais( obj->getId(), 1 );

        ids.erase( ids.begin() + vectutil::indice( ids, 1 ) );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );
    }

    void getTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        Objeto* obj = lista->get( 5 );

        testesunit::deveSerNaoNulo( obj );
        testesunit::devemSerIguais( ((IDObjeto*)obj)->getId(), 6 );

        obj = lista->get( -1 );

        testesunit::deveSerNulo( obj );

        obj = lista->get( 10 );

        testesunit::deveSerNulo( obj );
    }

    void percorreTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        VectorIDPercIT* vperc = new VectorIDPercIT();
        lista->percorre( vperc );

        testesunit::devemSerIguais( vperc->getVector(), ids );
    }

    void percorreOrdemInversaTeste() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        reverse( ids.begin(), ids.end() );

        VectorIDPercIT* vperc = new VectorIDPercIT();
        lista->percorreOrdemInversa( vperc );

        testesunit::devemSerIguais( vperc->getVector(), ids );
    }

    vector<int> criaIDs() {
        vector<int> ids = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        return ids;
    }

    IDLista* criaIDLista( vector<int> ids ) {
        IDLista* lista = new IDLista();
        int tam = ids.size();
        for( int i = 0; i < tam; i++ )
            lista->insere( criaIDObjeto( ids[ i ] ) );
        return lista;
    }

    IDObjeto* criaIDObjeto( int id ) {
        IDObjeto* obj = new IDObjeto();
        obj->setId( id );
        return obj;
    }

    vector<int> vectorIDs( IDLista* lista ) {
        vector<int> ids;

        Iterador* it = lista->it();
        while( it->temProx() )
            ids.push_back( ((IDObjeto*)it->prox())->getId() );

        return ids;
    }

}
