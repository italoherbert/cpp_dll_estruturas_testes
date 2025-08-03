#ifndef ARVORE_H
#define ARVORE_H

#if BUILDING_DLL
#define ARVORE_API __declspec(dllexport)
#else
#define ARVORE_API __declspec(dllimport)
#endif

#include "Objeto.h"
#include "Estrutura.h"
#include "structdef.h"
#include "perc/PercIT.h"
#include "comp/ObjComparador.h"
#include "comp/CampoComparador.h"
#include "it/Iterador.h"

class ARVORE_API Arvore : public Estrutura {

	private:
		Arv* raiz;
		ObjComparador* objComparador;
		int tam;

		void insereEmArvore( Arv**, Arv*, Objeto* );
		void percorreArvorePreOrdem( Arv*, PercIT* );
		void percorreArvoreOrdemCentral( Arv*, PercIT* );
		void percorreArvorePosOrdem( Arv*, PercIT* );
		Objeto* buscaEmArvore( Arv*, CampoComparador* );
		bool alteraEmArvore( Arv*, CampoComparador*, Objeto* );
		Objeto* deletaEmArvore( Arv**, CampoComparador* );
        void deletaTodosEmArvore( Arv**, bool );

		int tamanhoDaArvore( Arv* );

	public:
		Arvore( ObjComparador* );
		virtual ~Arvore();

		void percorrePreOrdem( PercIT* );
		void percorreOrdemCentral( PercIT* );
		void percorrePosOrdem( PercIT* );

		void insere( Objeto* );
		void percorre( PercIT* );
		Iterador* it();
		Iterador* inversoIt();
		Objeto* busca( CampoComparador* );
		bool altera( CampoComparador*, Objeto* );
		Objeto* deleta( CampoComparador* );
		void deletaTodos( bool deletarTodos = false );
		int tamanho();
		int getTamanho();

};

#endif
