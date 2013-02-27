#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Cabecalho.h"

using namespace std;
Cabecalho *arvore;

int main(int argc, char** argv){

	stringstream stream;
	ifstream file(argv[1]);
	char line[256];

	while(!file.eof()){
		file.getline(line, 256);
		stringstream stream(line);
		string comando;
		stream >> comando;

		if(comando == "CRIAR")
			arvore = new Cabecalho();

		if(comando == "INSERIR"){
			int quantidade;
			stream >> quantidade;
			int dados[quantidade];
			for(int i = 0; i < quantidade; i++){
				file.getline(line, 256);
				dados[i] = atoi(line);
			}
			arvore->balancear(dados, 0, quantidade);
		}

		if(comando == "BUSCAR"){
			file.getline(line, 256);
			int inicio = atoi(line);
			file.getline(line, 256);
			int final = atoi(line);
			cout << "Buscar números pares entre [" << inicio << ", " << final << "]." << endl;
			arvore->procurar(arvore->informarReferencia(), inicio, final);
		}
	}

}
