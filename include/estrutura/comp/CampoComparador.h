#ifndef CAMPO_COMPARADOR_H
#define CAMPO_COMPARADOR_H

#if BUILDING_DLL
#define CAMPO_COMPARADOR_API __declspec(dllexport)
#else
#define CAMPO_COMPARADOR_API __declspec(dllimport)
#endif

#include "../Objeto.h"

class CAMPO_COMPARADOR_API CampoComparador {
	
	public:
		virtual int compara( Objeto* o ) = 0;
	
};

#endif
