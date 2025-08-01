#ifndef GRUPO_DE_TESTES_H
#define GRUPO_DE_TESTES_H

#if BUILD_DLL
#define GRUPO_DE_TESTES_API __declspec(dllexport)
#else
#define GRUPO_DE_TESTES_API __declspec(dllimport)
#endif

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class GRUPO_DE_TESTES_API GrupoDeTestes {

    private:
        vector<function<bool()>> funcs;

    public:
        void add( function<bool()> );
        bool executa();

};

#endif
