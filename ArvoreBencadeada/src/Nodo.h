/*
 * Nodo.h
 *
 *  Created on: 30/11/2012
 *      Author: tiago
 */

#ifndef NODO_H_
#define NODO_H_

#define LISTA_VAZIA 0
#define LISTA_CHEIA -2
#define ERRO_POSICAO -3
#define k 6
#include "Info.h"

#include "Chave.h"
class Chave;
namespace ArvoreB{
class Nodo {
public:
	Nodo();
	Nodo(bool folha);
	virtual ~Nodo();

	Chave *primeiro;
	int tamanho;
	bool folha;

	int adicionaB(Nodo *raiz, Chave *dado);
	void mostrarLista();

private:
	int adiciona(Chave *dado);
	int adicionaNaPosicao(Chave *dado, int posicao);
	int adicionaNoInicio(Chave *dado);
	Nodo* selecionaRamoDecida(Nodo *raiz, Chave *dado);
	void divideNodo(Nodo *raiz, Chave *dado);
	bool maior(Info *dado1, Info *dado2);
	bool nodoCheio(Nodo *filho);
	bool vazia();
};
}




#endif /* NODO_H_ */
