/*
 * Nodo.h
 *
 *  Created on: Jan 10, 2013
 *      Author: will
 */

#ifndef NODO_H_
#define NODO_H_

#define ORDEM 10000

namespace Arvores {

class Nodo {
public:
	Nodo();
	Nodo(bool f);
	virtual ~Nodo();
	bool folha;
	int numeroChaves;
	Nodo** filhos;
	int* chaves;
	int insereEmOrdem(int chave);
	void inserirFilho(Nodo* filho,int posicao);
	void inserirFilho(Nodo* filho);
	bool cheio();
	Nodo* selecionaDescida(int chave);
	int acharPosicao(int chave);
	void mostrarNodo();

};

} /* namespace Ordenacao */
#endif /* NODO_H_ */
