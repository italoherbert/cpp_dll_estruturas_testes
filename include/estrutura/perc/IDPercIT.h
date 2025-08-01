#ifndef ID_PERC_IT_H
#define ID_PERC_IT_H

#if BUILDING_DLL
#define ID_PERC_IT_API __declspec(dllexport)
#else
#define ID_PERC_IT_API __declspec(dllimport)
#endif

#include "PercIT.h"
#include "../Objeto.h"

class ID_PERC_IT_API IDPercIT : public PercIT {

    public:
        void percorre( Objeto* );

};

#endif
