/*
 * ElementoDeLista.h
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef ELEMENTODELISTA_H_
#define ELEMENTODELISTA_H_
#include "InfoFila.h"
/*********************************************************************************************************************
 * 										Dicionario de Dados
 * ___________________________________________________________________________________________________________________
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |info    	 |      InfoFila*  | Ponteiro que aponta para a posição de memoria do objeto que contem a informação  |
 * |             |                 | do elemento da lista.  	                                          			  |
 * |proximo 	 |ElementoDeFila*  | Ponteiro que contem a posição(index) do primeiro elemento da lista.			  |
 * |_____________|_________________|__________________________________________________________________________________|
  ********************************************************************************************************************/
/**
 * Classe que representa um objeto pertencente a uma fila genérica.
 */
class ElementoDeFila {
public:
	ElementoDeFila();
	ElementoDeFila(InfoFila *info);
	virtual ~ElementoDeFila();
	ElementoDeFila *proximo;
	InfoFila *info;
};

#endif /* ELEMENTODELISTA_H_ */
