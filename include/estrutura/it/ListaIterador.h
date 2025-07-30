#ifndef LISTA_ITERADOR_H
#define LISTA_ITERADOR_H

#include "Iterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ListaIterador : public Iterador {

    private:
        Lst* perc;

    public:
        ListaIterador( Lst* );

        bool temProx();
        Objeto* prox();

};

#endif
