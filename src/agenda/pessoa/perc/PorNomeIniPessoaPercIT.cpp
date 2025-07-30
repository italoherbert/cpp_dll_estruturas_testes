
#include "PorNomeIniPessoaPercIT.h"
#include "../pessoa_io.h"
#include "util/strutil.h"

#include <iostream>
using namespace std;

PorNomeIniPessoaPercIT::PorNomeIniPessoaPercIT( string nomeIni ) {
	this->nomeIni = nomeIni;
}

void PorNomeIniPessoaPercIT::processa( Objeto* pessoa ) {
	Pessoa* pessoa2 = (Pessoa*)pessoa;

	string nome = toLower( pessoa2->getNome() );
	string ini = toLower( nomeIni );
	if ( startsWith( nome, ini ) )
		exibePessoa( pessoa2 );
}
