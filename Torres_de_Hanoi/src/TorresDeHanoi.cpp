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
	jogadas = 0;
}
TorresDeHanoi::TorresDeHanoi(int total) {
	// TODO Auto-generated constructor stub
	jogadas = 0;
	fonte.id = ID_FONTE;
	meio.id = ID_MEIO;
	destino.id = ID_DESTINO;
	totalDiscos = total;
	std::cout << "Criando " << total << " Discos(ID das torres f=1, m=2, d=3) "
			<< std::endl;
	for (int tamanho = totalDiscos; tamanho > 0; tamanho--) {
		fonte.empilha(new Disco(ID_FONTE, tamanho));
	}
}
TorresDeHanoi::~TorresDeHanoi() {
	// TODO Auto-generated destructor stub
}

void TorresDeHanoi::fazerJogadaSeguinte(int posicaoMenor) {
	if (destino.tamanho < totalDiscos) {
		switch (posicaoMenor) {
		case 1:
			if (meio.topo == 0) {
				meio.empilha(destino.desempilha());
				break;
			} else if (destino.topo == 0) {
				destino.empilha(meio.desempilha());
				break;
			}

			if (meio.topo->tamanho > destino.topo->tamanho) {
				destino.empilha(meio.desempilha());
			} else
				meio.empilha(destino.desempilha());
			break;
		case 2:
			if (fonte.topo == 0) {
				fonte.empilha(destino.desempilha());
				break;
			} else if (destino.topo == 0) {
				destino.empilha(fonte.desempilha());
				break;
			}
			if (fonte.topo->tamanho > destino.topo->tamanho) {
				destino.empilha(fonte.desempilha());
			} else
				fonte.empilha(destino.desempilha());
			break;
		case 3:
			if (fonte.topo == 0) {
				fonte.empilha(meio.desempilha());
				break;
			} else if (meio.topo == 0) {
				meio.empilha(fonte.desempilha());
				break;
			}
			if (fonte.topo->tamanho > meio.topo->tamanho) {
				meio.empilha(fonte.desempilha());
			} else
				fonte.empilha(meio.desempilha());
			break;
		}
	}
}

void TorresDeHanoi::resolverPar() {
	Disco *menor;
	int posMenor;
	menor = fonte.desempilha();
	meio.empilha(menor);
	fazerJogadaSeguinte(ID_MEIO);
	while (destino.tamanho < totalDiscos) {
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
		fazerJogadaSeguinte(posMenor);
	}
}
void TorresDeHanoi::resolverImpar() {
	Disco *menor;
	jogadas = 1;
	int posMenor;
	while (destino.tamanho < totalDiscos) {
		if (jogadas == 1) {
			menor = fonte.desempilha();
			destino.empilha(menor);
			posMenor = ID_DESTINO;
			jogadas++;
		} else {
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
		fazerJogadaSeguinte(posMenor);
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
