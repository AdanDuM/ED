/*
 * ElementoFila.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#include "ElementoFila.h"
#include "iostream"
using namespace std;

/**
 * Construtor que cria um objeto da classe ElementoFila.
 */
ElementoFila::ElementoFila() {
	// TODO Auto-generated constructor stub

}

/**
 * Construtor que cria um objeto da classe ElementoFila.
 *
 * @param numero da linha do ônibus.
 * @param empresa do ônibus.
 * @param lista de cidades que pertencem a rota. *
 */
ElementoFila::ElementoFila(int numeroLinhaOnib, char *empresaOnib, ListaDupla *list) {
	numeroLinhaOnibus = numeroLinhaOnib;
	empresaOnibus = empresaOnib;
	lista = list;
}

/**
 * Destrutor da Fila.
 *
 * Exclui toda a fila.
 */
ElementoFila::~ElementoFila() {
	// TODO Auto-generated destructor stub
}

/**
 * Modo que imprime no console a fila.
 */
void ElementoFila::mostrar(){
	cout<<"Rota: "<< numeroLinhaOnibus << " empresa: "<< empresaOnibus <<endl;
	lista->mostrar();
}
