/*
 * ArvoreB.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: will
 */

#include "ArvoreB.h"
#include<iostream>

using namespace std;

namespace Arvores {

ArvoreB::ArvoreB() {
	// TODO Auto-generated constructor stub
	raiz = new Nodo();
}

ArvoreB::~ArvoreB() {
	// TODO Auto-generated destructor stub
}

void ArvoreB::insere(int chave) {
	if (raiz->cheio()) {
		Nodo * antiga = raiz;
		raiz = new Nodo(false);
//		cout << "cheiao" << endl;
		raiz->inserirFilho(antiga);
		dividirNodo(raiz, antiga);
	//	cout << "sai div" << endl;
		insereNaoCheio(chave, raiz);
	} else {
		insereNaoCheio(chave, raiz);
	}
}

void ArvoreB::insereNaoCheio(int chave, Nodo* raiz) {
	//cout<<"raiz "<< raiz<< "raiz mesmo?" << raiz->raiz<< endl;
	if (raiz->folha) {
		//cout << "folha " << endl;
		raiz->insereEmOrdem(chave);
	} else {
		//cout << "nfolha " << endl;

		/*for(int i =0;i<(ORDEM *2);i++){
			cout<<"filho "<< raiz->filhos[i]<<endl;
		}*/
		Nodo* filho = raiz->selecionaDescida(chave);

		//cout << "selecionado " << filho << endl;
		if (filho->cheio()) {
			//cout << "dividindo filho " << endl;

			dividirNodo(raiz, filho);
			filho = raiz->selecionaDescida(chave);
		}
		insereNaoCheio(chave, filho);
	}
}

int buscar(int chave) {
	return 0;
}
void ArvoreB::dividirNodo(Nodo* pai, Nodo* filho) {
//somente para quando pai nao esta cheio se nao é outra coisa
	Nodo* irmao = new Nodo();
	irmao->folha = filho->folha;
	int mediana = (ORDEM - 1);
	int i;
	for (i = mediana + 1; i < (ORDEM * 2) - 1; i++) {
		irmao->insereEmOrdem(filho->chaves[i]);
		filho->chaves[i] = 0;
	}
	if(!filho->folha){
		for (i = mediana + 1; i < (ORDEM * 2); i++) {
				irmao->inserirFilho(filho->filhos[i]);
			}
	}
	filho->numeroChaves = ORDEM - 1;

	int pos = pai->insereEmOrdem(filho->chaves[mediana]);
	filho->chaves[mediana] = 0;

	//pai->inserirFilho(filho, pos);
	pos++;
	pai->inserirFilho(irmao,pos);
}
void ArvoreB::mostrarInOrdem(Nodo* nodo) {
	if (nodo->folha) {
		nodo->mostrarNodo();
	} else {
		int i = 0;
		while (i < nodo->numeroChaves) {
			mostrarInOrdem(nodo->filhos[i]);
			//cout << "chave " << nodo->chaves[i] << " pos " << i << endl;
			cout << nodo->chaves[i] << endl;
			i++;
		}
		mostrarInOrdem(nodo->filhos[i]);
	}
}
};


/*Nodo* irmao = new Nodo();
	irmao->folha = filho->folha;
	int mediana = (ORDEM - 1);
	int i;
	for (i = mediana + 1; i < (ORDEM * 2) - 1; i++) {
		irmao->insereEmOrdem(filho->chaves[i]);
		irmao->inserirFilho(filho->filhos[i]);
		filho->chaves[i] = 0;
	}
	irmao->inserirFilho(filho->filhos[i]);
	filho->numeroChaves = ORDEM - 1;
	int pos = pai->insereEmOrdem(filho->chaves[mediana]);
	filho->chaves[mediana] = 0;

	pai->inserirFilho(filho, pos++);
	pai->inserirFilho(irmao, pos);*/
