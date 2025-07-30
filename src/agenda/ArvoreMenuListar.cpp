
#include "ArvoreMenuListar.h"
#include "pessoa/pessoa_io.h"

#include "util/readutil.h"
#include "estrutura/it/Iterador.h"

#include <iostream>
#include <string>

using namespace std;
using namespace readutil;

ArvoreMenuListar::ArvoreMenuListar( IDArvore* pessoaArvore ) {
	this->pessoaArvore = pessoaArvore;
}

void ArvoreMenuListar::exec() {
	int op;
	do {
		mostraMenu();
		op = readInt( "Informe a opcao: ", "Opcao invalida. Informe um valor inteiro." );
		cout << endl;

		switch ( op ) {
			case 0:
				op = 0;
				break;
			case 1:
				listarTodos();
				break;
			case 2:
				listarPorNomeIni();
				break;
			case 3:
				listarPorIdade();
				break;
			default:
				opcaoInvalida();
		}

	} while( op != 0 );
}

void ArvoreMenuListar::mostraMenu() {
	cout << endl;
	cout << "==================================" << endl;
	cout << "             MENU" << endl;
	cout << "==================================" << endl;
	cout << "  (1) Listar todos" << endl;
	cout << "  (2) Listar por inicio do nome" << endl;
	cout << "  (3) Lista por idade" << endl;
	cout << "  (0) Sair" << endl;
	cout << "===================================" << endl;
	cout << endl;
}

void ArvoreMenuListar::listarTodos() {
	//TudoPessoaPercIT* perc = new TudoPessoaPercIT();

	int tam = pessoaArvore->getTamanho();
	if ( tam != pessoaArvore->tamanho() )
        cout << "ERRO: Tamanho errado.";

	cout << "\tLista de pessoas ( " << tam << " )" << endl;
 	cout << endl;

 	Iterador* it = pessoaArvore->it();
 	while( it->temProx() )
        exibePessoa( (Pessoa*)it->prox() );

	system( "pause" );
}

void ArvoreMenuListar::listarPorNomeIni() {
	string nomeIni = leNomeIni();
 	PorNomeIniPessoaPercIT* perc = new PorNomeIniPessoaPercIT( nomeIni );

	cout << "\tLista de pessoas" << endl;
 	cout << endl;
	pessoaArvore->percorreOrdemCentral( perc );

	system( "pause" );
}

void ArvoreMenuListar::listarPorIdade() {
	int idade = leIdade();
	PorIdadePessoaPercIT* perc = new PorIdadePessoaPercIT( idade );

	cout << "\tLista de pessoas" << endl;
 	cout << endl;
	pessoaArvore->percorreOrdemCentral( perc );

	system( "pause" );
}

void ArvoreMenuListar::opcaoInvalida() {
	cout << "Opcao invalida..." << endl;
	system( "pause" );
}
