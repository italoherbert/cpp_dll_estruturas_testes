#ifndef ID_OBJ_COMPARADOR_H
#define ID_OBJ_COMPARADOR_H

#if BUILDING_DLL
#define ID_OBJ_COMPARADOR_API __declspec(dllexport)
#else
#define ID_OBJ_COMPARADOR_API __declspec(dllimport)
#endif

#include "ObjComparador.h"

class ID_OBJ_COMPARADOR_API IDObjComparador : public ObjComparador {
	
	public:
		int compara( Objeto*, Objeto* );
		
};

#endif
