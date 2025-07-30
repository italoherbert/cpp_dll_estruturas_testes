#ifndef ARVORE_ORDEM_CENTRAL_ITERADOR_H
#define ARVORE_ORDEM_CENTRAL_ITERADOR_H

#include "ArvoreIterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ArvoreOrdemCentralIterador : public ArvoreIterador {

    private:
        void pushEsquerdosNaPilha( Arv* );

	public:
	    ArvoreOrdemCentralIterador( Arv* );
		Objeto* prox();

};

#endif
