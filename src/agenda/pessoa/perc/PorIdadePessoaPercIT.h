#ifndef POR_IDADE_PESSOA_PERC_IT_H
#define POR_IDADE_PESSOA_PERC_IT_H

#include "../Pessoa.h"
#include "estrutura/perc/PercIT.h"

class PorIdadePessoaPercIT : public PercIT {

	private:
		int idade;

	public:
		PorIdadePessoaPercIT( int );
		void processa( Objeto* );

};

#endif
