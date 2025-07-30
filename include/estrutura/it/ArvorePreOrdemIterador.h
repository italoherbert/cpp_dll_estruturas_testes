#ifndef ARVORE_PRE_ORDEM_ITERADOR_H
#define ARVORE_PRE_ORDEM_ITERADOR_H

#include "ArvoreIterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ArvorePreOrdemIterador : public ArvoreIterador {

	public:
	    ArvorePreOrdemIterador( Arv* );
		Objeto* prox();

};

#endif
