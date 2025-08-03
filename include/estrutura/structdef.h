#ifndef STRUCT_DEF_H
#define STRUCT_DEF_H

#include "Objeto.h"

typedef struct TArv {
    Objeto* dados;
    bool iterado;
    struct TArv* pai;
    struct TArv* esq;
    struct TArv* dir;
} Arv;

typedef struct TLst {
    Objeto* dados;
    struct TLst* ant;
    struct TLst* prox;
} Lst;

#endif
