#ifndef TESTES_UTIL_H
#define TESTES_UTIL_H

#if BUILDING_DLL
#define TESTES_UTIL_API __declspec(dllexport)
#else
#define TESTES_UTIL_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class TESTES_UTIL_API Testes {

    typedef struct TFunc {
        string nome;
        function<bool()> f;
    } Func;

    private:
        string nome;
        vector<Func> funcs;

    public:
        Testes( string nome );
        void add( string fname, function<bool()> );
        bool executa();

};

namespace testesutil {

    TESTES_UTIL_API bool verificaSucesso( bool, string );

}

#endif
