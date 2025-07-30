
#include "Pessoa.h"

string Pessoa::getNome() {
	return nome;
}

void Pessoa::setNome( string nome ) {
	this->nome = nome;
}

int Pessoa::getIdade() {
	return this->idade;
}

void Pessoa::setIdade( int idade ) {
	this->idade = idade;
}

double Pessoa::getPeso() {
	return peso;
}

void Pessoa::setPeso( double peso ) {
	this->peso = peso;
}
