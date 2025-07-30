#ifndef ARVORE_POS_ORDEM_ITERADOR_H
#define ARVORE_POS_ORDEM_ITERADOR_H

#include "ArvoreIterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ArvorePosOrdemIterador : public ArvoreIterador {

    private:
        void pushEsquerdosNaPilha( Arv* );

	public:
	    ArvorePosOrdemIterador( Arv* );

		Objeto* prox();

};

#endif
