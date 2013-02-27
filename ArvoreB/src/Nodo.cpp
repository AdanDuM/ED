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
	chaves = new int[((T * 2) - 1)];
	filhos = new Nodo*[T * 2];
	folha = true;
	numeroChaves = 0;

}
Nodo::Nodo(bool f) {
	// TODO Auto-generated constructor stub
	chaves = new int[((T * 2) - 1)];
	filhos = new Nodo*[T * 2];
	folha = f;
	numeroChaves = 0;
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

void Nodo::mostrarNodo() {
	//for (int i = 0; i < ((ORDEM * 2) - 1); i++) {
		//cout << "chave " << chaves[i] << " posicao " << i << endl;
	for (int i = 0; i < numeroChaves  ; i++) {
		cout << chaves[i] << endl;
	}
}






} /* namespace Ordenacao */
