/*
 * HeapSort.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: will
 */


#include<iostream>

#include "HeapSort.h"
using namespace std;
namespace Ordenacao {
/**
 * Construtor  da classe HeapSort
 */
HeapSort::HeapSort() {
	// TODO Auto-generated constructor stub

}
/**
 * Destrutor  da classe HeapSort
 */
HeapSort::~HeapSort() {
	// TODO Auto-generated destructor stub
}
/**
 * Método no qual esta implementado o algoritmo do HeapSort, se encarrega de fazer a ordenação.
 *
 *@param *numeros = ponteiro para um array de int no qual ira ser montada a Heap.
 *@param tamanho = inteiro contendo a quantidade de elementos do array.
 */
void HeapSort::ordenar(int *numeros, int tamanho) {

	montarHeap(numeros, tamanho);// faz heap
	for (int i = tamanho-1; i >= 0; i--) {
		swapArray(numeros,0,i);
		ajustarHeap(numeros, 0, i); //reamontoa
	}
}
/**
 * Método que monta uma Heap no array dado.
 *
 *@param *numeros = ponteiro para um array de int no qual ira ser montada a Heap.
 *@param tamanho = inteiro contendo a quantidade de elementos do array.
 */
void HeapSort::montarHeap(int *numeros, int tamanho) {

	for(int i=(tamanho/2)-1;i>=0;i--){
		ajustarHeap(numeros,i,tamanho);
	}

}
/**
 * Método que reajusta uma heap que foi desarrumada.
 *
 *@param *numeros = ponteiro para um array de int no qual ira ser montada a Heap.
 *@param i = index do elemento a ser usado como nodo pai, para ajustar a heap.
 *@param tamanho = inteiro contendo a quantidade de elementos do array.
 */
void HeapSort::ajustarHeap(int *numeros, int i, int tamanho ) {
int esquerda =(2*i)+1;
int direita = (2*i)+2;
int maior = i;
if(esquerda < tamanho && (numeros[esquerda]>numeros[maior]) ){
	maior = esquerda;
}
if(direita < tamanho && (numeros[direita]>numeros[maior])){
	maior = direita;
}
if(maior!= i){
	swapArray(numeros,i,maior);
	ajustarHeap(numeros,maior,tamanho);
}
}
/**
 * Método que faz o swap(troca) entre duas posições de um array.
 *
 *@param *numeros = ponteiro para um array de int no qual ira ser efetuado o swap.
 *@param a = inteiro contendo uma das posições a ser trocada.
 *@param b = inteiro contendo uma das posições a ser trocada.
 */

void HeapSort::swapArray(int *numeros, int a, int b){
	int temp = numeros[a];
	numeros[a] = numeros[b];
	numeros[b] = temp;
}
} /* namespace Ordenacao */
