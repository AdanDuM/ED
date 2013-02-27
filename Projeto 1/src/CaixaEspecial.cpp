/*
 * CaixaEspecial.cpp
 *
 *  Created on: 07/11/2012
 *      Author: tiago
 */

#include "CaixaEspecial.h"

namespace Projeto1 {
/**
 * Construtor que gera um caixa especial de supermercado.
 *
 *@param nome : nome do operador do caixa.
 *@param eficienc : eficiencia do operador do caixa.
 *@param salari : salario do operador do caixa.
 */
CaixaEspecial::CaixaEspecial(char *nome, int eficienc, int salari){
	nomeCaixa = nome;
	eficiencia = eficienc;
	salario = salari;
	totalProdutos = 0;
	clientesAtendidos = 0;
	faturamentoTotal = 0;
	tempoMedio = 0;
	tamanhoFila = 0;
	primeiro = 0;
	ultimo = 0;
}

CaixaEspecial::CaixaEspecial() {
	// TODO Auto-generated constructor stub

}

CaixaEspecial::~CaixaEspecial() {
	// TODO Auto-generated destructor stub
}
/**
 * Método que fornece o lucro gerado pelo caixa durante a simulação.
 *
 * Para tal fornecimento ele subtrai seu sálario, que é dobrado pois ele está em hora extra, de seu faturamento total.
 *
 * @return lucro gerado pelo caixa.
 */
int CaixaEspecial::fornecaLucro(){
	switch(eficiencia){
		case 1: //eficiente
			return (faturamentoTotal - (salario*2));
		case 2: //medio
			return (faturamentoTotal - (salario*2));
		case 3: //ruim
			return (faturamentoTotal - (salario*2));
		}
		return 0;
}




} /* namespace Projeto1 */
