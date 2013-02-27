/*
 * ListaContabil.cpp
 *
 *  Created on: 25/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#include "ListaContabil.h"
#include "string.h"
#include <iostream>

using namespace std;
/**
 * Construtor que configura um objeto da classe ListaContabil.
 */
ListaContabil::ListaContabil() {
	// TODO Auto-generated constructor stub
	ultimo = LISTA_VAZIA;
}
/**
 * Destrutor que exclui um objeto da classe ListaContabil.
 */
ListaContabil::~ListaContabil() {
	// TODO Auto-generated destructor stub
}
/**
 * Método que adiciona um objeto da classe Lancamento. Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na última posição da Lista.
 *
 * @param dado = objeto da classe Lancamento que vai ser adicionado na última posição da fila.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 * @return ultimo = inteiro que determina a posicao do último elemento da Lista.
 */
int ListaContabil::adiciona(Lancamento dado) {
	if (cheia())
		return LISTA_CHEIA;
	ultimo++;
	lista[ultimo] = dado;
	return ultimo;
}
/**
 * Método que adiciona no início um objeto da classe Lancamento.
 *
 *  Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na primeira posição da Lista. Deslocando em uma posição os dados já inseridos na mesma lista.
 *
 *@param dado = objeto da classe Lancamento que vai ser adicionado na primeira posição da fila.
 *
 *@return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 *@return 0 (inteiro zero) = caso o objeto tenha sido adicionado com sucesso.
 */
int ListaContabil::adicionaNoInicio(Lancamento dado) {
	if (cheia()) {
		return LISTA_CHEIA;
	} else {
		ultimo++;
		for (int i = ultimo; i > 0; i--) {
			lista[i] = lista[i - 1];
		}
		lista[0] = dado;
		return 0;
	}
}
/**
 * Método que adiciona um objeto da classe Lancamento.
 *
 * Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na posição recebida pelo parametro, deslocando em uma posição os dados já inseridos após a posição adicionada.
 *
 * @param dado = objeto da classe Lancamento que vai ser adicionado na primeira posição da fila.
 * @param posicao = inteiro que identifica a posição em que o dado vai ser inserido.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 * @return ERRO_POSICAO = caso a posição informada seja inválida, ou seja, caso nao esteja entre o inicio e o final da fila.
 * @return posicao = posição onde o dado foi inserido.
 */
int ListaContabil::adicionaNaPosicao(Lancamento dado, int posicao) {
	if (cheia()) {
		return LISTA_CHEIA;
	}
	if (posicao < 0 || posicao > ultimo + 1) {
		return ERRO_POSICAO;
	}
	ultimo++;
	for (int i = ultimo; i > posicao; i--) {
		lista[i] = lista[i - 1];
	}
	lista[posicao] = dado;
	return posicao;
}
/**
 *Método que adiciona um objeto da classe Lancamento.
 *
 * Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado em ordem intrinsica, deslocando em uma posição os dados já inseridos após a posição adicionada.
 *
 * @param dado = objeto da classe Lancamento que vai ser adicionado na primeira posição da fila.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 * @return 0 (inteiro zero) = caso o objeto tenha sido adicionado com sucesso.
 */
int ListaContabil::adicionaEmOrdem(Lancamento dado) {
	if (cheia()) {
		return LISTA_CHEIA;
	} else {
		int posicao = 0;
		while (posicao <= ultimo && maior(dado, lista[posicao])) {
			posicao++;
		}
		adicionaNaPosicao(dado, posicao);
		return 0;
	}
}
/**
 *Método que retira o último elemento da Lista.
 *
 * Para isso ele utiliza o método retiraDaPosicao, levando a última posição como parametro. Para maiores informações vide retiraDaPosicao().
 *
 * @return Lancamento da última posição da Lista.
 */
Lancamento ListaContabil::retira() {
	return retiraDaPosicao(ultimo);
}
/**
 * Método que retira o primeiro elemento Lista.
 *
 * Para isso ele utiliza o método retiraDaPosicao, levando a primeira posição como parametro. Para maiores informações vide retiraDaPosicao().
 *
 *@return Lancamento da primeira posição da Lista.
 */
Lancamento ListaContabil::retiraDoInicio() {
	return retiraDaPosicao(0);
}
/**
 * Método que retira o elemento da lista que esta armazenado na posição recebida como parametro.
 *
 * Prara isso ele testa se a posicao recebida por parametro é válida, isto é, se existe algum objeto armazenado na mesma.
 *
 * @param posicao = inteiro que determina a localização do dado a ser retirado.
 *
 * @return Caso não seja possível retirar:\n
 *    Lancamento que possui uma string nula e um inteiro sinalizando o erro. Esse inteiro pode ser:\n
 *         		-> LISTA_VASIA = caso a lista não possua nenhum elemento.\n
 *        		-> ERRO_POSICAO = caso a posição informada seja inválida, ou seja, caso nao esteja entre o inicio e o final da fila.
 *@return Caso seja possível retirar:\n
 *	 Objeto da classe Lancamento que foi retirado.
 *
 */
Lancamento ListaContabil::retiraDaPosicao(int posicao) {
	if (vazia()) {
		return Lancamento("", LISTA_VAZIA);
	} else if (posicao < 0 || posicao > ultimo) {
		return Lancamento("", ERRO_POSICAO);
	} else {
		Lancamento retirado = lista[posicao];
		for (int i = posicao; i < ultimo; i++) {
			lista[i] = lista[i + 1];
		}
		ultimo--;
		return retirado;
	}
}
/**
 * Método que retira um objeto específico da classe Lancamento.
 *
 *  Para isso ele utiliza o método retiraDaPosicao, levando a posição do dado recebido como parametro. Para maiores informações vide retiraDaPosicao().
 *
 * @param dado = objeto da classe Lancamento que vai ser retirado da fila.
 *
 * @return objeto da classe Lancamento.
 */
Lancamento ListaContabil::retiraEspecifico(Lancamento dado) {
	int pos = posicao(dado);
	if (pos < 0) {
		return Lancamento("", ERRO_POSICAO);
	}else if (vazia()) {
		return Lancamento("", LISTA_VAZIA);
	}else {
		return retiraDaPosicao(pos);
	}
}
/**
 * Método que identifica a posição de um objeto da classe Lancamento recebido por parâmetro.
 *
 * @param objeto da classe lancamento.
 *
 * @return ERRO_POSICAO caso o objeto em questão nao esteja na Lista.
 * @return posicao = posicao do objeto na Lista.
 */
int ListaContabil::posicao(Lancamento dado) {
	int posicao = 0;
	while (posicao <= ultimo && !(igual(dado, lista[posicao]))) {
		posicao++;
	}
	if (posicao > ultimo) {
		return ERRO_POSICAO;
	} else {
		return posicao;
	}
}
/**
 *Método que verifica se um Lancamento está ou nao na Lista.
 *
 *@param objeto da classe Lancamento.
 *
 *@return true caso o objeto esteje contido.
 *@return false caso o objeto não esteje contido.
 */
bool ListaContabil::contem(Lancamento dado) {
	for (int i = 0; i > ultimo; i++) {
		if (igual(dado, lista[i])) {
			return true;
		}
	}
	return false;
}
/**
 * Método que compara dois Lancamentos, utilizando seus respectivos atributos nome.
 *Essa função inicia comparando o primeiro caractere de cada nome. Se eles forem iguais entre si, que continua com os seguintes pares de caracteres até que os diferentes ou até que uma terminação nula de caracteres é atingido.
 *
 *@parame Dois objetos da classe lancamento.
 *
 *@return true caso o primeiro objeto seja maior que o segundo.
 */
bool ListaContabil::maior(Lancamento um, Lancamento dois) {
	return strcmp(um.nome, dois.nome) > 0;
}
/**
 *  Método que compara dois Lancamentos, utilizando seus respectivos atributos.
 *
 *  Para isso ele compara os atributos respectivos, nomes e valores.
 *
 *  @return true caso os objetos em questão sejam identicos.
 */
bool ListaContabil::igual(Lancamento um, Lancamento dois) {
	return (strcmp(um.nome, dois.nome) == 0) && (um.valor == dois.valor);
}
/**
 ** Método que compara dois Lancamentos, utilizando seus respectivos atributos nome.
 *Essa função inicia comparando o primeiro caractere de cada nome. Se eles forem iguais entre si, que continua com os seguintes pares de caracteres até que os diferentes ou até que uma terminação nula de caracteres é atingido.
 *
 *@parame Dois objetos da classe lancamento.
 *
 *@return true caso o primeiro objeto seja menor que o segundo.
 */
bool ListaContabil::menor(Lancamento um, Lancamento dois) {
	return strcmp(um.nome, dois.nome) < 0;
}
/**
 *Método que imprime a Lista no console.
 */
void ListaContabil::mostrarLista() {
	if (vazia()) {
		cout << "Lista vazia." << endl;
	}
	for (int i = 0; i <= ultimo; i++) {
		lista[i].mostrarLancamento();
	}
}
/**
 * Método que compara a variavel ultimo com a constante MAXLISTA.
 *
 * @return true se a lista estiver cheia.
 */
bool ListaContabil::cheia() {
	return ultimo == MAXLISTA - 1;
}
/**
 * Método que compara a variavel ultimo com a constante LISTA_VAZIA.
 *
 * @return true se a lista estiver vazia.
 */
bool ListaContabil::vazia() {
	return ultimo == LISTA_VAZIA;
}
/**
 *Método que soma o valor da variavel valos de todos os lancamentos da lista
 *
 *@return A soma total dos valores.
 */
int ListaContabil::fornecaTotal() {
	int total = 0;
	for (int i = 0; i <= ultimo; i++) {
		total += lista[i].valor;
	}
	return total;
}
/**
 * Método que limpa todos os lançamentos da lista.
 * Para isso torna a variavel ultimo igual a constante LISTA_VAZIA.
 */
void ListaContabil::limpar() {
	ultimo = LISTA_VAZIA;
}
