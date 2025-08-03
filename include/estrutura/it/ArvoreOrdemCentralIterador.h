#ifndef ARVORE_ORDEM_CENTRAL_ITERADOR_H
#define ARVORE_ORDEM_CENTRAL_ITERADOR_H

#include "Iterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ArvoreOrdemCentralIterador : public Iterador {

    private:
        Arv* perc;
        bool vaiParaBaixo;
        bool vemDaEsquerda;

        Arv* menorEsq( Arv* );
        Arv* paiNaoIterado( Arv* );

	public:
	    ArvoreOrdemCentralIterador( Arv* );
	    bool temProx();
		Objeto* prox();

};

#endif
