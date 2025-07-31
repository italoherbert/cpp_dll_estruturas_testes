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

class TESTES_UTIL_API teste_error : public runtime_error {

    public:
        teste_error( string msg );

};

class TESTES_UTIL_API Testes {

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

namespace testesutil {

    TESTES_UTIL_API void verificaSeNulo( void* );

    TESTES_UTIL_API void verificaSeNaoNulo( void* );


    TESTES_UTIL_API void verificaSeIguais( void*, void* );

    TESTES_UTIL_API void verificaSeIguais( int, int );

    TESTES_UTIL_API void verificaSeIguais( double, double );

    TESTES_UTIL_API void verificaSeIguais( float, float );

    TESTES_UTIL_API void verificaSeIguais( string, string );

    TESTES_UTIL_API void verificaSeIguais( int*, int*, int );

    TESTES_UTIL_API void verificaSeIguais( vector<int>, vector<int> );


    TESTES_UTIL_API void verificaSeDiferentes( void*, void* );

    TESTES_UTIL_API void verificaSeDiferentes( int, int );

    TESTES_UTIL_API void verificaSeDiferentes( double, double );

    TESTES_UTIL_API void verificaSeDiferentes( float, float );

    TESTES_UTIL_API void verificaSeDiferentes( string, string );

    TESTES_UTIL_API void verificaSeDiferentes( int*, int*, int );

    TESTES_UTIL_API void verificaSeDiferentes( vector<int>, vector<int> );

}

#endif
