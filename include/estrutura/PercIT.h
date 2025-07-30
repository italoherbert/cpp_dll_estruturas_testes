#ifndef PROC_IT_H
#define PROC_IT_H

#if BUILDING_DLL
#define PROC_IT_API __declspec(dllexport)
#else
#define PROC_IT_API __declspec(dllimport)
#endif

#include "Objeto.h"

class PROC_IT_API PercIT {
	
	public:
		virtual void processa( Objeto* ) = 0;
	
};

#endif
