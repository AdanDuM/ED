/*
 * HeapSort.h
 *
 *  Created on: Dec 20, 2012
 *      Author: will
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_


namespace Ordenacao {
/**
 * Classe que representa um objeto que faz ordenação de um array com o metodo HeapSort.
 *
 * O algoritmo heapsort é um algoritmo de ordenação generalista, e faz parte da família
 *  de algoritmos de ordenação por seleção.
 *  O heapsort utiliza uma estrutura de dados chamada heap, para ordenar os elementos a
 *  medida que os insere na estrutura. Assim, ao final das inserções, os elementos podem
 *   ser sucessivamente removidos da raiz da heap, na ordem desejada, lembrando-se sempre
 *   de manter a propriedade de max-heap.
A heap pode ser representada como uma árvore (uma árvore binária com propriedades especiais)
 ou como um vetor. Para uma ordenação crescente, deve ser construído uma heap mínima
 (o menor elemento fica na raiz). Para uma ordenação decrescente, deve ser construído uma
 heap máxima (o maior elemento fica na raiz).


 REF: http://pt.wikipedia.org/wiki/Heapsort
 */
class HeapSort {
public:
	HeapSort();
	virtual ~HeapSort();
	void ordenar(int *numeros, int tamanho);
	void montarHeap(int *numeros,int tamanho);
	void ajustarHeap(int *numeros,int index,int tamanho);
	void swapArray(int *numeros,int a,int b);
};

} /* namespace Ordenacao */
#endif /* HEAPSORT_H_ */
