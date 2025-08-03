#ifndef GTESTES_H
#define GTESTES_H

#if BUILD_DLL
#define GTESTES_API __declspec(dllexport)
#else
#define GTESTES_API __declspec(dllimport)
#endif

#include "TestesResult.h"

#include <functional>
#include <vector>

class GTESTES_API GTestes {

    public:
        virtual vector<string> testeFuncNomes() = 0;
        virtual TestesResult* executaTeste( int testeIndice ) = 0;
        virtual TestesResult* executa() = 0;

};

#endif
