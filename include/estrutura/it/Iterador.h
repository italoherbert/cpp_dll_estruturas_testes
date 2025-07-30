
#ifndef ITERADOR_H
#define ITERADOR_H

#if BUILDING_DLL
#define ITERADOR_API __declspec(dllexport)
#else
#define ITERADOR_API __declspec(dllimport)
#endif

#include "../Objeto.h"

class ITERADOR_API Iterador {

	public:
	    virtual bool temProx() = 0;
		virtual Objeto* prox() = 0;

};

#endif
