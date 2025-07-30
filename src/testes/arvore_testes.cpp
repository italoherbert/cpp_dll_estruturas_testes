
#include "arvore_testes.h"

#include "estrutura/IDArvore.h"
#include "estrutura/IDObjeto.h"
#include "estrutura/it/Iterador.h"

#include "util/arrayutil.h"

#include <iostream>

using namespace std;
using namespace arrayutil;

IDObjeto* criaIDObjeto( int );
IDArvore* criaArvore( int[], int );

int* criaIDs( int* );

bool arvoreInsereTeste();
bool arvoreIteradorTeste();

bool arvoreTodosOsTestes() {
    bool sucesso = arvoreInsereTeste();
    if ( sucesso )
        sucesso = arvoreIteradorTeste();
    return sucesso;
}

bool arvoreInsereTeste() {
    int tam;
    int* ids = criaIDs( &tam );

    criaArvore( ids, tam );

    cout << "arvoreInsereTeste - Ok" << endl;

    return true;
}

bool arvoreIteradorTeste() {
    int tam;
    int* ids = criaIDs( &tam );
    int* ordenados = copiaVetor( ids, tam );
    int inseridos[ tam ];

    selectionSort( ordenados, tam );

    IDArvore* arv = criaArvore( ids, tam );

    Iterador* it = arv->it();
    int i = 0;
    while( it->temProx() ) {
        inseridos[ i ] = ((IDObjeto*)it->prox())->getId();
        i++;
    }

    bool sucesso = verificaSeArraysIguais( inseridos, ordenados, tam );

    if ( sucesso )
        cout << "arvoreIteradorTest - Ok" << endl;
    else cout << "arvoreIteradorTest - Falha" << endl;

    return sucesso;
}

int* criaIDs( int* tam ) {
    int ids[] = { 10, 5, 3, 4, 2, 1, 18, 17, 16, 19 };
    *tam = 10;
    return copiaVetor( ids, *tam );
}

IDArvore* criaArvore( int ids[], int tam ) {
    IDArvore* arv = new IDArvore();
    for( int i = 0; i < tam; i++ )
        arv->insere( criaIDObjeto( ids[ i ] ) );
    return arv;
}

IDObjeto* criaIDObjeto( int id ) {
    IDObjeto* obj = new IDObjeto();
    obj->setId( id );
    return obj;
}
