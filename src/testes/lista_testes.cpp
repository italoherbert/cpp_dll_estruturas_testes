
#include "lista_testes.h"

#include "estrutura/IDObjeto.h"
#include "estrutura/IDLista.h"

#include "testesunit/testesunit.h"
#include "testesunit/Testes.h"

#include <iostream>
#include <vector>

using namespace std;

namespace lista_testes {

    void insereTest();
    void insereNoInicioTest();
    void insereNoFimTest();
    void iteradorTest();

    vector<int> criaIDs();
    IDLista* criaIDLista( vector<int> );
    IDObjeto* criaIDObjeto( int );
    vector<int> vectorIDs( IDLista* );

    bool executaTodosOsTestes() {
        Testes testes( "lista" );
        testes.add( "insereTeste", insereTest );
        testes.add( "insereNoInicioTeste", insereNoInicioTest );
        testes.add( "insereNoFimTeste", insereNoFimTest );
        testes.add( "iteradorTeste", iteradorTest );
        return testes.executa();
    }

    void insereTest() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void insereNoInicioTest() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        lista->insereNoInicio( criaIDObjeto( 0 ) );
        ids.insert( ids.begin(), 0 );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void insereNoFimTest() {
        vector<int> ids = criaIDs();
        IDLista* lista = criaIDLista( ids );

        lista->insereNoFim( criaIDObjeto( 0 ) );
        ids.push_back( 0 );

        vector<int> inseridos = vectorIDs( lista );

        testesunit::devemSerIguais( ids, inseridos );

        delete lista;
    }

    void iteradorTest() {
        vector<int> ids = criaIDs();
        vector<int> inseridos;

        IDLista* lista = criaIDLista( ids );

        Iterador* it = lista->it();
        while( it->temProx() )
            inseridos.push_back( ((IDObjeto*)it->prox())->getId() );

        testesunit::devemSerIguais( ids, inseridos );
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
