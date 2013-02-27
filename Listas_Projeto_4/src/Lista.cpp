/*
 * Lista.cpp
 *
 *  Created on: 02/10/2012
 *       Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */
#include "iostream"
#include "cstring"
#include "string.h"
#include "Lista.h"
using namespace std;
Lista::Lista() {
	// TODO Auto-generated constructor stub
	ultimo = LISTA_VAZIA;
}

Lista::~Lista() {
	// TODO Auto-generated destructor stub
}

int Lista::adiciona(char *dado) {
	if (cheia())
		return LISTA_CHEIA;
	ultimo++;
	lista[ultimo] = dado;
	return ultimo;
}

/**
 * Método que adiciona um ponteiro para char.
 *
 *  Para isso verifica se ha espaço. Caso a questão anterior seja verdadeira o objeto é adicionado na primeira posição da Lista. Deslocando em uma posição os dados já inseridos na mesma lista.
 *
 *@param *dado = ponteiro para o primeiro elemento de um array de char que vai ser adicionado na primeira posição da fila.
 *
 *@return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 *@return 0 (inteiro zero) = caso o objeto tenha sido adicionado com sucesso.
 */
int Lista::adicionaNoInicio(char *dado) {
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
 * Método que adiciona um ponteiro para char.
 *
 * Para isso verifica se ha espaço na lista. Caso a questão anterior seja verdadeira o objeto é adicionado na posição recebida pelo parametro, deslocando em uma posição os dados já inseridos após a posição adicionada.
 *
 * @param *dado = ponteiro para o primeiro elemento de um array de char que vai ser adicionado.
 * @param posicao = inteiro que identifica a posição em que o ponteiro vai ser inserido.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o número de elementos determinado pela variável MAXLISTA.
 * @return ERRO_POSICAO = caso a posição informada seja inválida, ou seja, caso nao esteja entre o inicio e o final da fila.
 * @return posicao = posição onde o ponteiro foi inserido.
 */
int Lista::adicionaNaPosicao(char *dado, int posicao) {
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
 *  Método que adiciona um ponteiro para char.
 *
 * Para isso verifica se ha espaço. Caso a questão anterior seja verdadeira o ponteiro é adicionado em ordem intrinsica, deslocando em uma posição os dados já inseridos após a posição adicionada.
 *
 * @param *dado = ponteiro para o primeiro elemento de um array de char que vai ser adicionado.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o número de elementos determinado pela variável MAXLISTA.
 * @return 0 (inteiro zero) = caso o objeto tenha sido adicionado com sucesso.
 */
int Lista::adicionaEmOrdem(char *dado) {
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
 * @return Ponteiro para um array de char que está na última posição da lista.
 */
char* Lista::retira() {
	return retiraDaPosicao(ultimo);
}
/**
 * Método que retira o primeiro elemento Lista.
 *
 * Para isso ele utiliza o método retiraDaPosicao, levando a primeira posição como parametro. Para maiores informações vide retiraDaPosicao().
 *
 *@return Ponteiro para um array de char que está na primeira posição da lista.
 */
char* Lista::retiraDoInicio() {
	return retiraDaPosicao(0);
}
/**
 * Método que retira o elemento da lista que esta armazenado na posição recebida como parametro.
 *
 * Prara isso ele testa se a posicao recebida por parametro é válida, isto é, se existe algum ponteiro armazenado na mesma.
 *
 * @param posicao = inteiro que determina a localização do dado a ser retirado.
 *
 * @return Caso não seja possível retirar:\n
 *    Ponteiro nulo, que por convenção significa que ocorreu um erro.
 * @return Caso seja possível retirar:\n
 *	  Ponteiro para um array de char.
 *
 */
char* Lista::retiraDaPosicao(int posicao) {
	if (vazia()) {
		cout << "Lista vazia." << endl;
		char *erro;
		erro = NULL;
		return erro;
	}else if (posicao < 0 || posicao > ultimo) {
		cout << "Posição inválida." << endl;
		char *erro;
		erro = NULL;
		return erro;
	}
	char *retirado = lista[posicao];
	for (int i = posicao; i < ultimo; i++) {
		lista[i] = lista[i + 1];
	}
	ultimo--;
	return retirado;

}
/**
 * Método que retira um ponteiro específico.
 *
 *  Para isso ele utiliza o método retiraDaPosicao, levando a posição do dado recebido como parametro. Para maiores informações vide retiraDaPosicao().
 *
 *  @param *dado = ponteiro para um array de char.
 */
char* Lista::retiraEspecifico(char* dado) {
	return retiraDaPosicao(posicao(dado));
}

/**
 * Método que identifica a posição de um ponteiro para array de char recebido por parâmetro.
 *
 * @param *dado = ponteiro para um array de char.
 *
 * @return ERRO_POSICAO caso o objeto em questão nao esteja na Lista.
 * @return posicao = posicao do ponteiro na Lista.
 */
int Lista::posicao(char *dado) {
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
 *Método que verifica se um ponteiro está ou nao na Lista.
 *
 *@param *dado = ponteiro para um array de char.
 *
 *@return true caso o ponteiro esteje contido.
 */
bool Lista::contem(char *dado) {
	for (int i = 0; i > ultimo; i++) {
		if (igual(dado, lista[i])) {
			return true;
		}
	}
	return false;
}

/**
 * Método que compara dois ponteiros, utilizando a função strcmp, para mais informações consulte: http://www.cplusplus.com/reference/clibrary/cstring/strcmp \n
 *Essa função inicia comparando o primeiro caractere. Se eles forem iguais entre si, que continua com os seguintes pares de caracteres até que os diferentes ou até que uma terminação nula de caracteres é atingido.
 *
 *@param *dado1 = ponteiro para um array de char.
 *@param *dado2 = ponteiro para um array de char.
 *
 *@return true caso o primeiro objeto seja maior que o segundo.
 */
bool Lista::maior(char *dado1, char *dado2) {
	return strcmp(dado1, dado2) > 0;
}
/**
 *  Método que compara dois ponteiros, utilizando a função strcmp, para mais informações consulte: http://www.cplusplus.com/reference/clibrary/cstring/strcmp
 *
 *  Para isso ele compara os atributos respectivos.
 *
 *  @return true caso os objetos em questão sejam identicos.
 */
bool Lista::igual(char *dado1, char *dado2) {
	return strcmp(dado1, dado2) == 0;
}
/**
 ** Método que compara dois ponteiros, utilizando a função strcmp, para mais informações consulte: http://www.cplusplus.com/reference/clibrary/cstring/strcmp
 *Essa função inicia comparando o primeiro caractere de cada ponteiro. Se eles forem iguais entre si, que continua com os seguintes pares de caracteres até que os diferentes ou até que uma terminação nula de caracteres é atingido.
 *
 *@param Dois objetos da classe lancamento.
 *
 *@return true caso o primeiro objeto seja menor que o segundo.
 */
bool Lista::menor(char *dado1, char *dado2) {
	return strcmp(dado1, dado2) < 0;
}
/**
 * Método que lista todos os elementos contidos no array de ponteiros.
 */
void Lista::mostrarLista() {
	if (vazia()) {
		cout << "Lista vazia." << endl;
	}
	for (int i = 0; i <= ultimo; i++) {
		cout << lista[i] << endl;
	}
}
/**
 * Método que compara a variavel ultimo com a constante MAXLISTA.
 *
 * @return true se a lista estiver cheia.
 */
bool Lista::cheia() {
	return ultimo == MAXLISTA - 1;
}
/**
 * Método que compara a variavel ultimo com a constante LISTA_VAZIA.
 *
 * @return true se a lista estiver vazia.
 */
bool Lista::vazia() {
	return ultimo == LISTA_VAZIA;
}
