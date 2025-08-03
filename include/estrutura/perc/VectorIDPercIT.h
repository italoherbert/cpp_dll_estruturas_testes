#ifndef VECTOR_ID_PERC_IT_H
#define VECTOR_ID_PERC_IT_H

#if BUILDING_DLL
#define VECTOR_ID_PERC_IT_API __declspec(dllexport)
#else
#define VECTOR_ID_PERC_IT_API __declspec(dllimport)
#endif

#include "PercIT.h"

#include <vector>

using namespace std;

class VECTOR_ID_PERC_IT_API VectorIDPercIT : public PercIT {

    private:
        vector<int> vetor;

    public:
        void processa( Objeto* obj );
        vector<int> getVector();

};

#endif
