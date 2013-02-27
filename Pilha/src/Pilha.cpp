/*
 * Pilha.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#include "Pilha.h"

namespace Pilha {
/**
 * Construtor que configura um objeto da classe Pilha
 */
Pilha::Pilha() {
// TODO Auto-generated constructor stub
topo = PILHAVAZIA;
}
/**
 * Destrutor que exclui um objeto da classe Pilha
 */
Pilha::~Pilha(){
}
/**
 *Método que recebe um inteiro positivo e coloca-o na última posição da pilha.
 *
 *@param dado = número inteiro positivo.
 *
 *@return PILHACHEIA caso a pilha já contenha o numero máximo de elementos, determinado pela constante MAXPILHA.
 *@return 0(zero) caso o dado recebido tenha sido empilhado corretamente.
 */
int Pilha::empilhar(int dado) {
	if (topo == MAXPILHA - 1)
		return PILHACHEIA;
	topo++;
	pilha[topo] = dado;
	return 0;
}
/**
 * Método que retorna o último inteiro posicionado na pilha.
 *
 * @return Uma constante "PILHAVAZIA" (-1), caso não existam dados na pilha.
 * @return O dado contido na última posição da pilha.
 */
int Pilha::desempilhar() {
	if (topo == PILHAVAZIA) {
		return PILHAVAZIA;
	}
	topo--;
	return pilha[topo + 1];
}
/**
 *Método que imprime no console a pila.
 *
 *O primeiro dado a ser impresso será o último que foi empilhaado, sendo o primeiro empilhado o último a ser impresso.
 */
void Pilha::mostrarPilha() {
	if (topo == PILHAVAZIA) {
		std::cout << "Pilha Vazia."<<endl;
	} else {
		for (int i = topo; i > -1; i--) {
			std::cout << pilha[i] << endl;
		}
	}
}
/**
 * Método que limpa o conteúdo da Pilha. Para isso torna seu topo (variável que controla a quantidade de elementos da pilha) igual a "PILHAVAZIA"(-1).
 */
void Pilha::limpar() {
	topo = PILHAVAZIA;
}
} /* namespace Pilha */
