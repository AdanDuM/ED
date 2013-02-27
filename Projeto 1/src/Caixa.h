/*
new Caixa(a[i],1) * Caixa.h
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */

#ifndef CAIXA_H_
#define CAIXA_H_
#include<iostream>
#include<fstream>
#define FILA_VAZIA 0
#define FILA_CHEIA -2
#define ERRO_POSICAO -3


#include "ElementoDeFila.h"
using namespace std;

namespace Projeto1 {
/**
 * Classe que representa um caixa de um supermercado.
 */
class Caixa {
public:
	Caixa(char *nome, int eficiencia, int salario);
	Caixa();
	virtual ~Caixa();

	/**identificador do caixa*/
	char *nomeCaixa;
	/**eficiencia do caixa */
	int eficiencia;
	/**salario do caixa */
	int salario;
	/**numero de clientes atendidos */
	int clientesAtendidos;
	/**tempo medio de espera */
	int tempoMedio;
	/**faturamento total */
	int faturamentoTotal;


	/**FilaDeClientes */
	ElementoDeFila *primeiro;
	/**FilaDeClientes */
	ElementoDeFila *ultimo;
	/**tamanho fila de clientes */
	int tamanhoFila;
	/**soma de todas as mercadorias dos clientes que estão na fila. */
	int totalProdutos;

	int enfileirar(Cliente *dado);
	Cliente* desenfileirar();
	void limpar();
	int receberCliente(Cliente *cliente);
	virtual int fornecaLucro();
	long int atenderCliente(int horaAtual);
	void mostrar();
	void apresentarRelatorio();

private:

	bool vazia();

};

} /* namespace Projeto1 */
#endif /* CAIXA_H_ */
