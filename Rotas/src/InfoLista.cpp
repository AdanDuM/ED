/*
 * InfoLista.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */
#include "string.h"
#include "InfoLista.h"
#include "iostream"

InfoLista::InfoLista() {
	// TODO Auto-generated constructor stub
}

InfoLista::InfoLista(char *nCidade, int hChegada, int hPartida){
	nomeCidade = nCidade;
	horarioChegada = hChegada;
	horarioPartida = hPartida;
}

InfoLista::~InfoLista() {
	// TODO Auto-generated destructor stub
	delete []nomeCidade;
	horarioChegada = 0;
	horarioPartida = 0;
}

bool InfoLista::maior(InfoLista *info){
	return strcmp(nomeCidade, info->nomeCidade) > 0;
}

bool InfoLista::menor(InfoLista *info){
	return strcmp(nomeCidade, info->nomeCidade) < 0;
}

bool InfoLista::igual(InfoLista *info){
	return strcmp(nomeCidade, info->nomeCidade) == 0;
}

bool InfoLista::nomeMaior(char *dado){
	return strcmp(nomeCidade, dado) > 0;
}


bool InfoLista::nomeMenor(char *dado){
	return strcmp(nomeCidade, dado) < 0;
}


bool InfoLista::nomeIgual(char *dado){
	return strcmp(nomeCidade, dado) == 0 ;
}

void InfoLista::mostrar(){
	std::cout<< nomeCidade <<" : "<< horarioChegada << " -- "<< horarioPartida <<std::endl;
}
