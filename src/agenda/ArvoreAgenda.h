#ifndef AGENDA_H
#define AGENDA_H

#include "ArvoreMenuListar.h"
#include "pessoa/Pessoa.h"

#include "estrutura/IDArvore.h"

#include <iostream>

using namespace std;

class ArvoreAgenda {

	private:
		IDArvore* pessoaArvore;
		ArvoreMenuListar* menuListar;

		void mostraMenu();
		void inserePessoa();
		void mostraMenuListar();
		void buscaPessoa();
		void alteraPessoa();
		void deletaPessoa();

		void sair();
		void opcaoInvalida();

	public:
		ArvoreAgenda();

		void exec();


};

#endif
