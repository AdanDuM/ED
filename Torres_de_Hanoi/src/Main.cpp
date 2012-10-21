/*
 * Main.cpp
 *
 *  Created on: Oct 17, 2012
 *      Author: will
 */
#include "TorresDeHanoi.h"
#include<iostream>

using namespace PilhaEncadeada;
int main(){
	int quantidade;
	std::cout<<"Insira o numero de Discos a ser usado"<<std::endl;
	std::cin >> quantidade;
	TorresDeHanoi torres = TorresDeHanoi(quantidade);
	torres.iniciarJogadas();
	return 0;
}



