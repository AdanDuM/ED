/*
 * ArvoreB.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: will
 */

#include "ArvoreB.h"
#include<iostream>
#include <fstream>

using namespace std;

namespace Arvores {

ArvoreB::ArvoreB() {
	// TODO Auto-generated constructor stub
	raiz = new Nodo();
/*	arquivo.open(string("arvore.txt").c_str(),ios::in | ios::out | ios::binary | ios::trunc );
	arquivo.write((char*)&raiz,sizeof(raiz));
*/

}

ArvoreB::~ArvoreB() {
	// TODO Auto-generated destructor stub
}

void ArvoreB::insere(string k) {
//	file.open("arquivoarvB");

	/*arquivo.open(string("arvore.txt").c_str(),ios::in | ios::out | ios::binary | ios::trunc );
	Nodo* teste;
	cout<< "prestes a beg "<<teste << endl;
	arquivo.seekg(0,ios::beg);
	cout<< "prestes a ler "<<teste << endl;
	arquivo.read((char*)&teste,sizeof(Nodo));
	cout<< "prestes a testar "<<teste << endl;
	teste->mostrarNodo();
*/
	Nodo *r = raiz;
	if (r->numeroChaves == 2 * T - 1) {
		//	cout << "cheio" << endl;
		Nodo* s = new Nodo();
		raiz = s;
		s->folha = false;
		s->numeroChaves = 0;
		s->filhos[0] = r;
		//	cout << "antes div" << endl;
		dividirNodo(s, 0, r);
		//	cout << "depois div" << endl;
		insereNaoCheio(k, s);
	} else {
		insereNaoCheio(k, r);
	}
}

void ArvoreB::dividirNodo(Nodo* pai, int i, Nodo* filho) {
//	cout << "i " << i << endl;
	Nodo* irmao = new Nodo();
	irmao->folha = filho->folha;
	irmao->numeroChaves = T - 1;
	int j;
	for (j = 0; j < T - 1; j++) {
		irmao->chaves[j] = filho->chaves[(j + T)];
		filho->chaves[(j + T)] = "";
	}
	if (!filho->folha) {
		for (j = 0; j < T; j++) {
			irmao->filhos[j] = filho->filhos[j + T];
			filho->filhos[j + T] = 0;
		}
	}
	filho->numeroChaves = T - 1;
	for (j = pai->numeroChaves; j > i; j--) {
		pai->filhos[j + 1] = pai->filhos[j];
	}
	pai->filhos[i + 1] = irmao;
	for (j = pai->numeroChaves - 1; j > i - 1; j--) {
		pai->chaves[j + 1] = pai->chaves[j];
	}
	pai->chaves[i] = filho->chaves[T - 1];
	filho->chaves[T - 1] = "";
	pai->numeroChaves++;
}

void ArvoreB::insereNaoCheio(string k, Nodo* x) {
	int i = x->numeroChaves - 1;
	//cout << "inserenc " << "x " << x << "   " << x->numeroChaves << " chave "
	//		<< k << endl;
	if (x->folha) {
		//cout << "folha" << endl;
		while (i >= 0 &&  maior(x->chaves[i],k)) {
			x->chaves[i + 1] = x->chaves[i];
			i--;
		}
		x->chaves[i + 1] = k;
		x->numeroChaves++;
		//arquivo.write((char*)&raiz,sizeof(raiz));
	} else {
		//cout << "nfolha" << endl;

		while (i >= 0 && maior(x->chaves[i],k)) {
			i--;
		}
		i++;
		if (x->filhos[i]->numeroChaves == (2 * T) - 1) {
			dividirNodo(x, i, x->filhos[i]);
			if (k > x->chaves[i]) {
				i++;
			}
		}
		insereNaoCheio(k, x->filhos[i]);
	}
}

void ArvoreB::mostrarInOrdem(Nodo* nodo) {
	if (nodo->folha) {
		nodo->mostrarNodo();
	} else {
		int i = 0;
		while (i < nodo->numeroChaves) {
			mostrarInOrdem(nodo->filhos[i]);
			//cout << "chave " << nodo->chaves[i] << " pos " << i << endl;
			cout << nodo->chaves[i] << endl;
			i++;
		}
		mostrarInOrdem(nodo->filhos[i]);
	}
}
bool ArvoreB::buscar(Nodo* x, string k) {
	int i = 0;
	while (i < x->numeroChaves && maior(x->chaves[i],k)) {
		i++;
	}
	if(i<= x->numeroChaves && igual(x->chaves[i],k)){

		mostrarConteudo(x->chaves[i]);
		return true;
	}
	if(x->folha){
		return false;
	}else{
		return buscar(x->filhos[i],k);
	}
}
/*string* ArvoreB::buscar(Nodo* x, string k) {
	cout<<"dentro " << x<<endl;
	int i = 0;
	while (i < x->numeroChaves && maior(x->chaves[i],k)) {
		i++;
	}
	if(i<= x->numeroChaves && igual(x->chaves[i],k)){

		return &x->chaves[i];
	}
	if(x->folha){
		return 0;
	}else{
		return buscar(x->filhos[i],k);
	}
	}*/

bool ArvoreB::maior(string chavePrimaria, string outro){
//	return (chavePrimaria.compare(outro)>0);
	return strcmp(chavePrimaria.c_str(),outro.c_str()) > 0;
}
bool ArvoreB::menor(string chavePrimaria, string outro){
	//return (chavePrimaria.compare(outro)<0);
	return strcmp(chavePrimaria.c_str(),outro.c_str()) < 0;
}
bool ArvoreB::igual(string chavePrimaria, string outro){
	return (strcmp(chavePrimaria.c_str(),outro.c_str())==0);
}
void ArvoreB::mostrarConteudo(string chave){
	cout<<"mostrar: " << chave << endl;
	arquivo.open(chave.c_str(),ios::in);
	char line[10000];
	arquivo.getline(line, 10000);
	while(!arquivo.eof()){
		cout<< line << endl;
		arquivo.getline(line, 10000);
	}
}
};

/*
 *


#include "ArvoreB.h"
#include<iostream>
#include <fstream>

using namespace std;

namespace Arvores {

ArvoreB::ArvoreB() {
	raiz = new Nodo();

}

ArvoreB::~ArvoreB() {
}

void ArvoreB::insere(int k) {
	Nodo *r = raiz;
	if (r->numeroChaves == 2 * T - 1) {
		Nodo* s = new Nodo();
		raiz = s;
		s->folha = false;
		s->numeroChaves = 0;
		s->filhos[0] = r;
		dividirNodo(s, 0, r);
		insereNaoCheio(k, s);
	} else {
		insereNaoCheio(k, r);
	}
}

void ArvoreB::dividirNodo(Nodo* pai, int i, Nodo* filho) {
	Nodo* irmao = new Nodo();
	irmao->folha = filho->folha;
	irmao->numeroChaves = T - 1;
	int j;
	for (j = 0; j < T - 1; j++) {
		irmao->chaves[j] = filho->chaves[(j + T)];
		filho->chaves[(j + T)] = 0;
	}
	if (!filho->folha) {
		for (j = 0; j < T; j++) {
			irmao->filhos[j] = filho->filhos[j + T];
			filho->filhos[j + T] = 0;
		}
	}
	filho->numeroChaves = T - 1;
	for (j = pai->numeroChaves; j > i; j--) {
		pai->filhos[j + 1] = pai->filhos[j];
	}
	pai->filhos[i + 1] = irmao;
	for (j = pai->numeroChaves - 1; j > i - 1; j--) {
		pai->chaves[j + 1] = pai->chaves[j];
	}
	pai->chaves[i] = filho->chaves[T - 1];
	filho->chaves[T - 1] = 0;
	pai->numeroChaves++;
}

void ArvoreB::insereNaoCheio(int k, Nodo* x) {
	int i = x->numeroChaves - 1;
	if (x->folha) {
		while (i >= 0 && k < x->chaves[i]) {
			x->chaves[i + 1] = x->chaves[i];
			i--;
		}
		x->chaves[i + 1] = k;
		x->numeroChaves++;
	} else {

		while (i >= 0 && k < x->chaves[i]) {
			i--;
		}
		i++;
		if (x->filhos[i]->numeroChaves == (2 * T) - 1) {
			dividirNodo(x, i, x->filhos[i]);
			if (k > x->chaves[i]) {
				i++;
			}
		}
		insereNaoCheio(k, x->filhos[i]);
	}
}

void ArvoreB::mostrarInOrdem(Nodo* nodo) {
	if (nodo->folha) {
		nodo->mostrarNodo();
	} else {
		int i = 0;
		while (i < nodo->numeroChaves) {
			mostrarInOrdem(nodo->filhos[i]);
			cout << nodo->chaves[i] << endl;
			i++;
		}
		mostrarInOrdem(nodo->filhos[i]);
	}
	raiz->mostrarNodo();
}
int ArvoreB::buscar(Nodo* x, int k) {
	cout<<"dentro " << x<<endl;
	int i = 0;
	while (i < x->numeroChaves && k > x->chaves[i]) {
		i++;
	}
	if(i<= x->numeroChaves && k == x->chaves[i]){
		return x->chaves[i];
	}
	if(x->folha){
		return 0;
	}else{
		return buscar(x->filhos[i],k);
	}
	}
}
;

 * */
