#ifndef ID_OBJETO_H
#define ID_OBJETO_H

#if BUILDING_DLL
#define ID_OBJETO_API __declspec(dllexport)
#else
#define ID_OBJETO_API __declspec(dllimport)
#endif

#include "Objeto.h"

class ID_OBJETO_API IDObjeto : public Objeto {

	private:
		int id;

	public:
		int getId();
		void setId( int );

};

#endif
