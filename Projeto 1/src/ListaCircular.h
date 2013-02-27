/*
 * ListaCircular.h
 *
 *  Created on: 08/11/2012
 *      Author: tiago
 */

#ifndef LISTACIRCULAR_H_
#define LISTACIRCULAR_H_

#include "ElementoDaListaCircular.h"
#include "Caixa.h"

#define LISTA_VAZIA 1
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

namespace Projeto1 {
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
class ListaCircular {
public:
	ListaCircular();
	virtual ~ListaCircular();
	/** Primeiro elemento da lista circular. */
	ElementoDeListaCircular *sentinela;
	/** Tamanho da lista circular */
	int tamanho;
	int adiciona(Caixa *caixa);

	void mostrarLista();
private:
	bool vazia();
};
} /* namespace Projeto1 */
#endif /* LISTACIRCULAR_H_ */
