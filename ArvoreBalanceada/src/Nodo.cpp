/*
 * Nodo.cpp
 *
 *  Created on: 01/11/2012
 *      Author: grad
 */

#include "Nodo.h"

#include<iostream>

Nodo::Nodo() {
	// TODO Auto-generated constructor stub

}

Nodo::Nodo(int v) {
	// TODO Auto-generated constructor stub
	valor = v;
	filhoDireita = 0;
	filhoEsquerda = 0;
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

Nodo* Nodo::construir(int inferior, int superior, int vetor[]) {
	int mediana = ((inferior + superior)/2);
	std::cout << "mediana "<<mediana<< std::endl;

	Nodo *volta;
	if (superior - inferior <=1) {
		volta = new Nodo(vetor[mediana]);
		volta->filhoEsquerda = new Nodo(vetor[(mediana)-1]);
		volta->filhoDireita = new Nodo(vetor[(mediana+1)]);
		std::cout << "valor " << volta->valor << " esquerda "<< volta->filhoEsquerda->valor << " direita "<< volta->filhoDireita->valor << std::endl;
		return volta;
	} else {
		volta = new Nodo(vetor[mediana]);
		volta->filhoDireita = construir(mediana + 1, superior,vetor);
		volta->filhoEsquerda = construir(inferior, mediana - 1,	vetor);
		std::cout << "valor " << volta->valor << " esquerda "<< volta->filhoEsquerda->valor << " direita "<< volta->filhoDireita->valor << std::endl;
		return volta;
	}
	return 0;
}

void Nodo::buscar(Nodo* raiz, int inicio, int fim){
	if(raiz != NULL){
		if(raiz->valor <= inicio){
			if(raiz->valor == inicio){
				std::cout << raiz->valor <<std::endl;
			}
			buscar(raiz->filhoDireita, inicio, fim);
		}

		if(raiz->valor > inicio){
			buscar(raiz->filhoEsquerda, inicio, fim);
			if(raiz->valor <= fim){
				if((raiz->valor % 2 == 0))
					std::cout << raiz->valor << std::endl;

				buscar(raiz->filhoDireita, inicio, fim);
			}
		}

	}

}

