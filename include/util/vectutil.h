#ifndef VECTOR_UTIL_H
#define VECTOR_UTIL_H

#if BUILDING_DLL
#define VECTOR_UTIL_API __declspec(dllexport)
#else
#define VECTOR_UTIL_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>

using namespace std;

namespace vectutil {

    VECTOR_UTIL_API bool verificaSeIguais( vector<int>, vector<int> );

    VECTOR_UTIL_API void exibe( string, vector<int> );

    VECTOR_UTIL_API int indice( vector<int>, int );

}

#endif
