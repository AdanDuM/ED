/*
 * Nodo.cpp
 *
 *  Created on: 21/11/2012
 *      Author: tiago
 */
#include "iostream"
#include "Nodo.h"
using namespace std;
Nodo::Nodo() { //constroi somente folhas!!
	// TODO Auto-generated constructor stub
	numeroChaves = 0;
	folha = true;
	filhos = new Nodo*[ORDEM*2];
	chaves = new Info*[((ORDEM*2)-1)];

}

Nodo::Nodo(bool fol) {
	numeroChaves = 0;
	folha = fol;
	filhos = new Nodo*[ORDEM*2];
	chaves = new Info*[((ORDEM*2)-1)];
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}


Nodo* Nodo::insereB(Nodo *raiz,Info *info){
	Nodo *filho = 0;
	if(raiz->folha){
		insereFolhaB(raiz, info);
	}else{
		filho = selecionaRamoDecida(raiz, info);
		insereB(filho, info);
	}

	if(nodoCheio(filho)){
		divideNodo(raiz, filho);
	}
	if(nodoCheio(raiz)){
		Nodo *temporario = raiz;
		Nodo *raizNova = new Nodo(false);

		divideNodo(raizNova, temporario);
		raiz = raizNova;
	}
	return this;
}


void Nodo::divideNodo(Nodo *raiz,Nodo *filho){
	if(filho->folha){
		divideFolha(raiz, filho);
	}else{
		divideSubArvore(raiz, filho);
	}


}


void Nodo::divideFolha(Nodo *raiz,Nodo *filho){


	int mediana = ORDEM - 1;
	Info *sobe;
	sobe = filho->chaves[mediana];
	delete filho->chaves[mediana];
	filho->numeroChaves --;
	Nodo novo = new Nodo(filho->folha);


	//populando o novo nodo!
	int posnovo = 0;
	int i = mediana + 1;
	for(; i>(ORDEM*2)-1; i++){
		novo.chaves[posnovo] = filho->chaves[i];
		novo.filhos[posnovo] = filho->filhos[i];

		delete filho->chaves[i];
		filho->filhos[i] = 0;
		filho->numeroChaves --;
		novo.numeroChaves ++;

		posnovo ++;

	}



	novo.filhos[posnovo] = filho->filhos[i+1];
	filho->filhos[i+1] = 0;




	insereEmOrdem(raiz, sobe);


}

void Nodo::divideSubArvore(Nodo *raiz,Nodo *filho){


	int mediana = ORDEM - 1;
	Info *sobe;
	sobe = filho->chaves[mediana];
	delete filho->chaves[mediana];
	Nodo novo = new Nodo(filho->folha);


	//populando o novo nodo!
	int posnovo = 0;
	int i = mediana + 1;
	for(; i>(ORDEM*2)-1; i++){
		novo.chaves[posnovo] = filho->chaves[i];
		novo.filhos[posnovo] = filho->filhos[i];

		delete filho->chaves[i];
		filho->filhos[i] = 0;

		posnovo ++;
	}

	novo.filhos[posnovo] = filho->filhos[i+1];
	filho->filhos[i+1] = 0;


	raiz->chaves[numeroChaves-1] = sobe;
	raiz->filhos[numeroChaves-1] = &novo;


}

void Nodo::insereEmOrdem(Nodo *nodo, Info *info){
	cout<<"Inserindo"<<endl;

	int posicao = 0;
	for(int i = 0; i < nodo->numeroChaves; i++){
		if(!(nodo->chaves[posicao]->maior(info))){
			posicao++;
		}
	}
	nodo->numeroChaves ++;
	for(int i = nodo->numeroChaves; i > posicao; i--){
		nodo->chaves[i] = nodo->chaves[i -1];
	}
	nodo->chaves[posicao] = info;
}




void Nodo::insereFolhaB(Nodo *folha,Info *info){


/*	if(numeroChaves == 0){
		folha->chaves[numeroChaves] = info;
		numeroChaves ++;
	}else{*/
		insereEmOrdem(folha,info);

//	}

	for(int i =0 ; i< numeroChaves; i++){
		folha->chaves[i]->mostrar();
	}
}

Nodo* Nodo::selecionaRamoDecida(Nodo *raiz,Info *info){
	int posicao = 0;
	while(raiz->chaves[posicao] && raiz->chaves[posicao]->menor(info) ){
		posicao ++;
	}
	return raiz->filhos[posicao];
}



bool Nodo::nodoCheio(Nodo *filho){
	if(!filho){
		return false;
	}
	return filho->numeroChaves == (ORDEM*2)-1;

}


