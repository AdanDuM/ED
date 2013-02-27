/*
 * Cliente.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */
#include "Cliente.h"
#include<cstdlib>
#include<stdio.h>
#include<iostream>
#include<time.h>
namespace Projeto1 {

Cliente::Cliente() {
	// TODO Auto-generated constructor stub
	valorCompras = 0;
	gerarTotalDeCompras(); //entre 2 e 100
	calcularValorDeCompras(); //cada item varia entre 1 e 90r$ dai td junto é colocado aqui
	decidirCheque(); //True quando for pagamento em cheque
	chegada = 0; //horario de chegada do cliente
	saida = 0; //horario de saida do cliente
}
Cliente::Cliente(int c) {
	// TODO Auto-generated constructor stub
	valorCompras = 0;
	gerarTotalDeCompras(); //entre 2 e 100
	calcularValorDeCompras(); //cada item varia entre 1 e 90r$ dai td junto é colocado aqui
	decidirCheque(); //True quando for pagamento em cheque
	chegada = c; //horario de chegada do cliente
	saida = 0; //horario de saida do cliente
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

/**
 * Método que fornece o lucro gerado pelo caixa durante a simulação.
 *
 * Para tal fornecimento ele subtrai seu sálario, que é dobrado pois ele está em hora extra, de seu faturamento total.
 *
 * @return lucro gerado pelo caixa.
 */
void Cliente::gerarTotalDeCompras() {
	int total;
	do {
		total = (rand() % MAX_VALOR) + MIN_VALOR;
	} while (total < 2 || total > 100);
	totalCompras = (rand() % MAX_COMPRAS) + MIN_COMPRAS;
}
/**
 * Método que calcula o valor de cada compra do cliente.
 *
 * Para isso ele usa o metodo "rand()", que gera um numero aleatório,e delimita o intervalo de geração entre as constantes: MAX_VALOR e MIN_VALOR.
 */
void Cliente::calcularValorDeCompras() {
	for (int i = 0; i < totalCompras; i++) {
		int valor;
		do {
			valor = (rand() % MAX_VALOR) + MIN_VALOR;
		} while (valor < 1 || valor > 90);
		valorCompras += valor;

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
