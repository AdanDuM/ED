/*
 * Lancamento.cpp
 *
 *  Created on: 25/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#include "Lancamento.h"
#include <string.h>
#include <iostream>

using namespace std;

Lancamento::Lancamento(){}
/**
 *Construtor que configura um objeto da classe Lancamento.
 */
Lancamento::Lancamento(const char *dado,int val) {
	strcpy(nome,dado);

	valor = val;
}
/**
 *Destrutoer que exclui um objeto da classe Lancamento.
 */
Lancamento::~Lancamento() {
	// TODO Auto-generated destructor stub
}
/**
 * Metodo que imprime no console as informaçoes sobre o Lançamento.
 */
void Lancamento::mostrarLancamento(){
	cout << nome << ": " << valor <<endl;
}
/**
 * Método que verifica se o valor do lançamento é um código de erro.
 *
 * @return true caso o valor do lançamento seja um código de erro.
 */
bool Lancamento::verificarErro(int codigo){
	return (valor == codigo);
}
