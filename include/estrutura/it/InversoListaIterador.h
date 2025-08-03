
#ifndef INVERSO_LISTA_ITERADOR_H
#define INVERSO_LISTA_ITERADOR_H

#include "Iterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class InversoListaIterador : public Iterador {

    private:
        Lst* perc;

    public:
        InversoListaIterador( Lst* );

        bool temProx();
        Objeto* prox();

};

#endif
