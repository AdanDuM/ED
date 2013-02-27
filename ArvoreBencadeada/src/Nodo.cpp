/*
 * Nodo.cpp
 *
 *  Created on: 30/11/2012
 *      Author: tiago
 */
#include <iostream>

#include "Nodo.h"


namespace ArvoreB{
Nodo::Nodo() {
	// TODO Auto-generated constructor stub

}
Nodo::Nodo(bool fol) {
	// TODO Auto-generated constructor stub
	folha = fol;
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

int Nodo::adicionaNaPosicao(Chave *dado, int posicao) {
	Chave *anterior;
	if (posicao > tamanho + 1) {
		return ERRO_POSICAO;
	} else {
		if (posicao == 1) {
			return adicionaNoInicio(dado);
		} else {
			anterior = primeiro;
			for (int i = 0; i < posicao - 2; i++) {
				anterior = anterior->proximo;
			}
			dado->proximo = anterior->proximo;
			anterior->proximo = dado;
			dado->anterior = anterior;
			dado->proximo->anterior = dado;
			tamanho++;
			return tamanho;
		}
	}
}

int Nodo::adicionaNoInicio(Chave *dado){
	primeiro->anterior = dado;
	dado->proximo = primeiro;
	primeiro = dado;

	if(dado->proximo){
		dado->proximo->filhoEsquerda = dado->filhoDireita;
	}

	tamanho++;
	return 1;
}

int Nodo::adiciona(Chave *dado) {
	Chave *atual;
	int posicao;
	if (vazia()) {
		return adicionaNoInicio(dado);
	} else {
		atual = primeiro;
		posicao = 1;
		while (atual->proximo != 0 && maior(dado->info, atual->info)) {
			atual = atual->proximo;
			posicao++;
		}
		if (maior(dado->info, atual->info)) {
			return adicionaNaPosicao(dado, posicao + 1);
		} else {
			return adicionaNaPosicao(dado, posicao);
		}
	}
}

int Nodo::adicionaB(Nodo *raiz, Chave *dado) {
	Nodo *filho = 0;
	if(raiz->folha){
		//cout<<"chamando insere folha"<<endl;
		adiciona(dado);
	}else{
		filho = selecionaRamoDecida(raiz, dado);
		adicionaB(filho, dado);
	}

	if(nodoCheio(filho)){
		//cout<<"chamando divide nodo"<<endl;
		divideNodo(raiz, dado);
	}
	return 0;
}

Nodo* Nodo::selecionaRamoDecida(Nodo *raiz, Chave *dado){
	return 0;
}

void divideNodo(Nodo *raiz, Chave *dado){

}

bool Nodo::nodoCheio(Nodo *filho){
	return tamanho == ((2*k)+1);
}


bool Nodo::maior(Info *dado1, Info *dado2) {
	return dado1->maior(dado2);
}


void Nodo::mostrarLista() {
	Chave* atual = primeiro;
	if (vazia()) {
		std::cout << "Lista vazia." << std::endl;
	}
	while (atual) {
		atual->info->mostrar();
		atual = atual->proximo;
	}
}

bool Nodo::vazia(){
	return tamanho == LISTA_VAZIA;
}











}
