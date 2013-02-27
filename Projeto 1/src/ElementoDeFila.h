/*
 * ElementoDeLista.h
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef ELEMENTODELISTA_H_
#define ELEMENTODELISTA_H_

#include "Cliente.h"
namespace Projeto1 {

/**
 * Classe que representa um objeto pertencente a uma lista genérica.
 */
class ElementoDeFila {
public:
	ElementoDeFila();
	ElementoDeFila(Cliente *info);
	virtual ~ElementoDeFila();
	/** Proximo cliente da fila do caixa */
	ElementoDeFila *proximo;
	/** Ponteiro para o cliente referente a este elemento da fila. */
	Cliente *cliente;
};
}
#endif /* ELEMENTODELISTA_H_ */
