/*
 * CabecaDePilha.cpp
 *
 *  Created on: Oct 13, 2012
 *      Author: will
 */

#include "Pilha.h"
#include "iostream"

namespace PilhaEncadeada {

Pilha::Pilha() {
	// TODO Auto-generated constructor stub
	topo = 0;
	tamanho = 0;
	diametroTopo =0;
}

Pilha::~Pilha() {
	// TODO Auto-generated destructor stub
}
int Pilha::empilha(Disco *novo) {
	if (!novo) {
		return ERRO_MOVIMENTO;
	}
	if (vazia()) {
		topo = novo;
		std::cout << "Movendo de " << novo->origem << " para " << id <<" o "<< novo->diametro<< std::endl;
		diametroTopo = topo->diametro;
		tamanho++;
		return 0;
	}
	novo->proximo = topo;
	topo = novo;
	diametroTopo = topo->diametro;
	tamanho++;
	std::cout << "Movendo de " << novo->origem << " para " << id <<" o "<< novo->diametro<< std::endl;
	return 0;
}
Disco* Pilha::desempilha() {
	if (vazia()) {
		return PILHA_VAZIA;
	}
	Disco* sai = topo;
	topo = topo->proximo;
	sai->origem = id;
	tamanho--;
	if(vazia())
		diametroTopo = 0;
	else
		diametroTopo = topo->diametro;
	return sai;
}
bool Pilha::vazia() {
	return tamanho == PILHA_VAZIA;
}
bool Pilha::contem(Disco *examinado) {
	Disco *igual = topo;
	while ((igual) && (examinado != igual))
		igual = igual->proximo;
	return igual;
}
} /* namespace Fila */
