#ifndef ID_ARVORE_H
#define ID_ARVORE_H

#if BUILDING_DLL
#define ID_ARVORE_API __declspec(dllexport)
#else
#define ID_ARVORE_API __declspec(dllimport)
#endif

#include "Arvore.h"
#include "IDObjeto.h"
#include "comp/IDObjComparador.h"

class ID_ARVORE_API IDArvore : public Arvore {

    using Arvore::insere;
    using Arvore::busca;
    using Arvore::altera;
    using Arvore::deleta;

	private:
		IDObjComparador* objComparador;

	public:
		IDArvore();

		void insere( IDObjeto* );
		IDObjeto* busca( int );
		bool altera( IDObjeto* );
		IDObjeto* deleta( int );

};

#endif
