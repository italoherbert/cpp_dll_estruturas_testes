
#include "arvore_testes.h"

#include "estrutura/IDArvore.h"
#include "estrutura/IDObjeto.h"
#include "estrutura/PercIT.h"
#include "estrutura/it/Iterador.h"
#include "estrutura/comp/IDCampoComparador.h"

#include "util/vectutil.h"
#include "util/testesutil.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>

using namespace std;

IDObjeto* criaIDObjeto( int );
IDArvore* criaArvore( vector<int> );

vector<int> criaIDs();

namespace arvore_testes {

    bool insereTeste();
    bool iteradorTeste();
    bool alteraTeste();
    bool deletaTeste();

    bool executaTodosOsTestes() {
        Testes testes( "arvore" );
        testes.add( "insereTeste", insereTeste );
        testes.add( "iteradorTeste", iteradorTeste );
        testes.add( "alteraTeste", alteraTeste );
        testes.add( "deletaTeste", deletaTeste );
        return testes.executa();
    }

    bool insereTeste() {
        vector<int> ids = criaIDs();
        criaArvore( ids );

        return true;
    }

    bool iteradorTeste() {
        vector<int> ids = criaIDs();
        vector<int> inseridos;

        vector<int> ordenados(ids.size());
        copy( ids.begin(), ids.end(), ordenados.begin() );

        sort( ordenados.begin(), ordenados.end() );

        IDArvore* arv = criaArvore( ids );

        Iterador* it = arv->it();
        while( it->temProx() )
            inseridos.push_back( ((IDObjeto*)it->prox())->getId() );

        return vectutil::verificaSeIguais( inseridos, ordenados );
    }

    bool alteraTeste() {
        return false;
    }

    bool deletaTeste() {
        vector<int> ids = criaIDs();

        IDArvore* arv = criaArvore( ids );

        arv->deleta( 5 );
        arv->deleta( 16 );
        arv->deleta( 1 );
        arv->deleta( 10 );

        ids.erase( ids.begin() + vectutil::indice( ids, 5 ) );
        ids.erase( ids.begin() + vectutil::indice( ids, 16 ) );
        ids.erase( ids.begin() + vectutil::indice( ids, 1 ) );
        ids.erase( ids.begin() + vectutil::indice( ids, 10 ) );

        sort( ids.begin(), ids.end() );

        vector<int> inseridos;

        Iterador* it = arv->it();
        while( it->temProx() ) {
            int num = ((IDObjeto*)it->prox())->getId();
            inseridos.push_back( num );
        }

        IDObjeto* dados = arv->deleta( 0 );

        bool sucesso = dados == NULL;
        if ( sucesso )
            sucesso = vectutil::verificaSeIguais( ids, inseridos );
        return sucesso;
    }

}

vector<int> criaIDs() {
    vector<int> ids = { 10, 5, 3, 4, 2, 1, 18, 16, 17, 19 };
    return ids;
}

IDArvore* criaArvore( vector<int> ids ) {
    IDArvore* arv = new IDArvore();
    int tam = ids.size();
    for( int i = 0; i < tam; i++ )
        arv->insere( criaIDObjeto( ids[ i ] ) );
    return arv;
}

IDObjeto* criaIDObjeto( int id ) {
    IDObjeto* obj = new IDObjeto();
    obj->setId( id );
    return obj;
}
