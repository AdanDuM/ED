/*
 * Main.cpp
 *
 *  Created on: 01/11/2012
 *      Author: grad
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include"Nodo.h"

using namespace std;
Nodo raiz;
int numeros[101];

void montarArray(char* arquivo) {
	ifstream file(arquivo);
	char line[256];
	file.getline(line, 256);
	int i = 0;
	while (!file.eof()) {
		stringstream stream(line);
		int n;
		stream >> n;

		numeros[i] = n;

		i++;
		file.getline(line, 256);
	}
}

int main(int argc, char** argv) {

	//int teste[] = {1,2,6,8,12,15,20,24,25,29,40,50,60,70,80,90,91,92,93,94,95,96};
	montarArray(argv[1]);
	raiz = *raiz.construir(0,100,numeros);
	/*std::cout << "valor " << raiz.valor << " esquerda "
							<< raiz.filhoEsquerda->valor << " direita "
							<< raiz.filhoDireita->valor << std::endl;*/

	raiz.buscar(&raiz,50,100);

	return 0;
}
