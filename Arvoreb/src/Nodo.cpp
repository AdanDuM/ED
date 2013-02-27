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

void Nodo::insereB(Nodo *raiz,Info *info){
	Nodo *filho = 0;
	if(raiz->folha){
		cout<<"chamando insere folha"<<endl;
		insereFolhaB(raiz, info);
	}else{
		filho = selecionaRamoDecida(raiz, info);
		insereB(filho, info);
	}
	if(nodoCheio(filho)){
		cout<<"chamando divide nodo"<<endl;
		divideNodo(raiz, filho);
	}
	if(nodoCheio(raiz)){
		cout<<"chamando divide nodo 2"<<endl;
		Nodo *temporario = raiz;
		raiz = new Nodo(false);
		divideNodo(raiz, temporario);
	}
}
void Nodo::insereFolhaB(Nodo *folha,Info *info){
	folha->chaves[numeroChaves] = info;
	numeroChaves++;
	/*for(int i =0 ; i< numeroChaves; i++){
		folha->chaves[i]->mostrar();
	}*/
}
Nodo* Nodo::selecionaRamoDecida(Nodo *raiz,Info *info){
	cout<<"dentro elecionar decida"<<endl;
	int posicao = 0;
	while(raiz->chaves[posicao] && raiz->chaves[posicao]->menor(info) ){
		posicao ++;
	}
	return raiz->filhos[posicao];
}
void Nodo::divideNodo(Nodo *raiz,Nodo *filho){
	cout<<"dentro divide nodo"<<endl;

	int mediana = ORDEM - 1;
	Info *sobe;
	sobe = filho->chaves[mediana];
	filho->chaves[mediana] = 0;
	Nodo *novo = new Nodo(filho->folha);

	cout<<"antes popular"<<endl;

	//populando o novo nodo!
	int posnovo = 0;
	int i;
	for(i = mediana + 1; i>(ORDEM*2)-1; i++){
		novo->chaves[posnovo] = filho->chaves[i];
		novo->filhos[posnovo] = filho->filhos[i];

		filho->chaves[i] = 0;
		filho->filhos[i] = 0;

		novo->numeroChaves = mediana;
		posnovo ++;

	}

	cout<<"depois do for"<<endl;
	novo->filhos[posnovo] = filho->filhos[i+1];
	filho->filhos[i+1] = 0;

	cout<<"quase no fim"<< raiz-> numeroChaves<<endl;

	raiz->chaves[raiz->numeroChaves] = sobe;
	raiz->filhos[raiz->numeroChaves] = novo;

	cout<<"fim divide nodo"<<endl;
}

bool Nodo::nodoCheio(Nodo *filho){
	if(!filho){
		return false;
	}
	return filho->numeroChaves == (ORDEM*2)-1;
}
