/*
 * Main.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: will
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include "ArvoreB.h"


using namespace std;
using namespace Arvores;
ArvoreB arvore;
int main(int argc, char** argv) {
	ifstream file(argv[1]);
	char line[1000];
	file.getline(line, 1000);
	while (!file.eof()) {
		stringstream stream(line);
		int numero;
		stream >> numero;
		arvore.insere(numero);
		file.getline(line, 1000);
	}
	arvore.mostrarInOrdem(arvore.raiz);
	int b;
	while(b!=(-1)){
		cout<<"busque: "<<endl;
		cin>>b;
		cout<<"resultado " << arvore.buscar(arvore.raiz,b)<<endl;
	}
}


