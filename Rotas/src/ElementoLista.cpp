/*
 * ElementoLista.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#include "ElementoLista.h"

ElementoLista::ElementoLista() {
	// TODO Auto-generated constructor stub

}

ElementoLista::ElementoLista(InfoLista *inf) {
	proximo = 0;
	anterior = 0;
	info = inf;
}

ElementoLista::~ElementoLista() {
	// TODO Auto-generated destructor stub
}

