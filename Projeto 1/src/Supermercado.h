/*
 * Supermercado.h
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#ifndef SUPERMERCADO_H_
#define SUPERMERCADO_H_
#define MAX_CAIXA 10
#define FATOR_IRRITACAO 3
#include "ListaCircular.h"
namespace Projeto1 {

class Supermercado {
public:
	Supermercado();
	Supermercado(ListaCircular *caixas, int tempClientes, int tempoTotal);
	virtual ~Supermercado();
	/** Lista de caixas. */
	ListaCircular *caixas;
	/** Nome do supermercado. */
	char *nomeSupermercado;
	/** Tempo medio de chegada de clientes. */
	int tempoMedioClientes;
	/** Tempo de Simulação. */
	int tempoSimulacao;
	/** Número de clientes que desistiram. */
	int desistencias;
	/** Faturamento bruto do supermercado. */
	int faturamentoBruto;
	/** Prejuiso gerado pelas desistências. */
	int valorDesistencias;
	/** Limite para chamar um caixa especial. */
	int limiteCaixaEspecial;
	/** Informação se um caixa especial já foi chamado. */
	bool caixaEspecialchamado;
	void iniciarSimulacao();
	Cliente* gerarCliente(int horario);
	int posicionarCliente(Cliente* novo);
	int atenderClientes(int horario);
	void chamarCaixaEspecial();
	void configurarSimulacao(char *nome, int tempoSimulacao,int tempoMedioChegada, int limiteCaixaEspecial, ListaCircular *caixas);
	void apresentarResultados();
};

} /* namespace Fila */
#endif /* SUPERMERCADO_H_ */
