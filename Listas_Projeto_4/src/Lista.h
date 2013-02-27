/*
 * Lista.h
 *
 *  Created on: 02/10/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#ifndef LISTA_H_
#define LISTA_H_

/*********************************************************************************************************************
 * 										Dicionario de Dados															 |
 * __________________________________________________________________________________________________________________|
 * Nome 		|		 Tipo    | Descrição																		 |
 * MAXLISTA		|	 inteiro	 | Definição do numero maximo de componenetes da lista, seu valor é 100				 |
 * LISTA_VAZIA  |    inteiro	 | Codigo de identificação de uma situação em que a lista esta vazia, seu valor é -1 |
 * LISTA_CHEIA  |    inteiro	 | Codigo de identificação de uma situação em que a lista esta cheia, seu valor é -2 |
 * ERRO_POSICAO |    inteiro	 | Codigo de identificação de uma situação em que a posição(index) que tentou ser	 |
 * 				|				 | usada esta errada, seu valor é -3												 |
 * ultimo  		| 	 inteiro	 | Inteiro que contem a posição(index) do ultimo elemento da lista, usado tambem	 |
 * 				|				 | para verificar quantos elementos tem na lista									 |
 * lista		| Array de *char | Array de ponteiros para array de char que forma o corpo da lista e contem todos   |
 * 				|				 | os elementos para serem operados, seu tamanho é o de MAXLISTA					 |
 ********************************************************************************************************************/
#define MAXLISTA 100
#define LISTA_VAZIA -1
#define LISTA_CHEIA -2
#define ERRO_POSICAO -3

//char* ERRO ="\0";
/**
 * Classe que representa uma lista que contém e opera sobre strings.
 *
 * Lista é uma estrutura de dados abstrata que implementa uma coleção ordenada de valores, onde o mesmo valor pode ocorrer mais de uma vez. Uma instância de uma lista é uma representação computacional do conceito matemático de uma sequência finita, que é, uma tupla. Cada instância de um valor na lista normalmente é chamado de um item, entrada ou elemento da lista. Se o mesmo valor ocorrer várias vezes, cada ocorrência é considerada um item distinto.\n
 * http://pt.wikipedia.org/wiki/Lista
 */
class Lista {
public:
	Lista();
	virtual ~Lista();
	int adiciona(char *dado);
	int adicionaNoInicio(char *dado);
	int adicionaNaPosicao(char *dado, int posicao);
	int adicionaEmOrdem(char *dado);

	char* retira();
	char* retiraDoInicio();
	char* retiraDaPosicao(int posicao);
	char* retiraEspecifico(char *dado);

	int posicao(char *dado);
	bool contem(char *dado);
	bool maior(char *dado1, char *dado2);
	bool igual(char *dado1, char *dado2);
	bool menor(char *dado1, char *dado2);
	void mostrarLista();
	void limpar();
private:
	char* lista[MAXLISTA];
	int ultimo;
	bool cheia();
	bool vazia();
};

#endif /* LISTA_H_ */
