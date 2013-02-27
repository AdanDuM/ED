/*
 * Dados.h
 *
 *  Created on: Feb 12, 2013
 *      Author: will
 */

#ifndef DADOS_H_
#define DADOS_H_

#include<iostream>
#include<cstring>
using namespace std;
namespace Ordenacao {


class Dados {
public:
	Dados();
	virtual ~Dados();
	string chavePrimaria;
	char* primaria;
	int igual();
	int maior();
	void mostrar();
};

} /* namespace Ordenacao */
#endif /* DADOS_H_ */
