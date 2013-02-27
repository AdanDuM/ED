/*
 * ArvoreB.h
 *
 *  Created on: Jan 21, 2013
 *      Author: will
 */

#ifndef ARVOREB_H_
#define ARVOREB_H_
#include "Nodo.h"
#include <fstream>

using namespace std;
namespace Arvores {

class ArvoreB {

public:
	ArvoreB();
	virtual ~ArvoreB();
	void insereNaoCheio(string chave,Nodo* raiz);
	void insere(string chave);
	Nodo* raiz;
	void mostrarInOrdem(Nodo* nodo);
	bool buscar(Nodo* raiz, string chave);
	void dividirNodo(Nodo* pai,int idx, Nodo* filho);
	fstream arquivo;

	bool maior(string chavePrimaria, string outro);
	bool menor(string chavePrimaria, string outro);
	bool igual(string chavePrimaria, string outro);
	void mostrarConteudo(string chave);
};

} /* namespace Ordenacao */
#endif /* ARVOREB_H_ */
