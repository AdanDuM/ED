/*
 * TorresDeHanoi.cpp
 *
 *  Created on: Oct 17, 2012
 *      Author: will
 */

#include "TorresDeHanoi.h"
#include "iostream"

namespace PilhaEncadeada {

TorresDeHanoi::TorresDeHanoi() {
	// TODO Auto-generated constructor stub
	totalDiscos = 0;
}
TorresDeHanoi::TorresDeHanoi(int total) {
	// TODO Auto-generated constructor stub
	fonte.id = ID_FONTE;
	meio.id = ID_MEIO;
	destino.id = ID_DESTINO;
	totalDiscos = total;
	posMenor = 1;
	std::cout << "Criando " << total << " Discos(ID das torres F=1, M=2, D=3) "
			<< std::endl;
	for (int tamanho = totalDiscos; tamanho > 0; tamanho--) {
		fonte.empilha(new Disco(ID_FONTE, tamanho));
	}
}
TorresDeHanoi::~TorresDeHanoi() {
	// TODO Auto-generated destructor stub
}

void TorresDeHanoi::fazerJogadaSeguinte() {
	if (destino.tamanho < totalDiscos) {
		switch (posMenor) {
		case 1:
			if ((destino.tamanho != 0)
					&& (meio.diametroTopo > destino.diametroTopo)) {
				meio.empilha(destino.desempilha());
			} else {
				if (fonte.tamanho == 0) {
					meio.empilha(destino.desempilha());
					break;
				}
				destino.empilha(meio.desempilha());
			}
			break;
		case 2:
			if ((destino.tamanho != 0)
					&& (fonte.diametroTopo > destino.diametroTopo)) {
				fonte.empilha(destino.desempilha());
			} else {
				if (fonte.tamanho == 0) {

					fonte.empilha(destino.desempilha());
					break;
				}
				destino.empilha(fonte.desempilha());
			}
			break;
		case 3:
			if ((meio.tamanho != 0)
					&& (fonte.diametroTopo > meio.diametroTopo)) {
				fonte.empilha(meio.desempilha());
			} else {
				if (fonte.tamanho == 0) {

					fonte.empilha(meio.desempilha());
					break;
				}
				meio.empilha(fonte.desempilha());
			}
			break;
		}
	}
}
void TorresDeHanoi::moverMenor() {
	if (fonte.contem(menor)) {
		switch (menor->origem) {
		case 2:
			destino.empilha(fonte.desempilha());
			posMenor = ID_DESTINO;
			break;
		case 3:
			meio.empilha(fonte.desempilha());
			posMenor = ID_MEIO;
			break;
		}
	} else if (meio.contem(menor)) {
		switch (menor->origem) {
		case 1:
			destino.empilha(meio.desempilha());
			posMenor = ID_DESTINO;
			break;
		case 3:
			fonte.empilha(meio.desempilha());
			posMenor = ID_FONTE;
			break;
		}
	} else if (destino.contem(menor)) {
		switch (menor->origem) {
		case 1:
			meio.empilha(destino.desempilha());
			posMenor = ID_MEIO;
			break;
		case 2:
			fonte.empilha(destino.desempilha());
			posMenor = ID_FONTE;
			break;
		}
	}
}
void TorresDeHanoi::resolverPar() {

	menor = fonte.desempilha();
	meio.empilha(menor);
	posMenor = ID_MEIO;
	while (destino.tamanho < totalDiscos) {
		fazerJogadaSeguinte();
		moverMenor();
	}
}
void TorresDeHanoi::resolverImpar() {
	menor = fonte.desempilha();
	destino.empilha(menor);
	posMenor = ID_DESTINO;
	while (destino.tamanho < totalDiscos) {
		fazerJogadaSeguinte();
		moverMenor();
	}
}
void TorresDeHanoi::iniciarJogadas() {
	std::cout << "Iniciando Jogadas" << std::endl;
	if ((totalDiscos % 2) == 0) {
		resolverPar();
	} else if ((totalDiscos % 2) == 1) {
		resolverImpar();
	}
}

} /* namespace Fila */
