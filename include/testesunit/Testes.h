#ifndef TESTES_H
#define TESTES_H

#if BUILD_DLL
#define TESTES_API __declspec(dllexport)
#else
#define TESTES_API __declspec(dllimport)
#endif

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class TESTES_API Testes {

    typedef struct TFunc {
        string nome;
        function<void()> f;
    } Func;

    private:
        string nome;
        vector<Func> funcs;

    public:
        Testes( string nome );
        void add( string fname, function<void()> );
        bool executa();

};

#endif
