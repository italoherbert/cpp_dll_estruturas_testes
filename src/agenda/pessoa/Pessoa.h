#ifndef PESSOA_H
#define PESSOA_H

#include "estrutura/IDObjeto.h"

#include <iostream>

using namespace std;

class Pessoa : public IDObjeto {

	private:
		string nome;
		int idade;
		double peso;

	public:
		string getNome();
		void setNome( string );
		int getIdade();
		void setIdade( int );
		double getPeso();
		void setPeso( double );

};

#endif
