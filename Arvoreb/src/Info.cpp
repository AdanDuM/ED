/*
 * Info.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */
#include "iostream"
#include "string.h"
#include "Info.h"

using namespace std;


Info::Info() {
	// TODO Auto-generated constructor stub
	logradouro = 0;
	cep = 0;
}
Info::Info(long int c, char* l) {
	logradouro = new char [strlen(l)];
	strcpy(logradouro, l);
	cep = c;
}

Info::~Info() {
	// TODO Auto-generated destructor stub
}

bool Info::maior(Info *dado){
	return cep > dado->cep;
}

bool Info::menor(Info *dado){
	return cep < dado->cep;
}

bool Info::igual(Info *dado){
	return cep == dado->cep;
}

void Info::mostrar(){
	cout<< "logradouro: "<< logradouro <<" cep: " << cep <<endl;
}
