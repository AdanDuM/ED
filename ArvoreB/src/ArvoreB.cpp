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

void ArvoreB::insere(int k) {
	Nodo *r = raiz;
	if (r->numeroChaves == 2 * T - 1) {
		//	cout << "cheio" << endl;
		Nodo* s = new Nodo();
		raiz = s;
		s->folha = false;
		s->numeroChaves = 0;
		s->filhos[0] = r;
		//	cout << "antes div" << endl;
		dividirNodo(s, 0, r);
		//	cout << "depois div" << endl;
		insereNaoCheio(k, s);
	} else {
		insereNaoCheio(k, r);
	}
}

void ArvoreB::dividirNodo(Nodo* pai, int i, Nodo* filho) {
//	cout << "i " << i << endl;
	Nodo* irmao = new Nodo();
	irmao->folha = filho->folha;
	irmao->numeroChaves = T - 1;
	int j;
	for (j = 0; j < T - 1; j++) {
		irmao->chaves[j] = filho->chaves[(j + T)];
		filho->chaves[(j + T)] = 0;
	}
	if (!filho->folha) {
		for (j = 0; j < T; j++) {
			irmao->filhos[j] = filho->filhos[j + T];
			filho->filhos[j + T] = 0;
		}
	}
	filho->numeroChaves = T - 1;
	for (j = pai->numeroChaves; j > i; j--) {
		pai->filhos[j + 1] = pai->filhos[j];
	}
	pai->filhos[i + 1] = irmao;
	for (j = pai->numeroChaves - 1; j > i - 1; j--) {
		pai->chaves[j + 1] = pai->chaves[j];
	}
	pai->chaves[i] = filho->chaves[T - 1];
	filho->chaves[T - 1] = 0;
	pai->numeroChaves++;
}

void ArvoreB::insereNaoCheio(int k, Nodo* x) {
	int i = x->numeroChaves - 1;
	//cout << "inserenc " << "x " << x << "   " << x->numeroChaves << " chave "
	//		<< k << endl;
	if (x->folha) {
		//cout << "folha" << endl;
		while (i >= 0 && k < x->chaves[i]) {
			x->chaves[i + 1] = x->chaves[i];
			i--;
		}
		x->chaves[i + 1] = k;
		x->numeroChaves++;
	} else {
		//cout << "nfolha" << endl;

		while (i >= 0 && k < x->chaves[i]) {
			i--;
		}
		i++;
		if (x->filhos[i]->numeroChaves == (2 * T) - 1) {
			dividirNodo(x, i, x->filhos[i]);
			if (k > x->chaves[i]) {
				i++;
			}
		}
		insereNaoCheio(k, x->filhos[i]);
	}
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
	raiz->mostrarNodo();
}
int ArvoreB::buscar(Nodo* x, int k) {
	cout<<"dentro " << x<<endl;
	int i = 0;
	while (i < x->numeroChaves && k > x->chaves[i]) {
		i++;
	}
	if(i<= x->numeroChaves && k == x->chaves[i]){
		return x->chaves[i];
	}
	if(x->folha){
		return 0;
	}else{
		return buscar(x->filhos[i],k);
	}
	}
}
;
