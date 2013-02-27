/*
 * Cliente.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */
#include "Cliente.h"
#include<cstdlib>
#include<stdio.h>
#include<time.h>
namespace Projeto1 {

Cliente::Cliente() {
	// TODO Auto-generated constructor stub
	gerarTotalDeCompras(); //entre 2 e 100
	calcularValorDeCompras(); //cada item varia entre 1 e 90r$ dai td junto é colocado aqui
	decidirCheque(); //True quando for pagamento em cheque
	chegada = 0; //horario de chegada do cliente
	saida = 0; //horario de saida do cliente
	srand(time(NULL));
}

/**
 * Construtor que gera um objeto da classe Cliente.
 *
 *@param c: horario de chegada do cliente ao supermercado.
 */
Cliente::Cliente(int c) {
	// TODO Auto-generated constructor stub
	gerarTotalDeCompras(); //entre 2 e 100
	calcularValorDeCompras(); //cada item varia entre 1 e 90r$ dai td junto é colocado aqui
	decidirCheque(); //True quando for pagamento em cheque
	chegada = c; //horario de chegada do cliente
	saida = 0; //horario de saida do cliente
	srand(time(NULL));
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

/**
 * Método que gera o npúmero total de compras de um cliente.
 *
 * Para isso ele usa o metodo "rand()", que gera um numero aleatório,e delimita o intervalo de geração entre as constantes: MAX_COMPRAS e MIN_COMPRAS.
 */
void Cliente::gerarTotalDeCompras() {
	totalCompras = (rand() % MAX_COMPRAS) + MIN_COMPRAS;
}

/**
 * Método que calcula o valor de cada compra do cliente.
 *
 * Para isso ele usa o metodo "rand()", que gera um numero aleatório,e delimita o intervalo de geração entre as constantes: MAX_VALOR e MIN_VALOR.
 */
void Cliente::calcularValorDeCompras() {
	for (int i = 0; i < totalCompras; i++) {
		valorCompras += (rand() % MAX_VALOR) + MIN_VALOR;
	}
}

/**
 * Método que gera a forma de pagamento de um cliente.
 *
 * Para isso tem uma probabilidade de 20% para pagamento em cheque e 80% para dinheiro.
 */
void Cliente::decidirCheque() {
	cheque = false;
	int escolha = (rand() % 100) + 1;
	if (escolha <= PROB_CHEQUE)
		cheque = true;
}
} /* namespace Fila */
