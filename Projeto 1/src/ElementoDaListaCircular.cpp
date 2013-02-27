/*
 * ElementoDaListaCircular.cpp
 *
 *  Created on: 08/11/2012
 *      Author: tiago
 */

#include "ElementoDaListaCircular.h"

namespace Projeto1 {

ElementoDeListaCircular::ElementoDeListaCircular() {
	// TODO Auto-generated constructor stub
	caixa = 0;
}

/**
 *Construtor que configura um objeto da classe ElementoDeLista.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
ElementoDeListaCircular::ElementoDeListaCircular(Caixa *c) {
	// TODO Auto-generated constructor stub
	caixa = c;
}

/**
 *Destrutoer que exclui um objeto da classe ElementoDeLista.
 */
ElementoDeListaCircular::~ElementoDeListaCircular() {
	// TODO Auto-generated destructor stub

}


} /* namespace Projeto1 */
