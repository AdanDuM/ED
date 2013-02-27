/*
 * Pilha.h
 *
 *  Created on: Sep 14, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#ifndef PILHA_H_
#define PILHA_H_

#include<iostream>
#define MAXPILHA 30 //Constante que determina o tamanho máximo da pilha
#define PILHACHEIA -2//Constante de controle de pilha cheia
#define PILHAVAZIA -1//Constante de controle de pilha vazia

using namespace std;

namespace Pilha {
/**
 * Classe para representação de estruturas de dados Pilha.
 *
 * 	As pilhas são estruturas baseadas no princípio LIFO (last in, first out), na qual os dados que foram inseridos primeiros na pilha serão os últimos a serem removidos. Existem duas funções que se aplicam a todas as pilhas: EMPILHA (PUSH), que insere um dado no topo da pilha, e DESEMPILHAR (POP), que remove o item no topo da pilha.
 */
class Pilha
{
	public:
		Pilha();
		virtual ~Pilha();
		virtual int empilhar(int);
		virtual int desempilhar();
		virtual void mostrarPilha();
		virtual void limpar();
	private:
		int topo;//Variável que controla a quantidade de elementos da pilha.
		int pilha[MAXPILHA];//Array que contém a estrutura de dados pilha.
};

} /* namespace Pilha */

#endif /* PILHA_H_ */
