#ifndef INVERSO_ARVORE_ORDEM_CENTRAL_ITERADOR_H
#define INVERSO_ARVORE_ORDEM_CENTRAL_ITERADOR_H

#include "Iterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class InversoArvoreOrdemCentralIterador : public Iterador {

    private:
        Arv* perc;
        bool vaiParaBaixo;
        bool vemDaDireita;

        Arv* menorDir( Arv* );
        Arv* paiNaoIterado( Arv* );

	public:
	    InversoArvoreOrdemCentralIterador( Arv* );
	    bool temProx();
		Objeto* prox();

};

#endif

