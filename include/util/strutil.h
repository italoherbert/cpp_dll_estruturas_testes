#ifndef STR_UTIL_H
#define STR_UTIL_H

#if BUILDING_DLL
#define STRUTIL_API __declspec(dllexport)
#else
#define STRUTIL_API __declspec(dllimport)
#endif

#include <iostream>

namespace strutil {

    STRUTIL_API std::string toLower( std::string str );
    STRUTIL_API bool startsWith( std::string str, std::string ini );

}

#endif
