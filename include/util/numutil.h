#ifndef NUM_UTIL_H
#define NUM_UTIL_H

#if BUILDING_DLL
#define NUMUTIL_API __declspec(dllexport)
#else
#define NUMUTIL_API __declspec(dllimport)
#endif

NUMUTIL_API int sorteiaNumero();

#endif
