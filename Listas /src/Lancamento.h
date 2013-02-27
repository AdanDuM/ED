/*
 * Lancamento.h
 *
 *  Created on: 25/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#ifndef LANCAMENTO_H_
#define LANCAMENTO_H_

#define MAXNOME 40
/**
 * Representação de um objeto que será integrado à Lista.
 */
class Lancamento {
public:
	Lancamento();
	Lancamento(const char *dado, int valor);
	virtual ~Lancamento();
	char nome[MAXNOME];
	int valor;
	void mostrarLancamento();
	bool verificarErro(int codigo);
};

#endif /* LANCAMENTO_H_ */
