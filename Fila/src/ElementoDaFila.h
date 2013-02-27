/*
 * ElementoDaFila.h
 *
 *  Created on: Sep 20, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#ifndef ELEMENTODAFILA_H_
#define ELEMENTODAFILA_H_

#define MAXNOME 40 //constante que determina o tamanho máximo da string.
namespace Fila {

class ElementoDaFila {
public:
	ElementoDaFila();
	virtual ~ElementoDaFila();
	void receberNome(const char * dado);
	char nome[MAXNOME];
};

} /* namespace Fila */
#endif /* ELEMENTODAFILA_H_ */
