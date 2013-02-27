/*
 * Main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: will
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include <time.h>
#include <sys/timeb.h>
#include"HeapSort.h"
using namespace std;
using namespace Ordenacao;
HeapSort heap;
struct timeb tempoInicial, tempoFinal;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	int tamanho = 0;
	char line[1000];
	file.getline(line, 1000);
	stringstream t(line);
	t >> tamanho;
	int numeros[tamanho];
	int contador = 0;
	file.getline(line, 1000);
	while (!file.eof()) {
		stringstream stream(line);
		stream >> numeros[contador];
		contador++;
		file.getline(line, 1000);
	}
	ftime( &tempoInicial );
	heap.ordenar(numeros,tamanho);
	ftime( &tempoFinal );

	for(int i = 0; i<tamanho;i++){
		cout<<numeros[i]<<endl;
	}
	cout<<"Tempo estimado : "<< tempoFinal.millitm - tempoInicial.millitm<<" milisegundos aprox." <<endl;
	return 0;
}


