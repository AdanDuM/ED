/*
 * ListaDupla.h
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef LISTADUPLA_H_
#define LISTADUPLA_H_

#include "ElementoLista.h"


/*********************************************************************************************************************
 * ______________________________________________________________________________________________________________________
 * |										Dicionario de Dados														     |
 * |_____________________________________________________________________________________________________________________|
 * |Nome 		    |		 Tipo    | Descrição																		 |
 * |________________|________________|___________________________________________________________________________________|
 * |LISTA_VAZIA     |    inteiro	 | Codigo de identificação de uma situação em que a lista esta vazia, seu valor é 0  |
 * |LISTA_CHEIA     |    inteiro	 | Codigo de identificação de uma situação em que a lista esta cheia, seu valor é -2 |
 * |ERRO_POSICAO    |    inteiro	 | Codigo de identificação de uma situação em que a posição(index) que tentou ser	 |
 * |				|				 | usada esta errada, seu valor é -3												 |
 * |tamanho  		| 	 inteiro	 | Inteiro que contem a quantidade de elemntos na lista                          	 |
 * |primeiro	  	| ElementoLista* | Ponteiro que aponta para o primeiro elemento da lista                             |
 * |________________|________________|___________________________________________________________________________________|
 *************************************************************************************************************************/



#define LISTA_VAZIA 0
#define LISTA_CHEIA -2
#define ERRO_POSICAO -3
/*
 * Classe que modela uma Lista Duplamente Encadeada.
 *
 * Uma lista duplamente ligada (ou lista duplamente encadeada)é uma extensão da lista simplesmente ligada
 * (ou lista simplesmente encadeada).
 *
 * Numa lista cada elemento, ou nó, é composto normalmente por uma variável que guarda a informação(Objeto,
 * inteiro, cadeia de caractéres, etc) e dois ponteiros (referências a endereços de memória) que permitem
 * a ligação entre os vários nós desta lista. Este tipo de lista é conhecido por "Duplamente ligada" ou
 * "Duplamente encadeada" exatamente pelo fato de possuir duas váriaveis de controle (ponteiros) ao contrário
 * da lista simplesmente ligada que possui somente um, o qual aponta para o próximo elemento da lista.
 *
 * A função destas variáveis é guardar o endereço de memória do nó anterior e do nó posterior, identificados
 * normalmente como "prev" ou "previous" e "next". Com estas estruturas podemos realizar diversas tarefas que
 * seriam impossiveis ou muito dispendiosas com uma lista simplesmente encadeada.
 * No modelo mais simples deste tipo de lista, ao criar a lista o primeiro nó tem seu ponteiro "previous"
 * apontando sempre para nulo e o último nó com seu "next" apontando para nulo.
 * Este modelo não é muito confiável, já que não há um controle efetivo para saber quem é o primeiro e quem
 * é o ultimo elemento, já que a única maneira de extrair tal informação é verificar quem possui o "prev" ou
 * o "next" nulo.
 *
 * Para mais informações acesse:
 * http://pt.wikipedia.org/wiki/Lista_duplamente_ligada
 */
class ListaDupla {
public:
	ListaDupla();
	virtual ~ListaDupla();
	int adiciona(InfoLista *info);
	int adicionaNaPosicao(InfoLista *info, int posicao);
	int adicionaNoInicio(InfoLista *info);
	int adicionaEmOrdem(InfoLista *info);

	InfoLista* retira();
	InfoLista* retiraDoInicio();
	InfoLista* retiraDaPosicao(int posicao);
	InfoLista* retiraEspecifico(ElementoLista *dado);

	bool vazia();
	bool maior(InfoLista *info1, InfoLista *info2);
	bool menor(InfoLista *info1, InfoLista *info2);
	bool igual(InfoLista *info1, InfoLista *info2);
	int posicao(ElementoLista *elemento);
	bool contem(ElementoLista *elemento);

	void mostrar();
	void limpar();


	ElementoLista *primeiro;
	int tamanho;
};

#endif /* LISTADUPLA_H_ */
