#ifndef MENOR_COMPARADOR_H
#define MENOR_COMPARADOR_H

#include "Comparador.h"

template <typename T>
class MenorComparador : public Comparador<T> {

    public:
        int compara( T, T );
};

#endif
