#ifndef LISTA_H
#define LISTA_H

#if BUILDING_DLL
#define LISTA_API __declspec(dllexport)
#else
#define LISTA_API __declspec(dllimport)
#endif

#include "Objeto.h"
#include "Estrutura.h"
#include "structdef.h"
#include "perc/PercIT.h"
#include "comp/ObjComparador.h"
#include "comp/CampoComparador.h"
#include "it/Iterador.h"

class LISTA_API Lista : public Estrutura {

    typedef struct TDescritor {
        int tamanho;
        Lst* prim;
        Lst* ult;
    } Descritor;

    private:
		Descritor* descritor;

		void insereNoInicio( Descritor*, Objeto* );
		void insereNoFim( Descritor*, Objeto* );
		void percorreLista( Descritor*, PercIT* );
		void percorreListaOrdemInversa( Descritor*, PercIT* );
		Objeto* buscaNaLista( Descritor*, CampoComparador* );
		bool alteraNaLista( Descritor*, CampoComparador*, Objeto* );
		Objeto* deletaNaLista( Descritor*, CampoComparador* );
		void deletaTodosNaLista( Descritor*, bool );
		Objeto* popEmLista( Descritor* );

		Objeto* getEmLista( Descritor*, int indice );
		int tamanhoDaLista( Descritor* desc );

	public:
	    Lista();
	    virtual ~Lista();

	    int getTamanho();
	    int tamanho();

		void insere( Objeto* );
		void insereNoInicio( Objeto* );
		void insereNoFim( Objeto* );
		void percorre( PercIT* );
		void percorreOrdemInversa( PercIT* );
        Iterador* it();
        Iterador* inversoIt();
		Objeto* busca( CampoComparador* );
		bool altera( CampoComparador*, Objeto* );
		Objeto* deleta( CampoComparador* );
		void deletaTodos( bool deletarObjetos = false );
		Objeto* pop();
	    Objeto* get( int );

};

#endif

