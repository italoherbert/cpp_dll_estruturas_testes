#ifndef OBJ_COMPARADOR_H
#define OBJ_COMPARADOR_H

#if BUILDING_DLL
#define OBJ_COMPARADOR_API __declspec(dllexport)
#else
#define OBJ_COMPARADOR_API __declspec(dllimport)
#endif

#include "../Objeto.h"

class OBJ_COMPARADOR_API ObjComparador {
	
	public:
		virtual int compara( Objeto*, Objeto* ) = 0;
	
};

#endif
