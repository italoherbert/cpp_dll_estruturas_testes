#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#if BUILDING_DLL
#define ESTRUTURA_API __declspec(dllexport)
#else
#define ESTRUTURA_API __declspec(dllimport)
#endif

#include "Objeto.h"
#include "perc/PercIT.h"
#include "comp/ObjComparador.h"
#include "comp/CampoComparador.h"
#include "it/Iterador.h"

class ESTRUTURA_API Estrutura {

	public:
		virtual void insere( Objeto* ) = 0;
		virtual void percorre( PercIT* ) = 0;
		virtual Iterador* it() = 0;
		virtual Iterador* inversoIt() = 0;
		virtual Objeto* busca( CampoComparador* ) = 0;
		virtual bool altera( CampoComparador*, Objeto* ) = 0;
		virtual Objeto* deleta( CampoComparador* ) = 0;
		virtual void deletaTodos( bool deletarObjetos = false ) = 0;
	    virtual int tamanho() = 0;
	    virtual int getTamanho() = 0;

};

#endif
