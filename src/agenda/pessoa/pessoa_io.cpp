
#include "pessoa_io.h"
#include "util/readutil.h"

#include <iostream>
#include <string>

using namespace std;
using namespace readutil;

void exibePessoa( Pessoa* pessoa ) {
	cout << "ID: " << pessoa->getId() << endl;
	cout << "Nome: " << pessoa->getNome() << endl;
	cout << "Idade: " << pessoa->getIdade() << endl;
	cout << "Peso: " << pessoa->getPeso() << endl;
	cout << endl;
}

Pessoa* lePessoa() {
	int id;
	string nome;
	int idade;
	double peso;

	id = readInt( "Informe o ID: ", "ID Invalido. Informe um valor inteiro!" );
	nome = readLine( "Informe o nome: " );
	idade = readInt( "Informe a idade: ", "Idade invalida. Informe um valor inteiro." );
	peso = readDouble( "Informe o peso: ", "Peso invalido. Informe um valor inteiro." );

	Pessoa* pessoa = new Pessoa();
	pessoa->setId( id );
	pessoa->setNome( nome );
	pessoa->setIdade( idade );
	pessoa->setPeso( peso );
	return pessoa;
}

int leIDParaBusca() {
	return readInt( "Informe o ID: ", "ID Invalido. Informe um valor inteiro!" );
}

string leNomeIni() {
	return readLine( "Informe o inicio do nome: " );
}

int leIdade() {
	return readInt( "Informe a idade: ", "Idade invalida. Informe um valor inteiro." );
}

