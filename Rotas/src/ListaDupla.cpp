/*
 * ListaDupla.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#include "ListaDupla.h"
#include "iostream"
ListaDupla::ListaDupla() {
	// TODO Auto-generated constructor stub
	tamanho = 0;
	primeiro = 0;
}

ListaDupla::~ListaDupla() {
	// TODO Auto-generated destructor stub
}

int ListaDupla::adiciona(InfoLista *info){
	if(vazia()){
		return adicionaNoInicio(info);
	}
	return adicionaNaPosicao(info, tamanho+1);
}

int ListaDupla::adicionaNoInicio(InfoLista *info){
	ElementoLista *novoElemento = new ElementoLista(info);
	if (novoElemento == 0)
		return LISTA_CHEIA;
	novoElemento->proximo = primeiro;
	novoElemento->anterior = 0;
	primeiro = novoElemento;
	if (novoElemento->proximo)
		novoElemento->proximo->anterior = novoElemento;
	tamanho ++;
	return tamanho;
}

int ListaDupla::adicionaNaPosicao( InfoLista *info, int posicao){
	if(posicao > tamanho +1 || posicao <1)
		return ERRO_POSICAO;
	if( posicao == 1)
		return adicionaNoInicio(info);
	ElementoLista *novoElemento = new ElementoLista(info);
	if (novoElemento == 0)
		return LISTA_CHEIA;
	ElementoLista* anterior = primeiro;
	for(int i = 0; i < posicao - 2; i++){
		anterior = anterior->proximo;
	}
		novoElemento->proximo = anterior->proximo;
		if(novoElemento->proximo )
			novoElemento->proximo->anterior = novoElemento;
		anterior->proximo = novoElemento;
		novoElemento->anterior = anterior;

		tamanho ++;

	return tamanho;
}

int ListaDupla::adicionaEmOrdem(InfoLista *info){
	ElementoLista *atual;
	int posicao;
	if (vazia()) {
		return adicionaNoInicio(info);
	} else {
		atual = primeiro;
		posicao = 1;
		while (atual->proximo != 0 && maior(info, atual->info)) {
			atual = atual->proximo;
			posicao++;
		}
		if (maior(info, atual->info)) {
			return adicionaNaPosicao(info, posicao + 1);
		} else {
			return adicionaNaPosicao(info, posicao);
		}
	}
}

InfoLista* ListaDupla::retira(){
	return retiraDaPosicao(tamanho);
}

InfoLista* ListaDupla::retiraDoInicio(){
	ElementoLista *saiu;
	InfoLista *volta;
	if(vazia())
		return 0;
	saiu = primeiro;
	volta = saiu->info;
	primeiro = saiu->proximo;
	if(primeiro)
		primeiro->anterior = 0;
	tamanho --;
	delete saiu;
	return volta;
}

InfoLista* ListaDupla::retiraDaPosicao(int posicao){
	ElementoLista *eliminar, *anterior;
	InfoLista *volta;
	if(posicao < 1 || posicao > tamanho)
		return 0;
	if(posicao == 1)
		return retiraDoInicio();
	anterior = primeiro;
	for(int i = 0; i < posicao - 2; i++ ){
		anterior = anterior->proximo;
	}
	eliminar = anterior->proximo;
	volta = eliminar->info;

	anterior->proximo = eliminar->proximo;
	if(eliminar->proximo)
		eliminar->proximo->anterior = anterior;

	tamanho --;
	delete eliminar;
	return volta;
}

InfoLista* ListaDupla::retiraEspecifico(ElementoLista *dado){
	return retiraDaPosicao(posicao(dado));
}

bool ListaDupla::vazia(){
	return tamanho == LISTA_VAZIA;
}

bool ListaDupla::maior(InfoLista *info1, InfoLista *info2){
	return info1->maior(info2);
}

bool ListaDupla::menor(InfoLista *info1, InfoLista *info2){
	return info1->menor(info2);
}

bool ListaDupla::igual(InfoLista *info1, InfoLista *info2){
	return info1->igual(info2);
}

int ListaDupla::posicao(ElementoLista *elemento){
	if (vazia()) {
		return LISTA_VAZIA;
	}
	int posicao = 1;
	ElementoLista *atual;
	atual = primeiro;
	while (atual != 0 && !(igual(atual->info, elemento->info))) {
		atual = atual->proximo;
		posicao++;
	}
	if (atual == 0) {
		return ERRO_POSICAO;
	}
	return posicao;
}

//************************************************************************************************
bool ListaDupla::contem(ElementoLista *elemento){
	return false;
}

void ListaDupla::mostrar(){
	ElementoLista *atual;
	atual = primeiro;
	if (vazia()) {
		std::cout << "Lista vazia." << std::endl;
	}
	while (atual) {
		atual->info->mostrar();
		atual = atual->proximo;
	}
}

void ListaDupla::limpar(){
	ElementoLista* i = primeiro;	//morre quando sair desse metodo
	ElementoLista* paraDeletar;	//morre quando sair desse metodo
	while (i) {				//percorre a lista e apaga os elementos do infolista
		delete i->info;				//chama o destrutor de infolista
		paraDeletar = i;
		i = i->proximo;
		delete paraDeletar;
	}
	tamanho = LISTA_VAZIA;
	primeiro = LISTA_VAZIA;
}
