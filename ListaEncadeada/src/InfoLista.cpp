/*
 * InfoLista.cpp
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */
#include "string.h"
#include "InfoLista.h"
#include "iostream"

InfoLista::InfoLista() {
	// TODO Auto-generated constructor stub

}

/**
 * Método que constri um objeto que representa as informações de um elemento da Lista.
 *
 * @param char *mome = ponteiro para char que representa o nome da pessoa na lista telefônica.
 * @param char *telefone = ponteiro para char que representa o telefone da pessoa na lista telefônica.
 */
InfoLista::InfoLista(char *nom, char *tel) {
	nome = nom;
	telefone = tel;
}

/**
 * Destrutor que exclui um elemento da classe InfoLista.
 * Para isso desaloca a memoria respectiva a todas as informações contidas no objeto em questão.
 */
InfoLista::~InfoLista() {
	// TODO Auto-generated destructor stub

	delete []nome;
	delete []telefone;
}

/**
 * Método que informa se um InfoLista é maior ao objeto que executa essa ação.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool InfoLista::maior(InfoLista *dado){
	return strcmp(nome, dado->nome) > 0;
}

/**
 * Método que informa se um InfoLista é menor ao objeto que executa essa ação.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool InfoLista::menor(InfoLista *dado){
	return strcmp(nome, dado->nome) < 0;
}

/**
 * Método que informa se um InfoLista é igual ao objeto que executa essa ação.
 *
 *@param InfoLista *dado= ponteiro para um objeto da classe InfoLista.
 */
bool InfoLista::igual(InfoLista *dado){
	return strcmp(nome, dado->nome) == 0 && strcmp(telefone, dado->telefone) == 0;
}

/**
 * Método que imprime na tela os dados da lista telefônica.
 */
void InfoLista::mostrar(){
	std::cout<< nome <<": "<< telefone <<std::endl;
}
