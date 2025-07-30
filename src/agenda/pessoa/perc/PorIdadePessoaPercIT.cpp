
#include "PorIdadePessoaPercIT.h"
#include "../pessoa_io.h"

PorIdadePessoaPercIT::PorIdadePessoaPercIT( int idade ) {
	this->idade = idade;
}

void PorIdadePessoaPercIT::processa( Objeto* pessoa ) {
	Pessoa* pessoa2 = (Pessoa*)pessoa;
	
	if ( idade == pessoa2->getIdade() )
		exibePessoa( pessoa2 );
}
