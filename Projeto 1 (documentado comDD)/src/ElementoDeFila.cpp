/*
 * ElementoDeLista.cpp
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */

#include "ElementoDeFila.h"

namespace Projeto1 {

/**
 *Método que constrói um objeto que representa uma elemento de uma fila encadeado.
 */
ElementoDeFila::ElementoDeFila() {
	// TODO Auto-generated constructor stub
	cliente = 0;
	proximo = 0;
}

/**
 *Método que constrói um objeto que representa uma elemento de uma fila encadeado.
 *@param inf : ponteiro para um objeto da classe Cliente.
 */
ElementoDeFila::ElementoDeFila(Cliente *inf) {
	// TODO Auto-generated constructor stub
	cliente = inf;
	proximo = 0;
}

/**
 * Destrutor que exclui um elemento da Fila.
 */
ElementoDeFila::~ElementoDeFila() {
	// TODO Auto-generated destructor stub
}




}
