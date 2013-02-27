/*
 * Fila.h
 *
 *  Created on: Sep 18, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#ifndef FILA_H_
#define FILA_H_
#define MAXFILA 100
#define FILAVAZIA -1
#define FILACHEIA -2

#include<iostream>
#include "ElementoDaFila.h"

using namespace std;

namespace Fila {

class Fila {
public:
	Fila();
	virtual ~Fila();
	int enfileirar(ElementoDaFila dado);
	int desenfileirar();
	void mostrarFila();
	void limpar();
private:
	int ultimo;
	ElementoDaFila fila[MAXFILA];
};


} /* namespace Fila */
#endif /* FILA_H_ */
