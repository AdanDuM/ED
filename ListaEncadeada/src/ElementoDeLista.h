/*
 * ElementoDeLista.h
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */

#ifndef ELEMENTODELISTA_H_
#define ELEMENTODELISTA_H_
#include "InfoLista.h"


/*********************************************************************************************************************
 * 										Dicionario de Dados
 * ___________________________________________________________________________________________________________________
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |info    	 |      InfoLista* | Ponteiro que aponta para a posição de memoria do objeto que contem a informação  |
 * |             |                 | do elemento da lista.  	                                          			  |
 * |proximo 	 |ElementoDeLista* | Ponteiro que contem a posição(index) do primeiro elemento da lista.			  |
 * |_____________|_________________|__________________________________________________________________________________|
  ********************************************************************************************************************/

/**
 * Representação de um objeto que será integrado à Lista.
 */
class ElementoDeLista {
public:
	ElementoDeLista();
	ElementoDeLista(InfoLista *info);
	virtual ~ElementoDeLista();
	ElementoDeLista *proximo;
	InfoLista *info;
};

#endif /* ELEMENTODELISTA_H_ */
