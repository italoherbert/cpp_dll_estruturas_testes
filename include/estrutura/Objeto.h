#ifndef OBJETO_H
#define OBJETO_H

#if BUILDING_DLL
#define OBJETO_API __declspec(dllexport)
#else
#define OBJETO_API __declspec(dllimport)
#endif

class OBJETO_API Objeto {
		
};

#endif
