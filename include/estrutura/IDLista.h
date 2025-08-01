#ifndef ID_LISTA_H
#define ID_LISTA_H

#if BUILDING_DLL
#define ID_LISTA_API __declspec(dllexport)
#else
#define ID_LISTA_API __declspec(dllimport)
#endif

#include "Lista.h"
#include "IDObjeto.h"
#include "comp/IDObjComparador.h"

class ID_LISTA_API IDLista : public Lista {

    using Lista::busca;
    using Lista::altera;
    using Lista::deleta;

	private:
		IDObjComparador* objComparador;

	public:
		IDLista();

		IDObjeto* busca( int );
		bool altera( IDObjeto* );
		IDObjeto* deleta( int );

};

#endif
