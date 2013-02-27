/*
 * ElementoDaListaCircular.h
 *
 *  Created on: 08/11/2012
 *      Author: tiago
 */

#ifndef ELEMENTODALISTACIRCULAR_H_
#define ELEMENTODALISTACIRCULAR_H_

#include "Caixa.h"
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

namespace Projeto1 {
/**
 * Representação de um objeto que será integrado à Lista.
 */
class ElementoDeListaCircular {
public:
	ElementoDeListaCircular();
	ElementoDeListaCircular(Caixa *caixa);
	virtual ~ElementoDeListaCircular();
	/** Proximo caixa da lista de caixas */
	ElementoDeListaCircular *proximo;
	/** Ponteiro para o caixa referente a este elemento de lista. */
	Caixa *caixa;
};
} /* namespace Projeto1 */
#endif /* ELEMENTODALISTACIRCULAR_H_ */
