/*
 * Nodo.cpp
 *
 *  Created on: Jan 10, 2013
 *      Author: will
 */
#include "Nodo.h"
#include<iostream>

using namespace std;

namespace Arvores {

Nodo::Nodo() {
	// TODO Auto-generated constructor stub
	chaves = new int[((ORDEM * 2) - 1)];
	filhos = new Nodo*[ORDEM * 2];
	folha = true;
	numeroChaves = 0;
}
Nodo::Nodo(bool f) {
	// TODO Auto-generated constructor stub
	chaves = new int[((ORDEM * 2) - 1)];
	filhos = new Nodo*[ORDEM * 2];
	folha = f;
	numeroChaves = 0;
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

int Nodo::insereEmOrdem(int chave) {
	//cout<<"insereEmOrdem---chave :  " <<chave << " ---- "<< numeroChaves<< endl;
	int posicao = 0;
	if (numeroChaves == 0) {
		chaves[posicao] = chave;
		numeroChaves++;
	} else {
		posicao = acharPosicao(chave);
		numeroChaves++;
		for (int i = numeroChaves; i > posicao; i--) {
			chaves[i] = chaves[i - 1];
		}
		chaves[posicao] = chave;
	}
	return posicao;
}
int Nodo::acharPosicao(int chave) {
	//cout<<"acharPosicao---chave :  " <<chave << " ---- "<< numeroChaves<< endl;
	int posicao = 0;
		while( chaves[posicao] != 0 && chaves[posicao] < chave) {
			posicao++;
			//cout <<  " pos  " << posicao << endl;

		}
	return posicao;
}
bool Nodo::cheio() {
	return numeroChaves == ((ORDEM * 2) - 1);
}
Nodo* Nodo::selecionaDescida(int chave) {
	int i = 0;
	while (chaves[i] != 0 && chave > chaves[i]) {
		i++;
	}
	return filhos[i];

}

void Nodo::inserirFilho(Nodo* filho, int posicao) {
	//posicao contando a partir de 0
		for (int i = (ORDEM * 2) - 1; i > posicao; i--) {
			filhos[i + 1] = filhos[i];
		}
		filhos[posicao] = filho;
		folha = false;

}
void Nodo::inserirFilho(Nodo* filho) {
	//posicao contando a partir de 0
	int pos = 0;
	while (filhos[pos]) {
		pos++;
	}
	filhos[pos] = filho;
}
void Nodo::mostrarNodo() {
	//for (int i = 0; i < ((ORDEM * 2) - 1); i++) {
		//cout << "chave " << chaves[i] << " posicao " << i << endl;
	for (int i = 0; i < numeroChaves  ; i++) {

		cout << chaves[i] << endl;
	}
}

} /* namespace Ordenacao */
