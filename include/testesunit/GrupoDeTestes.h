#ifndef GRUPO_DE_TESTES_H
#define GRUPO_DE_TESTES_H

#if BUILD_DLL
#define GRUPO_DE_TESTES_API __declspec(dllexport)
#else
#define GRUPO_DE_TESTES_API __declspec(dllimport)
#endif

#include <string>

#include "GTestes.h"
#include "Testes.h"
#include "TestesResult.h"

using namespace std;

class GRUPO_DE_TESTES_API GrupoDeTestes : public GTestes {

    private:
        vector<Testes*> testesVect;

    public:
        void add( Testes* );

        vector<string> testeFuncNomes();
        TestesResult* executaTeste( int testeIndice );
        TestesResult* executa();

};

#endif
