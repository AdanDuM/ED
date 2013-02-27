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


void Nodo::insereB(Nodo *nodo,Info *info){
	Nodo *filho = 0;
	if(nodo->folha){
		insereFolhaB(nodo, info);
	}else{
		filho = selecionaRamoDecida(nodo, info);
		insereB(filho, info);
	}
	if(nodoCheio(filho) | nodoCheio(nodo)){
		divideNodo(nodo, filho);
	}
}
void Nodo::divideFolha(Nodo *pai,Nodo *nodo){
	if(pai == this){
		divideRaiz(pai);
	}


	int mediana = ORDEM - 1;
	Info *sobe;
	sobe = nodo->chaves[mediana];
	delete nodo->chaves[mediana];
	nodo->numeroChaves --;
	Nodo novo = new Nodo(nodo->folha);

	//populando o novo nodo!
	int posnovo = 0;
	int i = mediana + 1;
	for(; i>(ORDEM*2)-1; i++){
		novo.chaves[posnovo] = nodo->chaves[i];
		novo.filhos[posnovo] = nodo->filhos[i];

		delete nodo->chaves[i];
		nodo->filhos[i] = 0;
		nodo->numeroChaves --;
		novo.numeroChaves ++;

		posnovo ++;

	}



	novo.filhos[posnovo] = nodo->filhos[i+1];
	nodo->filhos[i+1] = 0;


	insereEmOrdem(pai, sobe);
	nodo->folha = false;
}


void Nodo::divideNodo(Nodo *raiz,Nodo *filho){
	if(raiz->folha){
		 divideFolha(raiz, filho);
	}else{
		 divideSubArvore(raiz, filho);
	}
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

Nodo* Nodo::selecionaRamoDecida(Nodo *raiz,Info *info){
	int posicao = 0;
	while(raiz->chaves[posicao] && raiz->chaves[posicao]->menor(info) ){
		posicao ++;
	}
	return raiz->filhos[posicao];
}
void Nodo::insereFolhaB(Nodo *folha,Info *info){
	if(numeroChaves == 0){
		folha->chaves[numeroChaves] = info;
		numeroChaves ++;
	}else{
		insereEmOrdem(folha,info);

	}
	for(int i =0 ; i< numeroChaves; i++){
		folha->chaves[i]->mostrar();
	}
}

bool Nodo::nodoCheio(Nodo *nodo){
	if(!nodo){
		return false;
	}
	return nodo->numeroChaves == (ORDEM*2)-1;
}

void Nodo::divideRaiz(Nodo *raiz){

	int mediana = ORDEM - 1;
	Info *sobe;
	sobe = raiz->chaves[mediana];
	Nodo novaEsquerda = new Nodo(raiz->folha);
	Nodo novaDireita = new Nodo(raiz->folha);

	int posnovo =0;
	int i = 0;
		for(; i>mediana; i++){
			novaEsquerda.chaves[posnovo] = raiz->chaves[i];
			novaEsquerda.filhos[posnovo] = raiz->filhos[i];

			raiz->chaves[i] = 0;
			raiz->filhos[i] = 0;
			raiz->numeroChaves --;
			novaEsquerda.numeroChaves ++;

			posnovo ++;
		}
		novaEsquerda.filhos[posnovo] = raiz->filhos[i+1];



	posnovo =0;
	i = mediana + 1;
	for(; i>(ORDEM*2)-1; i++){
		novaDireita.chaves[posnovo] = raiz->chaves[i];
		novaDireita.filhos[posnovo] = raiz->filhos[i];

		raiz->chaves[i] = 0;
		raiz->filhos[i] = 0;
		raiz->numeroChaves --;
		novaDireita.numeroChaves ++;

		posnovo ++;
	}
	novaDireita.filhos[posnovo] = raiz->filhos[i+1];
	for(int j =0; j>(ORDEM*2)-1; j++){
			raiz->chaves[i] = 0;
			raiz->filhos[i] = 0;
	}
	raiz->filhos[i+1] = 0;
	raiz->numeroChaves =0;
	raiz->insereEmOrdem(raiz,sobe);
	raiz->filhos[0] = &novaEsquerda;
	raiz->filhos[1] = &novaDireita;
	cout<<"raiz quebrada"<<endl;
}

