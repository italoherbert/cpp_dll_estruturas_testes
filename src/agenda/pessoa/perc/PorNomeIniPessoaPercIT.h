#ifndef POR_NOME_INI_PESSOA_PERC_IT_H
#define POR_NOME_INI_PESSOA_PERC_IT_H

#include "../Pessoa.h"
#include "estrutura/perc/PercIT.h"

using namespace std;

class PorNomeIniPessoaPercIT : public PercIT {

	private:
		string nomeIni;

	public:
		PorNomeIniPessoaPercIT( string );
		void processa( Objeto* );

};

#endif
