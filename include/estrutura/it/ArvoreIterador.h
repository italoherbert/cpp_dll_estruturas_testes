#ifndef ARVORE_ITERADOR_H
#define ARVORE_ITERADOR_H

#include "Iterador.h"
#include "../Objeto.h"
#include "../structdef.h"

class ArvoreIterador : public Iterador {

    typedef struct TPilha {
        Arv* perc;
        struct TPilha* prox;
    } Pilha;

    private:
        Pilha* pilha;

    protected:
        void pushNaPilha( Arv* );
        Arv* popNaPilha();

    public:
        ArvoreIterador();

        bool temProx();
};

#endif
