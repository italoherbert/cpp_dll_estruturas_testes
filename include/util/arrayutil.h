#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#if BUILDING_DLL
#define ARRAY_UTIL_API __declspec(dllexport)
#else
#define ARRAY_UTIL_API __declspec(dllimport)
#endif

#include "comp/Comparador.h"

namespace arrayutil {

    ARRAY_UTIL_API bool verificaSeArraysIguais( int*, int*, int );

    ARRAY_UTIL_API int* copiaVetor( int*, int );

    ARRAY_UTIL_API void selectionSort( int*, int );

    ARRAY_UTIL_API void inversoSelectionSort( int*, int );


    template <typename T>
    bool verificaSeArraysIguais2( T* a1, T* a2, int tam );

    template <typename T>
    T* copiaVetor2( T* vetor, int tam );

    template <typename T>
    void selectionSort2( T* vetor, int tam );

    template <typename T>
    void inversoSelectionSort2( T* vetor, int tam );

    template <typename T>
    void selectionSort2( T* vetor, int tam, Comparador<T>* comp );

}

#endif
