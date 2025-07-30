
#include "ArvoreAgenda.h"
#include "pessoa/pessoa_io.h"
#include "util/readutil.h"
#include "util/numutil.h"

#include <iostream>
#include <string>

using namespace std;
using namespace readutil;
using namespace numutil;

ArvoreAgenda::ArvoreAgenda() {
	this->pessoaArvore = new IDArvore();
	this->menuListar = new ArvoreMenuListar( pessoaArvore );
}

void ArvoreAgenda::exec() {
	int op;
	do {
		mostraMenu();
		op = readInt( "Informe a opcao: ", "Opcao invalida. Informe um valor inteiro." );
		cout << endl;

		switch ( op ) {
			case 0:
				sair();
				break;
			case 1:
				inserePessoa();
				break;
			case 2:
				mostraMenuListar();
				break;
			case 3:
				buscaPessoa();
				break;
			case 4:
				alteraPessoa();
				break;
			case 5:
				deletaPessoa();
				break;
			default:
				opcaoInvalida();
		}

	} while( op != 0 );
}

void ArvoreAgenda::mostraMenu() {
	cout << endl;
	cout << "==============================" << endl;
	cout << "             MENU" << endl;
	cout << "==============================" << endl;
	cout << "  (1) Inserir pessoa" << endl;
	cout << "  (2) Mostrar menu listar" << endl;
	cout << "  (3) Buscar pessoa" << endl;
	cout << "  (4) Alterar pessoa" << endl;
	cout << "  (5) Remover pessoa" << endl;
	cout << "  (0) Sair" << endl;
	cout << "==============================" << endl;
	cout << endl;
}

void ArvoreAgenda::inserePessoa() {
	Pessoa* pessoa = lePessoa();

	pessoaArvore->insere( pessoa );

	cout << endl;
	cout << "Pessoa inserida com sucesso." << endl;

	system("pause");
}

void ArvoreAgenda::mostraMenuListar() {
	menuListar->exec();
}

void ArvoreAgenda::buscaPessoa() {
	int id = leIDParaBusca();

	cout << endl;

	Pessoa* pessoa = (Pessoa*)pessoaArvore->busca( id );
	if ( pessoa == NULL ) {
		cout << "Pessoa não encontrada pelo ID informado." << endl;
	} else {
		cout << "\tDados da pessoa:" << endl;
		cout << endl;
		exibePessoa( pessoa );
	}

	system( "pause" );

}

void ArvoreAgenda::alteraPessoa() {
	Pessoa* pessoa = lePessoa();

	bool alterou = pessoaArvore->altera( pessoa );

	if ( alterou ) {
		cout << "Alteracao realizada com sucesso." << endl;
	} else {
		cout << "Pessoa nao encontrada pelo ID." << endl;
	}

	system( "pause" );
}

void ArvoreAgenda::deletaPessoa() {
	int id = leIDParaBusca();

	cout << endl;

	bool deletou = pessoaArvore->deleta( id );

	if ( deletou ) {
		cout << "Pessoa removida com sucesso." << endl;
	} else {
		cout << "Pessoa nao encontrada pelo ID." << endl;
	}

	system( "pause" );
}

void ArvoreAgenda::sair() {
	system( "pause" );
}

void ArvoreAgenda::opcaoInvalida() {
	cout << "Opcao invalida..." << endl;
	system( "pause" );
}

