/*
 * Nodo.h
 *
 *  Created on: 21/11/2012
 *      Author: tiago
 */

#ifndef NODO_H_
#define NODO_H_
#define ORDEM 6


#include "Info.h"


class Nodo {
public:
	Nodo();
	Nodo(bool folha);
	virtual ~Nodo();

	int numeroChaves;
	bool folha;

	Nodo** filhos;
	Info** chaves;


	//filhos = new Nodo[ORDEM*2];
	//chaves = new Info[(ORDEM*2)-1];


	void insereB(Nodo *raiz,Info *info);
	void insereFolhaB(Nodo *raiz,Info *info);
	Nodo* selecionaRamoDecida(Nodo *raiz,Info *info);
	void divideNodo(Nodo *raiz,Nodo *filho);
	bool nodoCheio(Nodo *filho);


	void divideFolha(Nodo *raiz,Nodo *filho);
	void divideSubArvore(Nodo *raiz,Nodo *filho);
	void divideRaiz(Nodo *raiz);

	void insereEmOrdem(Nodo *nodo, Info *info);
};

#endif /* NODO_H_ */
