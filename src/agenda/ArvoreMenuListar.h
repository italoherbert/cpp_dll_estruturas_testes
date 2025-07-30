#ifndef MENU_LISTAR_H
#define MENU_LISTAR_H

#include "pessoa/perc/TudoPessoaPercIT.h"
#include "pessoa/perc/PorNomeIniPessoaPercIT.h"
#include "pessoa/perc/PorIdadePessoaPercIT.h"

#include "estrutura/IDArvore.h"

class ArvoreMenuListar {

	private:
		IDArvore* pessoaArvore;

		void mostraMenu();
		void listarTodos();
		void listarPorIdade();
		void listarPorNomeIni();

		void opcaoInvalida();

	public:
		ArvoreMenuListar( IDArvore* );

		void exec();

};

#endif
