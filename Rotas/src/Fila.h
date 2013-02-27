/*
 * Fila.h
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef FILA_H_
#define FILA_H_

#include "ElementoFila.h"

/*********************************************************************************************************************
 * 										Dicionario de Dados
 * ___________________________________________________________________________________________________________________
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |FILA_VAZIA   |    inteiro	   | Codigo de identificação de uma situação em que a fila esta vazia, seu valor é 0  |
 * |FILA_CHEIA   |    inteiro	   | Codigo de identificação de uma situação em que a fila esta cheia, seu valor é -2 |
 * |ERRO_POSICAO |    inteiro	   | Codigo de identificação de uma situação em que a posição(index) que tentou ser	  |
 * |		     |				   | usada esta errada, seu valor é -3												  |
 * |tamanho		 |	 inteiro	   | Inteiro usado para guardar a quantidade de elementos na fila(ou tamnaho desta).  |
 * |ultimo  	 |ElementoDeFila * | Ponteiro que aponta para a posição de memoria do ultimo elemento da lista.       |
 * |primeiro	 |ElementoDeFila * | Ponteiro que aponta para a posição de memoria do primeiro elemento da lista.	  |
 * |_____________|_________________|__________________________________________________________________________________|
  ********************************************************************************************************************/




#define FILA_VAZIA 0
#define FILA_CHEIA -2
#define ERRO_POSICAO -3

/**
 * Classe que modela uma Fila Encadeada.
 *
 *
 *
 * As filas são estruturas baseadas no princípio FIFO (first in, first out),
 * em que os elementos que foram inseridos no início são os primeiros a serem removidos.
 * Uma fila possui duas funções básicas: Enfileirar(ENQUEUE), que adiciona um elemento ao final da fila,
 * e Desenfileirar(DEQUEUE), que remove o elemento no início da fila.
 * A operação Desenfileirar(DEQUEUE) só pode ser aplicado se a fila não estiver vazia,
 * causando um erro de underflow ou fila vazia se esta operação for realizada nesta situação.
 *
 * Para mais informações acesse:
 * http://pt.wikipedia.org/wiki/FIFO
 */
class Fila {
public:
	Fila();
	virtual ~Fila();
	ElementoFila *primeiro, *ultimo;
	int tamanho;
	int enfileirar(int numLinha, char* empresa, ListaDupla *lista);
	ListaDupla* desenfileirar();
	void limpar();

	void mostrar();
	int buscar(char *origem,char *destino, int hora);
private:
	bool vazia();
};

#endif /* FILA_H_ */
