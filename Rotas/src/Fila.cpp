/*
 * Fila.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */
#include "iostream"
#include "Fila.h"

Fila::Fila() {
	// TODO Auto-generated constructor stub

}

Fila::~Fila() {
	// TODO Auto-generated destructor stub
}
/**
 * Método que adiciona um elemento da fila.
 *
 * Primeiramente teste se ainda é possivel adicionar um elemento à fila. Caso isso não seja verdadeiro ele retorna uma constante FILA_CHEIA.
 *
 * @param InfoFila *dado= ponteiro para um objeto da classe InfoFila.
 * @return FILA_CHEIA = constante que representa a falta de espaço na Fila.
 * @return tamanho = inteiro que informa a posição onde o dado foi inserido.
 */
int Fila::enfileirar(int numLinha, char* empresa, ListaDupla *lista) {
	ElementoFila *novo = new ElementoFila(numLinha, empresa, lista);
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
	tamanho++;
	//dado->mostrar(tamanho);
	return tamanho;
}

/**
 *Método que remove um elemento da Fila.
 *Primeiramente testa se a Fila possui elementos. Caso possua ele remove o primeiro elemento, ou seja o primeiro que foi inserido.
 *
 *@return 0(NULL) = caso a Fila não possua elementos.
 *@return InfoFila = objeto que possui as informações do elemento removido.
 */
ListaDupla* Fila::desenfileirar() {
	ElementoFila *saiu;
	ListaDupla *volta;
	if (vazia()) {
		return 0;
	}
	saiu = primeiro;
	volta = saiu->lista;
	primeiro = saiu->proximo;
	if (tamanho == 1) {
		ultimo = FILA_VAZIA;
		primeiro = FILA_VAZIA;
	}
	tamanho--;
	delete saiu;
	return volta;
}

/**
 * Metodo que testa se a fila possui elementos.
 *
 * @return true = caso a Fila esteja vazia.
 */
bool Fila::vazia() {
	return tamanho == FILA_VAZIA;
}

/**
 * Método que exclui todos os elementos da fila e suas respectivas informações, representado pela classe InfoLista.
 */
void Fila::limpar() {
	ElementoFila* i = primeiro;	//morre quando sair desse metodo
	ElementoFila* paraDeletar;	//morre quando sair desse metodo
	while (i) {				//percorre a lista e apaga os elementos do infolista
		delete i->lista;				//chama o destrutor da listaDupla
		paraDeletar = i;
		i = i->proximo;
		delete paraDeletar;
	}
	tamanho = FILA_VAZIA;
	primeiro = FILA_VAZIA;
}

/**
 * Método que imprime no console a Fila.
 */
void Fila::mostrar(){
	ElementoFila *atual;
	atual = primeiro;
	if (vazia()) {
		std::cout << "Fila vazia." << std::endl;
	}
	while (atual) {
		atual->mostrar();
		atual = atual->proximo;
	}


}

/**
 * Método que verifica se existe uma rota e/ou é possivel que o passageiro a compre.
 *
 * Para isso este metodo percorre toda a lista de empresas e fila de cidades por onde a rota passa.
 * caso seja encontrada uma rota compatível o método imprime a mesma no console e retorna um valor inteiro.
 *
 * @pram origem = cidade onde o passageiro iniciará sua viagem.
 * @param destino = cidade destino do passageiro.
 * @param hora = hora local em que o passageiro se encontra.
 */
int Fila::buscar(char *origem,char *destino, int hora){
	if(!primeiro){
		return 1;
	}
	ElementoFila* atual = primeiro;
	ListaDupla* rotaAtual = atual->lista;
	while (atual) {
		ElementoLista* cidadeAtual = rotaAtual->primeiro;
		InfoLista *info = cidadeAtual->info;
		while(cidadeAtual){
			if((info->nomeIgual(origem)) && (info->horarioPartida > hora)){
				//se dentro ele encontrou a origem
				ElementoLista *examinada = cidadeAtual->proximo;
				InfoLista *infoExaminada;
				if(examinada){
					infoExaminada = examinada->info;
				}
				while(examinada){//procurando destino
				if( (infoExaminada->nomeIgual(destino)) && ((info->horarioPartida)<(infoExaminada->horarioChegada)) ){
						std::cout<<"ROTA "<<atual->numeroLinhaOnibus<<" - "<<atual->empresaOnibus<<" "<<info->horarioPartida<<std::endl;
						return 0;
					}
					examinada = examinada->proximo;
					if(examinada){
						infoExaminada = examinada->info;
					}
				}
				examinada = cidadeAtual->anterior;
				infoExaminada = examinada->info;
				while(examinada){
					if( (infoExaminada->nomeIgual(destino)) && ((info->horarioPartida)<(infoExaminada->horarioChegada)) ){
						std::cout<<"ROTA "<<atual->numeroLinhaOnibus<<" - "<<atual->empresaOnibus<<" "<<info->horarioPartida<<std::endl;
						return 0;
					}
					examinada = examinada->anterior;
					if(examinada){
						infoExaminada = examinada->info;
					}
				}
			}
			cidadeAtual = cidadeAtual->proximo;
			if(cidadeAtual){
			info = cidadeAtual->info;
			}
		}
		atual = atual->proximo;
		if(atual)
			rotaAtual = atual->lista;
	}
	return 1;
}

