/*
 * TorresDeHanoi.h
 *
 *  Created on: Oct 17, 2012
 *      Author: will
 */

#ifndef TORRESDEHANOI_H_
#define TORRESDEHANOI_H_

#define ID_FONTE 1
#define ID_MEIO 2
#define ID_DESTINO 3


#include "Pilha.h"

namespace PilhaEncadeada {

class TorresDeHanoi {
public:
	TorresDeHanoi();
	TorresDeHanoi(int total);
	virtual ~TorresDeHanoi();
	void iniciarJogadas();
private:
	int totalDiscos;
	int posMenor;
	Disco *menor;
	Pilha fonte;
	Pilha meio;
	Pilha destino;
	void resolverPar();
	void resolverImpar();
	void moverMenor();
	void fazerJogadaSeguinte();
};

} /* namespace Fila */
#endif /* TORRESDEHANOI_H_ */
