/*
 * ElementoDeLista.cpp
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */

#include "ElementoDeFila.h"

/**
 *Método que constrói um objeto que representa uma elemento de uma fila encadeado.
 */
ElementoDeFila::ElementoDeFila() {
	// TODO Auto-generated constructor stub
	proximo = 0;
}

/**
 *Método que constrói um objeto que representa uma elemento de uma fila encadeado.
 *@param InfoFila *inf = ponteiro para um objeto da classe InfoFila, este objeto deve conter as informações do elemento da fila que está sendo construido.
 */
ElementoDeFila::ElementoDeFila(InfoFila *inf) {
	// TODO Auto-generated constructor stub
	info = inf;
	proximo = 0;
}

/**
 * Destrutor que exclui um elemento da Fila.
 */
ElementoDeFila::~ElementoDeFila() {
	// TODO Auto-generated destructor stub
}

