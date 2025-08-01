
#include "arvore_testes.h"

#include "estrutura/IDArvore.h"
#include "estrutura/IDObjeto.h"
#include "estrutura/perc/PercIT.h"
#include "estrutura/it/Iterador.h"

#include "util/vectutil.h"

#include "testesunit/testesunit.h"
#include "testesunit/Testes.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class VectorPercIT : public PercIT {
private:
    vector<int> vetor;
public:
    void processa( Objeto* obj ) {
        vetor.push_back( ((IDObjeto*)obj)->getId() );
    }

    vector<int> getVector() {
        return vetor;
    }
};

namespace arvore_testes {

    void insereTeste();
    void iteradorTeste();
    void alteraTeste();
    void deletaTeste();
    void buscaTeste();
    void percorrePreOrdemTeste();
    void percorreOrdemCentralTeste();
    void percorrePosOrdemTeste();

    IDObjeto* criaIDObjeto( int );
    IDArvore* criaArvore( vector<int> );

    vector<int> criaIDs();
    vector<int> criaPreOrdemIDs();
    vector<int> criaOrdemCentralIDs();
    vector<int> criaPosOrdemIDs();

    bool executaTodosOsTestes() {
        Testes testes( "arvore" );
        testes.add( "insereTeste", insereTeste );
        testes.add( "iteradorTeste", iteradorTeste );
        testes.add( "alteraTeste", alteraTeste );
        testes.add( "deletaTeste", deletaTeste );
        testes.add( "buscaTeste", buscaTeste );
        testes.add( "percorrePreOrdemTeste", percorrePreOrdemTeste );
        testes.add( "percorreOrdemCentralTeste", percorreOrdemCentralTeste );
        testes.add( "percorrePosOrdemTeste", percorrePosOrdemTeste );
        return testes.executa();
    }

    void insereTeste() {
        vector<int> ids = criaIDs();
        IDArvore* arv = criaArvore( ids );

        delete arv;
    }

    void iteradorTeste() {
        vector<int> ids = criaIDs();
        vector<int> inseridos;

        vector<int> ordenados( ids.size() );
        copy( ids.begin(), ids.end(), ordenados.begin() );

        sort( ordenados.begin(), ordenados.end() );

        IDArvore* arv = criaArvore( ids );

        Iterador* it = arv->it();
        while( it->temProx() )
            inseridos.push_back( ((IDObjeto*)it->prox())->getId() );

        testesunit::devemSerIguais( inseridos, ordenados );
    }

    void percorrePreOrdemTeste() {
        vector<int> ids = criaIDs();
        vector<int> preOrdemIDs = criaPreOrdemIDs();

        IDArvore* arv = criaArvore( ids );

        VectorPercIT* vperc = new VectorPercIT();
        arv->percorrePreOrdem( vperc );

        testesunit::devemSerIguais( vperc->getVector(), preOrdemIDs );
    }

    void percorreOrdemCentralTeste() {
        vector<int> ids = criaIDs();
        vector<int> ordemCentralIDs = criaOrdemCentralIDs();

        IDArvore* arv = criaArvore( ids );

        VectorPercIT* vperc = new VectorPercIT();
        arv->percorreOrdemCentral( vperc );

        testesunit::devemSerIguais( vperc->getVector(), ordemCentralIDs );
    }

    void percorrePosOrdemTeste() {
        vector<int> ids = criaIDs();
        vector<int> posOrdemIDs = criaPosOrdemIDs();

        IDArvore* arv = criaArvore( ids );

        VectorPercIT* vperc = new VectorPercIT();
        arv->percorrePosOrdem( vperc );

        testesunit::devemSerIguais( vperc->getVector(), posOrdemIDs );
    }

    void alteraTeste() {
        vector<int> ids = criaIDs();
        IDArvore* arv = criaArvore( ids );

        IDObjeto* obj = criaIDObjeto( 17 );

        arv->altera( obj );

        IDObjeto* obj2 = arv->busca( 17 );

        testesunit::devemSerIguais( obj, obj2 );
    }

    void deletaTeste() {
        vector<int> ids = criaIDs();
        IDArvore* arv = criaArvore( ids );

        testesunit::devemSerIguais( arv->getTamanho(), 10 );
        testesunit::devemSerIguais( arv->tamanho(), 10 );

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

        testesunit::deveSerNulo( dados );
        testesunit::devemSerIguais( ids, inseridos );
        testesunit::devemSerIguais( arv->getTamanho(), 6 );
        testesunit::devemSerIguais( arv->tamanho(), 6 );

        arv->deletaTodos();

        testesunit::devemSerIguais( arv->getTamanho(), 0 );
        testesunit::devemSerIguais( arv->tamanho(), 0 );

        delete arv;
    }

    void buscaTeste() {
        vector<int> ids = criaIDs();
        IDArvore* arv = criaArvore( ids );

        IDObjeto* obj = arv->busca( 17 );

        testesunit::deveSerNaoNulo( obj );
        testesunit::devemSerIguais( obj->getId(), 17 );
    }

    vector<int> criaIDs() {
        vector<int> ids = { 10, 5, 3, 4, 2, 1, 18, 16, 17, 19 };
        return ids;
    }

    vector<int> criaPreOrdemIDs() {
        vector<int> ids = { 10, 5, 3, 2, 1, 4, 18, 16, 17, 19  };
        return ids;
    }

    vector<int> criaOrdemCentralIDs() {
        vector<int> ids = { 1, 2, 3, 4, 5, 10, 16, 17, 18, 19 };
        return ids;
    }

    vector<int> criaPosOrdemIDs() {
        vector<int> ids = { 1, 2, 4, 3, 5, 17, 16, 19, 18, 10 };
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

}
