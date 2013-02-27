/*
 * ElementoFila.h
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef ELEMENTOFILA_H_
#define ELEMENTOFILA_H_
#include "ListaDupla.h"

/*************************************************************************************************************************
 * 										Dicionario de Dados
 * _______________________________________________________________________________________________________________________
 * |Nome 		      |		 Tipo       | Descrição		 																  |
 * |__________________|_________________|_________________________________________________________________________________|
 * |lista    	      |    ListaDupla*  | Ponteiro que aponta para a posição de memoria do objeto que contem a informação |
 * |                  |                 | da lista que contem a rota.  	                                          		  |
 * |proximo 	      | ElementoDeFila* | Ponteiro que contem a posição(index) do proximo elemento da fila.			      |
 * |numeroLinhaOnibus |    inteiro      | Inteiro que contem o codigo da Linha de Onibus.                			      |
 * |empresaOnibus     |    char *       | String que contem o nome da Empresa de Onibus.                			      |
 * |__________________|_________________|_________________________________________________________________________________|
  *************************************************************************************************************************/

/**
 * Classe que representa um objeto pertencente a fila de listas.
 */
class ElementoFila {
public:
	ElementoFila();
	ElementoFila(int numeroLinhaOnibus, char *empresaOnibus, ListaDupla *lista);
	virtual ~ElementoFila();
	ElementoFila *proximo;
	ListaDupla *lista;

	int numeroLinhaOnibus;
	char *empresaOnibus;


	void mostrar();
};

#endif /* ELEMENTOFILA_H_ */
