/*
 * InfoLista.h
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
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
 * |modelo    	 |      caracter*  | Ponteiro que aponta para a posição de memoria do primeiro caracter da string que |
 * |             |                 | contem a  informação referente ao modelo.                             			  |
 * |preco    	 |      caracter*  | Ponteiro que aponta para a posição de memoria do primeiro caracter da string que |
 * |             |                 | contem a  informação referente ao preco.                             			  |
  ********************************************************************************************************************/

/**
 * Classe que representa as informações de um elemento de uma Fila.
 */
class InfoFila {
public:
	InfoFila();
	InfoFila(char *nome, char *tel, char *entrega, char *preco);
	virtual ~InfoFila();
	void mostrar(int semanas);
	char *nome, *telefone, *modelo, *preco;
};

#endif /* INFOLISTA_H_ */
