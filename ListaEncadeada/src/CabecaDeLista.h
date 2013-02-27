/*
 * CabecaDeLista.h
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */

#ifndef CABECADELISTA_H_
#define CABECADELISTA_H_
#include "ElementoDeLista.h"

#define LISTA_VAZIA 0
#define LISTA_CHEIA -2
#define ERRO_POSICAO -3

/*********************************************************************************************************************
 * 										Dicionario de Dados
 * ___________________________________________________________________________________________________________________
 * |Nome 		 |		 Tipo      | Descrição		 																  |
 * |_____________|_________________|__________________________________________________________________________________|
 * |LISTA_VAZIA  |    inteiro	   | Codigo de identificação de uma situação em que a lista esta vazia, seu valor é 0 |
 * |LISTA_CHEIA  |    inteiro	   | Codigo de identificação de uma situação em que a lista esta cheia, seu valor é -2|
 * |ERRO_POSICAO |    inteiro	   | Codigo de identificação de uma situação em que a posição(index) que tentou ser	  |
 * |		     |				   | usada esta errada, seu valor é -3												  |
 * |tamanho		 |	 inteiro	   | Inteiro usado para guardar a quantidade de elementos na lista(ou tamnaho desta). |
 * |primeiro	 |ElementoDeLista* | Ponteiro que aponta para a posição de memoria do primeiro elemento da lista.	  |
 * |_____________|_________________|__________________________________________________________________________________|
  ********************************************************************************************************************/



/**
 * Classe que modela uma lista encadeada.
 *
 * Uma lista encadeada ou lista ligada é uma estrutura de dados linear e dinâmica.
 * Ela é composta por células que apontam para o próximo elemento da lista.
 * Para "ter" uma lista ligada/encadeada, basta guardar seu primeiro elemento,
 * e seu último elemento aponta para uma célula nula.\n
 * Para mais informações acesse:\n
 * http://pt.wikipedia.org/wiki/Lista_ligada
 */
class CabecaDeLista {
public:
	CabecaDeLista();
	virtual ~CabecaDeLista();
	ElementoDeLista *primeiro;
	int tamanho;
	int adiciona(InfoLista *dado);//v
	int adicionaNoInicio(InfoLista *dado);//v
	int adicionaNaPosicao(InfoLista *dado, int posicao);//v
	int adicionaEmOrdem(InfoLista *dado);//v

	InfoLista* retira();//v
	InfoLista* retiraDoInicio();//v
	InfoLista* retiraDaPosicao(int posicao);//v
	InfoLista* retiraEspecifico(ElementoDeLista *elemento);//v

	int posicao(ElementoDeLista *elemento);//v
	bool maior(InfoLista *dado1, InfoLista *dado2);//v
	bool igual(InfoLista *dado1, InfoLista *dado2);//v
	bool menor(InfoLista *dado1, InfoLista *dado2);//v
	void mostrarLista();//v
	void limpar();//v
private:
	bool vazia();//v
};

#endif /* CABECADELISTA_H_ */
