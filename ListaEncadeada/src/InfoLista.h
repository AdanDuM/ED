/*
 * InfoLista.h
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */

#ifndef INFOLISTA_H_
#define INFOLISTA_H_
/*********************************************************************************************************************
 * 										Dicionario de Dados
 * ___________________________________________________________________________________________________________________
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |nome    	 |      caracter*  | Ponteiro que aponta para a posição de memoria do primeiro caracter da string que |
 * |             |                 | contem a  informação referente ao nome.                             			  |
 * |telefone  	 |      caracter*  | Ponteiro que aponta para a posição de memoria do primeiro caracter da string que |
 * |             |                 | contem a  informação referente ao telefone.                             		  |
  ********************************************************************************************************************/

/**
 * Classe que representa as informações de um elemento de uma Lista.
 */
class InfoLista{
public:
	InfoLista();
	InfoLista(char *nome, char *tel);
	virtual ~InfoLista();
	bool maior(InfoLista *elemento);
	bool igual(InfoLista *elemento);
	bool menor(InfoLista *elemento);
	void mostrar();
	char *nome;
	char *telefone;
};

#endif /* INFOLISTA_H_ */
