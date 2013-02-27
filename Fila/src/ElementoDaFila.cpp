/*
 * ElementoDaFila.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#include "ElementoDaFila.h"
#include <string.h>

namespace Fila {
/**
 * Construtor que configura um objeto da classe ElementoDaFila.
 */
ElementoDaFila::ElementoDaFila() {
	// TODO Auto-generated constructor stub
}
/**
 * Destrutor que excui um objeto da classe ElementoDaFila.
 */
ElementoDaFila::~ElementoDaFila() {
	// TODO Auto-generated destructor stub
}
/**
 * Método que inicializa o atributo nome.
 *
 * @param char nome[] = string que contem o nome do elemento.
 */
void ElementoDaFila::receberNome(const char * dado) {
	strcpy(nome, dado);
}

} /* namespace Fila */
