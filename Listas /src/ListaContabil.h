/*
 * ListaContabil.h
 *
 *  Created on: 25/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#ifndef LISTACONTABIL_H_
#define LISTACONTABIL_H_
#include "Lancamento.h"

#define MAXLISTA 100
#define LISTA_VAZIA -1
#define LISTA_CHEIA -2
#define ERRO_POSICAO -3

/**
 * Classe que representa uma lista que contém e opera sobre lançamentos.
 *
 * Lista é uma estrutura de dados abstrata que implementa uma coleção ordenada de valores, onde o mesmo valor pode ocorrer mais de uma vez. Uma instância de uma lista é uma representação computacional do conceito matemático de uma sequência finita, que é, uma tupla. Cada instância de um valor na lista normalmente é chamado de um item, entrada ou elemento da lista. Se o mesmo valor ocorrer várias vezes, cada ocorrência é considerada um item distinto.\n
 * http://pt.wikipedia.org/wiki/Lista
 */
class ListaContabil {
public:
	ListaContabil();
	virtual ~ListaContabil();
	int adiciona(Lancamento dado);
	int adicionaNoInicio(Lancamento dado);
	int adicionaNaPosicao(Lancamento dado, int posicao);
	int adicionaEmOrdem(Lancamento dado);

	Lancamento retira();
	Lancamento retiraDoInicio();
	Lancamento retiraDaPosicao(int posicao);
	Lancamento retiraEspecifico(Lancamento dado);

	int posicao(Lancamento dado);
	bool contem(Lancamento dado);
	bool maior(Lancamento um, Lancamento dois);
	bool igual(Lancamento um, Lancamento dois);
	bool menor(Lancamento um, Lancamento dois);
	void mostrarLista();
	int fornecaTotal();
	void limpar();
private:
	bool cheia();
	bool vazia();
	Lancamento lista[MAXLISTA];
	int ultimo;
};

#endif /* LISTACONTABIL_H_ */
