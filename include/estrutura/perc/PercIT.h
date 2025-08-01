#ifndef PERC_IT_H
#define PERC_IT_H

#if BUILDING_DLL
#define PERC_IT_API __declspec(dllexport)
#else
#define PERC_IT_API __declspec(dllimport)
#endif

#include "../Objeto.h"

class PERC_IT_API PercIT {

	public:
		virtual void processa( Objeto* ) = 0;

};

#endif
