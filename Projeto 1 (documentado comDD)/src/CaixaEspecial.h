/*
 * CaixaEspecial.h
 *
 *  Created on: 07/11/2012
 *      Author: tiago
 */

#ifndef CAIXAESPECIAL_H_
#define CAIXAESPECIAL_H_
#include "Caixa.h"
namespace Projeto1 {

/**
 * Classe que representa um caixa em hora extra.
 */
class CaixaEspecial :public Caixa{
public:
	CaixaEspecial(char *nome, int eficiencia, int salario);
	CaixaEspecial();
	virtual ~CaixaEspecial();

	virtual int fornecaLucro();
};

} /* namespace Projeto1 */
#endif /* CAIXAESPECIAL_H_ */
