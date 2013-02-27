/*
 * InfoLista.cpp
 *
 *  Created on: 04/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */
#include "string.h"
#include "InfoFila.h"
#include "iostream"

/**
 * Método que constri um objeto que representa as informações de um elemento da Fila.
 */
InfoFila::InfoFila() {
	// TODO Auto-generated constructor stub

}

/**
 * Método que constri um objeto que representa as informações de um elemento da Fila.
 *
 * @param char *nome = ponteiro para o nome do proprietário do computador.
 * @param char *telefone = ponteiro para o telefone do proprietário do computador.
 * @param char *modelo = ponteiro para o modelo do computador a ser consertado.
 * @param char *preço = ponteiro para o preço aproximado do conserto.
 *
 */
InfoFila::InfoFila(char *nom, char *tel, char *mod, char *pre) {
	nome = nom;
	telefone = tel;
	modelo = mod;
	preco = pre;
}

/**
 * Destrutor que exclui um elemento da classe InfoFila.
 * Para isso desaloca a memoria respectiva a todas as informações contidas no objeto em questão.
 */
InfoFila::~InfoFila() {
	// TODO Auto-generated destructor stub
	delete[] nome;
	delete[] telefone;
	delete[] modelo;
	delete[] preco;
}

/**
 * Método que imprime na tela os dados da chamada de serviço.
 */
void InfoFila::mostrar(int semanas){
	std::cout<< nome <<"( "<< telefone <<" / " <<modelo <<" ):"<< preco <<" em "<< (semanas*2) << " semanas" <<std::endl;
}
