/*
 * Supermercado.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#include "Supermercado.h"
#include "CaixaEspecial.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string.h>
using namespace std;

namespace Projeto1 {

/**
 * Costrutor que gera um objeto da classe supermercado.
 *
 * @param c : Pponteiro para Lista Circular de caixas do supermercado.
 * @param tempClientes : Tempo médio de chegada de clientes.
 * @param tempoTotal : Tempo total da simulação.
 */
Supermercado::Supermercado(ListaCircular *c, int tempClientes, int tempoTotal) {
	caixas = c;
	tempoSimulacao = tempoTotal;
	tempoMedioClientes = tempClientes;
	desistencias = 0;
	limiteCaixaEspecial = 5;
	valorDesistencias = 0;
	caixaEspecialchamado = false;
}

Supermercado::Supermercado() {
	// TODO Auto-generated constructor stub
	caixas = 0;
	tempoSimulacao = 0;
	desistencias = 0;
	limiteCaixaEspecial = 5;
	valorDesistencias = 0;
	caixaEspecialchamado = false;
}

Supermercado::~Supermercado() {
	// TODO Auto-generated destructor stub
}

/**
 * Método que configura a simulação.
 *
 *@param nome : nome do supermercado.
 *@param tempoS : tempo de simulação.
 *@param tempoMedioC : tempo médio de chegada de clientes.
 *@param c : lista de caixas;
 */
void Supermercado::configurarSimulacao(char *nome, int tempoS, int tempoMedioC,
		ListaCircular *c) {
	nomeSupermercado = nome;
	tempoSimulacao = tempoS;
	tempoMedioClientes = tempoMedioC;
	caixas = c;
}

/**
 * Método que executa a simulação.
 *
 * Para isso percorre segundo a segundo executando os passos da simulação.
 */
void Supermercado::iniciarSimulacao() {
	for (int segundos = 1; segundos <= tempoSimulacao; segundos++) {
		atenderClientes(segundos);
		if (segundos % tempoMedioClientes == 0) {
			int valorDesistencia = posicionarCliente(gerarCliente(segundos)); //é percorrida a lista de caixas e inserido em alguma fila o cliente, ou não
			if (valorDesistencia) {
				valorDesistencias += valorDesistencia;
				desistencias++;
			}
		}
		chamarCaixaEspecial();
	}

}

/**
 * Método que gera um cliente do supremercado, decidindo o tipo do mesmo.
 *
 * Existem dois tipos de clientes, os que buscam a fila com menos clientes e os que buscam uma fila com menor numero de produtos dos outros clientes.
 */
Cliente* Supermercado::gerarCliente(int horario) {
	Cliente *novo = new Cliente(horario);
	if ((rand() % 100) < 50) {
		novo->tipo = BuscaMenorFila;
		return novo;
	} else
		novo->tipo = BuscaFilaComMenosProdutos;
	return novo;
}

/**
 * Método que posiciona um cliente na fila de um caixa, de acordo com seu tipo.
 *
 *@param novo : Cliente a ser posicionado.
 */
int Supermercado::posicionarCliente(Cliente* novo) {

	bool desistir = true;
	ElementoDeListaCircular *atual, *menor;
	atual = caixas->sentinela->proximo;
	menor = atual;
	switch (novo->tipo) {
	case BuscaFilaComMenosProdutos:
		while (atual != caixas->sentinela) {
			if (atual->caixa->tamanhoFila >= MAX_CAIXA) {
				desistir = desistir && true;
				atual = atual->proximo;
				continue;
			} else if (atual->caixa->totalProdutos
					< menor->caixa->totalProdutos) {
				menor = atual;
			}
			desistir = desistir && false;
			atual = atual->proximo;
		}
		break;
	case BuscaMenorFila:
		while (atual != caixas->sentinela) {
			if (atual->caixa->tamanhoFila >= 10) {
				desistir = desistir && true;
				atual = atual->proximo;
				continue;
			} else if (atual->caixa->tamanhoFila < menor->caixa->tamanhoFila) {
				menor = atual;

			}
			desistir = desistir && false;
			atual = atual->proximo;
		}
		break;
	}
	if (desistir) {
		return novo->valorCompras * FATOR_IRRITACAO; //preju

	}

	return menor->caixa->receberCliente(novo);
}

/**
 * Método que atended um cliente.
 *
 * Para isso ele percorre todos os caixas e verifica se o primeiro cliente da fila deve ser atendido, ou seja, se o tempo de saida desse cliente é igual ao tempo atual de execução.
 *
 *@param horario : hora atual de execução.
 */
void Supermercado::atenderClientes(int horario) {

	ElementoDeListaCircular *atual = caixas->sentinela->proximo;
	while (atual->caixa) {
		atual->caixa->atenderCliente(horario);
		atual = atual->proximo;
	}
}

/**
 *Método que chama (constrói) um caixa do tipo caixa expecial.
 */
void Supermercado::chamarCaixaEspecial() {
	if (!caixaEspecialchamado) {
		ElementoDeListaCircular *atual = caixas->sentinela->proximo;
		bool chamarCaixa = (atual->caixa->tamanhoFila >= limiteCaixaEspecial);
		while (atual != caixas->sentinela) {
			chamarCaixa = chamarCaixa
					&& (atual->caixa->tamanhoFila >= limiteCaixaEspecial);
			atual = atual->proximo;

		}
		if (chamarCaixa) {
			int size1 = strlen((char *) "Caixa_Especial");
			char *nome = new char[size1]; //alocação na heap
			strcpy(nome, (char *) "Caixa_Especial");

			caixas->adiciona(new CaixaEspecial(nome, 3, 500));
			caixaEspecialchamado = true;
		}
	}

}

/**
 *Método que gera os resultados finais da execução.
 */
void Supermercado::apresentarResultados() {
	/*
	 Nome Supermercado:
	 Tempo total de simulação:
	 Faturamento bruto:
	 Faturamento liquido:
	 Número de desistências:
	 Prejuizo gerado pelas desistência:
	 Tempo médio de permanência de um cliente no supermercado:
	 Faturamento médio dos caixas:


	 Nome caixa:
	 Eficiência:
	 Tempo médio de permanência de um cliente na fila:
	 Número de clientes atendidos:
	 Faturamento real:
	 Faturamento medio por clinte:
	 Lucro total do caixa:
	 */

	cout << " Nome Supermercado: " << nomeSupermercado << endl;
	cout << " Tempo total de simulação: " << tempoSimulacao << " segundos"
			<< endl;
	ElementoDeListaCircular *atual = caixas->sentinela->proximo;
	atual = caixas->sentinela->proximo;

	int totalClientesAtendidos = 0;
	int faturamentoMedioCaixas = 0;
	int fatBruto = 0;
	int fatLiquido = 0;

	while (atual->caixa) {
		totalClientesAtendidos += atual->caixa->clientesAtendidos;
		faturamentoMedioCaixas += atual->caixa->fornecaLucro();
		fatBruto += atual->caixa->faturamentoTotal;
		fatLiquido += atual->caixa->fornecaLucro();
		atual = atual->proximo;
	}

	cout << " Faturamento bruto: " << fatBruto << endl;
	cout << " Faturamento liquido: " << fatLiquido << endl;
	cout << " Número de desistências: " << desistencias << " clientes" << endl;
	cout << " Prejuizo gerado pelas desistência: " << valorDesistencias << endl;
	if (totalClientesAtendidos) {
		cout << " Tempo médio de permanência de um cliente no supermercado: "
				<< (tempoSimulacao / totalClientesAtendidos) << " segundos"
				<< endl;
		cout << " Faturamento médio dos caixas: "
				<< (faturamentoMedioCaixas / (caixas->tamanho - 1)) << "\n"
				<< endl; //-1 por causa do sentinela
		atual = caixas->sentinela->proximo;
	}
	while (atual->caixa) {
		atual->caixa->apresentarRelatorio();
		atual = atual->proximo;
	}
}
} /* namespace Fila */
