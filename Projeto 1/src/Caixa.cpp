/*
 * Caixa.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */
#include<iostream>
#include<fstream>
#include "Caixa.h"
using namespace std;
namespace Projeto1 {

/**
 * Construtor que gera um caixa de supermercado.
 *
 * @param nome : nome do operador do caixa.
 * @param eficienc : eficiencia do operador do caixa.
 * @param salari : salario do operador do caixa.
 */
Caixa::Caixa(char *nome, int eficienc, int salari){
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

Caixa::Caixa(){
	nomeCaixa = 0;
	eficiencia = 0;
	salario = 0;
	totalProdutos = 0;
	clientesAtendidos = 0;
	faturamentoTotal = 0;
	tempoMedio = 0;
	tamanhoFila = 0;
	primeiro = 0;
	ultimo = 0;
}

/**
 * Destrutor que exclui um objeto da classe caixa.
 */
Caixa::~Caixa() {
	// TODO Auto-generated destructor stub
	limpar();
}

/**
 * Método que adiciona um elemento da fila.
 *
 * Primeiramente teste se ainda é possivel adicionar um elemento à fila. Caso isso não seja verdadeiro ele retorna uma constante FILA_CHEIA.
 *
 * @param dado = ponteiro para um objeto da classe Cliente.
 * @return FILA_CHEIA = constante que representa a falta de espaço na Fila.
 * @return tamanho = inteiro que informa a posição onde o dado foi inserido.
 */
int Caixa::enfileirar(Cliente *dado) {

	ElementoDeFila *novo = new ElementoDeFila(dado);
	if (novo == 0) {
		return FILA_CHEIA;
	}
	if (vazia()) {
		primeiro = novo;
	} else {
		ultimo->proximo = novo;
	}
	novo->proximo = 0;
	ultimo = novo;
	tamanhoFila++;
	return 0;
}
/**
 * Método que  imprime as informações do caixa.
 */
void Caixa::mostrar(){
	cout<<nomeCaixa<<" "<<eficiencia <<" "<<salario <<endl;
}
/**
 * Metodo que testa se a fila possui elementos.
 *
 * @return true = caso a Fila esteja vazia.
 */
bool Caixa::vazia() {
	return tamanhoFila == FILA_VAZIA;
}

/**
 *Método que remove um elemento da Fila.
 *Primeiramente testa se a Fila possui elementos. Caso possua ele remove o primeiro elemento, ou seja o primeiro que foi inserido.
 *
 *@return 0(NULL) = caso a Fila não possua elementos.
 *@return volta = ponteiro para um objeto da classe cliente.
 */
Cliente* Caixa::desenfileirar() {
	ElementoDeFila *saiu;
	Cliente *volta;
	if (vazia()) {
		return 0;
	}
	saiu = primeiro;
	volta = saiu->cliente;
	primeiro = saiu->proximo;
	if (tamanhoFila == 1) {
		ultimo = FILA_VAZIA;
		primeiro = FILA_VAZIA;
	}
	tamanhoFila--;
	delete saiu;
	return volta;
}

/**
 * Método que exclui todos os elementos da fila e suas respectivas informações, representado pela classe Cliente.
 */
void Caixa::limpar() {
	ElementoDeFila* i = primeiro;	//morre quando sair desse metodo
	ElementoDeFila* paraDeletar;	//morre quando sair desse metodo
	while (i) {						//percorre a lista e apaga os elementos do infolista
		delete i->cliente;			//chama o destrutor de infolista
		paraDeletar = i;
		i = i->proximo;
		delete paraDeletar;
	}
	tamanhoFila = FILA_VAZIA;
	primeiro = FILA_VAZIA;
}

/**
 * Método que calcula o tempo de saida de um cliente de acordo com seus parâmetros e com a eficoência do caixa.
 *
 * @param cliente  : cliente do supermercado.
 */
int Caixa::receberCliente(Cliente *cliente){
	int tempoDeProcessamento = 0;
	switch(eficiencia){
	case 1: //eficiente
		if(cliente->cheque)
			tempoDeProcessamento = 10;
		tempoDeProcessamento += (cliente->totalCompras * 1);
		break;
	case 2: //medio
		if(cliente->cheque)
			tempoDeProcessamento = 25;
		tempoDeProcessamento += (cliente->totalCompras * 2);
		break;
	case 3: //ruim
		if(cliente->cheque)
			tempoDeProcessamento = 60;
		tempoDeProcessamento += (cliente->totalCompras * 4);
		break;
	}
	totalProdutos += cliente->totalCompras;
	if(ultimo){
		cliente->saida = ultimo->cliente->saida + tempoDeProcessamento;
	}else{
		cliente->saida = cliente->chegada + tempoDeProcessamento;
	}
	return enfileirar(cliente);


}

/**
 * Método que fornece o lucro gerado pelo caixa corrente.
 *
 * @return lucro : ineiro.
 */
int Caixa::fornecaLucro(){
	switch(eficiencia){
	case 1: //eficiente
		return (faturamentoTotal - salario);
	case 2: //medio
		return (faturamentoTotal - salario);
	case 3: //ruim
		return (faturamentoTotal - salario);
	}
	return 0;
}

/**
 * Método que verificar se o proximo cliente da fila deve ser atendimento.
 *
 *@param horaAtual : instante em que se encontra o programa.
 *@return Cliente : cliente que foi atendido.
 */
long int Caixa::atenderCliente(int horaAtual){
	if(tamanhoFila){

		if(primeiro->cliente->saida == horaAtual){

			totalProdutos -= primeiro->cliente->totalCompras;

			faturamentoTotal += primeiro->cliente->valorCompras;
			clientesAtendidos ++;
			tempoMedio += (primeiro->cliente->saida - primeiro->cliente->chegada);

			delete desenfileirar();
		}
	}
	return faturamentoTotal;
}
/**
 * Método que gera o relatório final da execução.
 */
void Caixa::apresentarRelatorio(){
/*
	Nome caixa:
	Eficiência:
	Tempo médio de permanência de um cliente na fila:
	Número de clientes atendidos:
	Faturamento real:
	Faturamento medio por clinte:
	Lucro total do caixa:
 */
	ofstream resultados;
	resultados.open("resultados/Resultados",ofstream::app);
	resultados.eof();
	string line;
	resultados<< " Nome caixa: " << nomeCaixa <<endl;
	resultados<< " Eficiência: " << eficiencia <<endl;
	resultados<< " Salário: " << salario <<endl;
	if(clientesAtendidos){
		resultados<< " Tempo médio de permanência de um cliente na fila: " << (tempoMedio / clientesAtendidos ) << " segundos."<<endl;
		resultados<< " Número de clientes atendidos: " << clientesAtendidos <<endl;
		resultados<< " Faturamento real: " << faturamentoTotal <<endl;
		resultados<< " Faturamento medio por clinte: " << (faturamentoTotal / clientesAtendidos) <<endl;
		resultados<< " Lucro total do caixa: " << fornecaLucro() <<"\n" <<endl;
		resultados.close();
	}else{
		resultados<< " Nenhum cliente foi atendido por este caixa " <<"\n" <<endl;
		resultados.close();
	}
}



} /* namespace Fila */


