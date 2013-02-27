/*
 * CabecaDeLista.cpp
 *
 *  Created on: 04/10/2012
 *   Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */
#include "iostream"
#include "CabecaDeFila.h"

/**
 * Método que constri um objeto que representa uma fila encadeado.
 */
CabecaDeFila::CabecaDeFila() {
	// TODO Auto-generated constructor stub
	tamanho = 0;
	primeiro = 0;
	ultimo = 0;
}

/**
 * Destrutor que exclui uma fila encadeada.
 *
 * Para isso utiliza o método limpar.
 */
CabecaDeFila::~CabecaDeFila() {
	// TODO Auto-generated destructor stub
	limpar();
}

/**
 * Método que adiciona um elemento da fila.
 *
 * Primeiramente teste se ainda é possivel adicionar um elemento à fila. Caso isso não seja verdadeiro ele retorna uma constante FILA_CHEIA.
 *
 * @param InfoFila *dado= ponteiro para um objeto da classe InfoFila.
 * @return FILA_CHEIA = constante que representa a falta de espaço na Fila.
 * @return tamanho = inteiro que informa a posição onde o dado foi inserido.
 */
int CabecaDeFila::enfileirar(InfoFila *dado) {
	ElementoDeFila *novo = new ElementoDeFila(dado);
	if (novo == 0) {
		return FILA_CHEIA;
	}
	if (vazia()) {
		primeiro = novo;
	} else {
		ultimo->proximo = novo;
	}
	novo->proximo = 0;
	ultimo = novo;
	tamanho++;
	dado->mostrar(tamanho);
	return tamanho;
}

/**
 *Método que remove um elemento da Fila.
 *Primeiramente testa se a Fila possui elementos. Caso possua ele remove o primeiro elemento, ou seja o primeiro que foi inserido.
 *
 *@return 0(NULL) = caso a Fila não possua elementos.
 *@return InfoFila = objeto que possui as informações do elemento removido.
 */
InfoFila* CabecaDeFila::desenfileirar() {
	ElementoDeFila *saiu;
	InfoFila *volta;
	if (vazia()) {
		return 0;
	}
	saiu = primeiro;
	volta = saiu->info;
	primeiro = saiu->proximo;
	if (tamanho == 1) {
		ultimo = FILA_VAZIA;
		primeiro = FILA_VAZIA;
	}
	tamanho--;
	delete saiu;
	return volta;
}

/**
 * Metodo que testa se a fila possui elementos.
 *
 * @return true = caso a Fila esteja vazia.
 */
bool CabecaDeFila::vazia() {
	return tamanho == FILA_VAZIA;
}

/**
 * Método que exclui todos os elementos da fila e suas respectivas informações, representado pela classe InfoLista.
 */
void CabecaDeFila::limpar() {
	ElementoDeFila* i = primeiro;	//morre quando sair desse metodo
	ElementoDeFila* paraDeletar;	//morre quando sair desse metodo
	while (i) {				//percorre a lista e apaga os elementos do infolista
		delete i->info;				//chama o destrutor de infolista
		paraDeletar = i;
		i = i->proximo;
		delete paraDeletar;
	}
	tamanho = FILA_VAZIA;
	primeiro = FILA_VAZIA;
}
