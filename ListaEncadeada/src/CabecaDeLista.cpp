/*
 * CabecaDeLista.cpp
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */
#include "iostream"
#include "CabecaDeLista.h"

/**
 * Método que constri um objeto que representa uma lista encadeada.
 */
CabecaDeLista::CabecaDeLista() {
	// TODO Auto-generated constructor stub
	tamanho = 0;
	primeiro = 0;
}

/**
 * Destrutor que exclui uma lista encadeada.
 *
 * Para isso utiliza o método limpar.
 */
CabecaDeLista::~CabecaDeLista() {
	// TODO Auto-generated destructor stub
	limpar();
}

/**
 * Método que adiciona um elemento da lista.
 *
 * Primeiramente teste se ainda é possivel adicionar um elemento à lista. Caso isso não seja verdadeiro ele retorna uma constante LISTA_CHEIA.
 *
 * @param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 * @return LISTA_CHEIA = constante que representa a falta de espaço na Lista.
 * @return tamanho = inteiro que informa a posição onde o dado foi inserido.
 */
int CabecaDeLista::adiciona(InfoLista *dado) {
	if (vazia()) {
		return adicionaNoInicio(dado);
	}
	ElementoDeLista *novo = new ElementoDeLista();
	if (novo == 0) {
		return LISTA_CHEIA;
	}
	ElementoDeLista *anterior;
	anterior = primeiro;
	while (anterior->proximo != 0) {
		anterior = anterior->proximo;
	}
	anterior->proximo = novo;
	novo->proximo = 0;
	novo->info = dado;
	tamanho++;
	return 0; // return adicionaNaPosicao(dado,tamanho+1);

}

/**
 * Método que adiciona no início um objeto da classe ElementoDeLista.
 *
 *  Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na primeira posição da Lista.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 *
 *@return LISRA_CHEIA = constante que representa a falta de espaço na Lista.
 * @return 1 = inteiro que informa a posição onde o dado foi inserido.
 */
int CabecaDeLista::adicionaNoInicio(InfoLista *dado) {
	ElementoDeLista *novo;
	novo = new ElementoDeLista();
	if (novo == 0) {
		return LISTA_CHEIA;
	} else {
		novo->proximo = primeiro;
		novo->info = dado;
		primeiro = novo;
		tamanho++;
	}
	return 1;
}

/**
 * Método que adiciona um objeto da classe ElementoDeLista.
 *
 * Para isso verifica se ha espaço na mesma. Caso a questão anterior seja verdadeira o objeto é adicionado na posição recebida pelo parametro.
 *
 * @param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 * @param posicao = inteiro que identifica a posição em que o dado vai ser inserido.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 * @return ERRO_POSICAO = caso a posição informada seja inválida, ou seja, caso nao esteja entre o inicio e o final da lista.
 * @return tamanho = tamanho final da lista.
 */
int CabecaDeLista::adicionaNaPosicao(InfoLista *dado, int posicao) {
	ElementoDeLista *novo, *anterior;
	if (posicao > tamanho + 1) {
		return ERRO_POSICAO;
	} else {
		if (posicao == 1) {
			return adicionaNoInicio(dado);
		} else {
			novo = new ElementoDeLista();
			if (novo == 0) {
				return LISTA_CHEIA;
			} else {
				anterior = primeiro;
				for (int i = 0; i < posicao - 2; i++) {
					anterior = anterior->proximo;
				}
				novo->proximo = anterior->proximo;
				novo->info = dado;
				anterior->proximo = novo;
				tamanho++;
				return tamanho;
			}
		}
	}
}

/**
 *Método que adiciona um objeto da classe ElementoDeLista.
 *
 *
 * @param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 *
 * @return LISTA_CHEIA = caso a lista em execução já possua o numero de elementos determinado pela variável MAXLISTA.
 * @return ERRO_POSICAO = caso a posição informada seja inválida, ou seja, caso nao esteja entre o inicio e o final da lista.
 * @return tamanho = tamanho final da lista.
 */
int CabecaDeLista::adicionaEmOrdem(InfoLista *dado) {
	ElementoDeLista *atual;
	int posicao;
	if (vazia()) {
		return adicionaNoInicio(dado);
	} else {
		atual = primeiro;
		posicao = 1;
		while (atual->proximo != 0 && maior(dado, atual->info)) {
			atual = atual->proximo;
			posicao++;
		}
		if (maior(dado, atual->info)) {
			return adicionaNaPosicao(dado, posicao + 1);
		} else {
			return adicionaNaPosicao(dado, posicao);
		}
	}
}

/**
 *Método que retira o último elemento da Lista.
 *
 * Para isso ele utiliza o método retiraDaPosicao, levando a última posição como parametro. Para maiores informações vide retiraDaPosicao().
 *
 * @return InfoLista = ponteiro para um objeto da classe InfoLista.
 */
InfoLista* CabecaDeLista::retira() {
	return retiraDaPosicao(tamanho);
}

/**
 * Método que retira o primeiro elemento Lista.
 *
 *
 * @return 0(NULL) = caso a lista esteja vazia.
 * @return InfoLista = ponteiro para um objeto da classe InfoLista.
 */
InfoLista* CabecaDeLista::retiraDoInicio() {
	ElementoDeLista *saiu;
	InfoLista *volta;
	if (vazia()) {
		return 0;
	} else {
		saiu = primeiro;
		volta = saiu->info;
		primeiro = saiu->proximo;
		if (tamanho == 1) {
			primeiro = LISTA_VAZIA;
		}
		tamanho--;
		delete saiu;
		return volta;
	}
}

/**
 * Método que retira um objeto específico da classe ElementoDeLista.
 *
 *  Para isso ele utiliza o método retiraDaPosicao, levando a posição do dado recebido como parametro. Para maiores informações vide retiraDaPosicao().
 *
 * @param elemento = objeto da classe ElementoDeLista que vai ser retirado da lista.
 *
 @return InfoLista = ponteiro para um objeto da classe InfoLista.
 */
InfoLista* CabecaDeLista::retiraEspecifico(ElementoDeLista *elemento) {
	return retiraDaPosicao(posicao(elemento));
}

/**
 * Método que retira o elemento da lista que esta armazenado na posição recebida como parametro.
 *
 * Prara isso ele testa se a posicao recebida por parametro é válida, isto é, se existe algum objeto armazenado na mesma.
 *
 * @param posicao = inteiro que determina a localização do dado a ser retirado.
 *
 * @return 0(null) = Caso não seja possível retirar.
 * @return InfoLista = ponteiro para um objeto da classe InfoLista.
 */
InfoLista* CabecaDeLista::retiraDaPosicao(int posicao) {
	ElementoDeLista *anterior, *eliminar;
	InfoLista *volta;
	if (vazia()) {
		std::cout << "Lista vazia." << std::endl;
		return 0;
	}
	if (posicao > tamanho || posicao < 0) {
		std::cout << "Posição inválida." << std::endl;
		return 0;
	} else {
		if (posicao == 1) {
			return retiraDoInicio();
		} else {
			anterior = primeiro;
			for (int i = 0; i < posicao - 2; i++) {
				anterior = anterior->proximo;
			}
			eliminar = anterior->proximo;
			volta = eliminar->info;
			anterior->proximo = eliminar->proximo;
			tamanho--;
			delete eliminar;
			return volta;
		}
	}
}

/**
 * Método que identifica a posição de um objeto da classe ElementoDeLista recebido por parâmetro.
 *
 *  @param elemento = objeto da classe ElementoDeLista.
 *
 * @return LISTA_VAZIA = constante que informa que não ha elementos na Lista.
 * @return ERRO_POSICAO caso o objeto em questão nao esteja na Lista.
 * @return posicao = posição onde o ElementoDeLista se encontra na Lista.
 */
int CabecaDeLista::posicao(ElementoDeLista *elemento) {
	if (vazia()) {
		return LISTA_VAZIA;
	}
	int posicao = 1;
	ElementoDeLista *atual;
	atual = primeiro;
	while (atual != 0 && !(igual(atual->info, elemento->info))) {
		atual = atual->proximo;
		posicao++;
	}
	if (atual == 0) {
		return ERRO_POSICAO;
	}
	return posicao;
}

/**
 *Método que imprime a Lista no console.
 */
void CabecaDeLista::mostrarLista() {
	ElementoDeLista* atual = primeiro;
	if (vazia()) {
		std::cout << "Lista vazia." << std::endl;
	}
	while (atual) {
		atual->info->mostrar();
		atual = atual->proximo;
	}
}

/**
 * Método que informa se a Lista está vazia.
 */
bool CabecaDeLista::vazia() {
	return tamanho == LISTA_VAZIA;
}

/**
 * Método que informa se um InfoLista é maior que o segundo recebido por parametro.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool CabecaDeLista::CabecaDeLista::maior(InfoLista *dado1, InfoLista *dado2) {
	return dado1->maior(dado2);
}

/**
 * Método que informa se um InfoLista é igual que o segundo recebido por parametro.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool CabecaDeLista::igual(InfoLista *dado1, InfoLista *dado2) {
	return dado1->igual(dado2);
}

/**
 * Método que informa se um InfoLista é menor que o segundo recebido por parametro.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool CabecaDeLista::menor(InfoLista *dado1, InfoLista *dado2) {
	return dado1->menor(dado2);
}

/**
 * Método que desaloca toda a memória alocada dinamicamente para a Lista.
 */
void CabecaDeLista::limpar() {
	ElementoDeLista* i = primeiro;	//morre quando sair desse metodo
	ElementoDeLista* paraDeletar;	//morre quando sair desse metodo
	while (i) {				//percorre a lista e apaga os elementos do infolista
		delete i->info;				//chama o destrutor de infolista
		paraDeletar = i;
		i = i->proximo;
		delete paraDeletar;
	}
	tamanho = LISTA_VAZIA;
	primeiro = LISTA_VAZIA;
}
