/*
 * main.cpp
 *
 *  Created on: Jan 10, 2013
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
/*
arvore.insere(1);
arvore.insere(2);
arvore.insere(3);
arvore.insere(4);
arvore.insere(5);
arvore.insere(6);
arvore.insere(7);
arvore.insere(8);
arvore.insere(9);
arvore.insere(10);
arvore.insere(11);
arvore.insere(12);
arvore.insere(13);
arvore.insere(14);
arvore.insere(15);
arvore.insere(16);
arvore.insere(17);
arvore.insere(18);
arvore.insere(19);
arvore.insere(20);
arvore.insere(21);
arvore.insere(22);
arvore.insere(23);
*/
arvore.mostrarInOrdem(arvore.raiz);

	return 0;
}


