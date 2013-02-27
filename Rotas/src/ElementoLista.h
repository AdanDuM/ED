/*
 * ElementoLista.h
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef ELEMENTOLISTA_H_
#define ELEMENTOLISTA_H_

#include "InfoLista.h"


/*********************************************************************************************************************
 * ____________________________________________________________________________________________________________________
 * |										Dicionario de Dados                                                       |
 * |__________________________________________________________________________________________________________________|
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |info    	 |   InfoLista*    | Ponteiro que aponta para a posição de memoria do objeto que contem a informação  |
 * |             |                 | do elemento da lista.  	                                          			  |
 * |proximo 	 |ElementoDeLista* | Ponteiro que contem a posição(index) do proximo elemento na lista.			      |
 * |anterior 	 |ElementoDeLista* | Ponteiro que contem a posição(index) do anterior elemento na lista.		      |
 * |_____________|_________________|__________________________________________________________________________________|
  ********************************************************************************************************************/


/**
 * Classe que representa um objeto pertencente a uma lista.
 */
class ElementoLista {
public:
	ElementoLista();
	ElementoLista(InfoLista *info);
	virtual ~ElementoLista();
	ElementoLista* proximo;
	ElementoLista* anterior;
	InfoLista *info;
};

#endif /* ELEMENTOLISTA_H_ */
