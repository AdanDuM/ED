/*
 * ListaCircular.cpp
 *
 *  Created on: 08/11/2012
 *      Author: tiago
 */

#include "iostream"
#include "ListaCircular.h"


namespace Projeto1 {
/**
 * Método que constri um objeto que representa uma lista encadeada.
 */
ListaCircular::ListaCircular() {
	// TODO Auto-generated constructor stub
	sentinela = new ElementoDeListaCircular();
	sentinela->proximo = sentinela;
	tamanho = 1;
}

/**
 * Destrutor que exclui uma lista encadeada.
 *
 * Para isso utiliza o método limpar.
 */
ListaCircular::~ListaCircular() {
	// TODO Auto-generated destructor stub

}

/**
 * Método que adiciona no início um objeto da classe ElementoDeLista.
 *
 *  Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na primeira posição da Lista.
 *
 *@param caixa : ponteiro para o caixa onde o cliente vai ser inserido.
 *
 *@return LISRA_CHEIA = constante que representa a falta de espaço na Lista.
 *@return 1 = inteiro que informa a posição onde o dado foi inserido.
 */
int ListaCircular::adiciona(Caixa *caixa) {

	ElementoDeListaCircular *novo;
	novo = new ElementoDeListaCircular();
	if (novo == 0) {
		return LISTA_CHEIA;
	} else {
		ElementoDeListaCircular *aux; //proximo do sentinela antes de add
		aux = sentinela->proximo;
		sentinela->proximo = novo;
		novo->proximo = aux;
		novo->caixa = caixa;

		tamanho++;
	}
	return 1;
}

/**
 *Método que imprime a Lista no console.
 */
void ListaCircular::mostrarLista() {
	ElementoDeListaCircular* atual = sentinela->proximo;

	if (vazia()) {
		std::cout << "Lista vazia." << std::endl;
	}
	while (atual->caixa) {
		atual->caixa->mostrar();
		atual = atual->proximo;
	}
}

/**
 * Método que informa se a Lista está vazia.
 */
bool ListaCircular::vazia() {
	return tamanho == LISTA_VAZIA;
}



} /* namespace Projeto1 */
