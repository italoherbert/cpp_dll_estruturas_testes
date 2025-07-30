
#include "arvore_testes.h"

#include "estrutura/IDArvore.h"
#include "estrutura/IDObjeto.h"
#include "estrutura/it/Iterador.h"

#include <iostream>

using namespace std;

IDObjeto* criaIDObjeto( int );
IDArvore* criaArvore( int[], int );

int* criaIDs( int* );
int* ordena( int[], int );
int* ponteiroDeVetor( int[], int );
bool comparaArrays( int[], int[], int );

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
    int* ordenados = ordena( ids, tam );
    int inseridos[ tam ];

    IDArvore* arv = criaArvore( ids, tam );

    Iterador* it = arv->it();
    int i = 0;
    while( it->temProx() ) {
        inseridos[ i ] = ((IDObjeto*)it->prox())->getId();
        i++;
    }

    bool sucesso = comparaArrays( inseridos, ordenados, tam );

    if ( sucesso )
        cout << "arvoreIteradorTest - Ok" << endl;
    else cout << "arvoreIteradorTest - Falha" << endl;

    return sucesso;
}

int* criaIDs( int* tam ) {
    int ids[] = { 10, 5, 3, 4, 2, 1, 18, 17, 16, 19 };
    *tam = 10;
    return ponteiroDeVetor( ids, *tam );
}

int* ordena( int ids[], int tam ) {
    int* ordenados = new int[ tam ];
    for( int i = 0; i < tam; i++ )
        ordenados[ i ] = ids[ i ];

    for( int i = 0; i < tam-1; i++ ) {
        int menor_j = i;
        for( int j = i+1; j < tam; j++ )
            if ( ordenados[ j ] < ordenados[ i ] )
                menor_j = j;

        if ( menor_j != i ) {
            int aux = ordenados[ i ];
            ordenados[ i ] = ordenados[ menor_j ];
            ordenados[ menor_j ] = aux;
        }
    }
    return ordenados;
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

bool comparaArrays( int a1[], int a2[], int tam ) {
    for( int i = 0; i < tam; i++ )
        if ( a1[ i ] != a2[ i ] )
            return false;
    return true;
}

int* ponteiroDeVetor( int vetor[], int tam ) {
    int* vetor2 = new int[ tam ];
    for( int i = 0; i < tam; i++ )
        vetor2[ i ] = vetor[ i ];
    return vetor2;
}
