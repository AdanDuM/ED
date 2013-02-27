/*
 * Main.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cstdlib>

#include "Supermercado.h"
#include "ListaCircular.h"

using namespace std;
using namespace Projeto1;

char* nomeSupermercado;
int tempoSimulacao, tempoMedioChegada, numeroCaixas, limiteCaixaEspecial;
ListaCircular caixas;
Supermercado supermercado;
void lerConfig(char* arquivo) {

	ifstream file(arquivo);
	char line[256];
	file.getline(line, 256);
	int contador = 0;
	while (!file.eof()) {
		stringstream stream(line);
		string command;
		stream >> command;
		if (line[0] == '#' || command == "\0") {
			file.getline(line, 256);
		} else {
			switch (contador) {
			case 0: //nome supermercado
			{
				int size1 = strlen(line);
				nomeSupermercado = new char[size1]; //alocação na heap
				strcpy(nomeSupermercado, line);
				file.getline(line, 256);
				contador++;
			}
				break;
			case 1: //tempo simulacao em horas
			{
				stringstream ss(command);
				int n;
				ss >> n;
				tempoSimulacao = n * 3600; // transforma para segundos
				file.getline(line, 256);
				contador++;
			}
				break;
			case 2: //tempo medio chegada de clientes
			{
				stringstream ss(command);
				int n;
				ss >> n;
				tempoMedioChegada = n;
				file.getline(line, 256);
				contador++;
			}
				break;
			case 3: //numero de caixas
			{
				stringstream ss(command);
				int n;
				ss >> n;
				limiteCaixaEspecial = n;
				file.getline(line, 256);
				contador++;
			}
				break;
			case 4: //numero de caixas
			{
				stringstream ss(command);
				int n;
				ss >> n;
				numeroCaixas = n;
				file.getline(line, 256);
				contador++;
			}
				break;
			default: //dados do caixa
			{
				int size1 = command.size();
				char *nome = new char[size1]; //alocação na heap
				strcpy(nome, (char*) command.c_str());
				int eficiencia;
				stream >> eficiencia;
				int salario;
				stream >> salario;
				caixas.adiciona(new Caixa(nome, eficiencia, salario));
				file.getline(line, 256);
			}
				break;
			}
		}
	}

}

int main(int argc, char** argv) {
	if (argc > 0) {
		srand(time(NULL));
		lerConfig(argv[1]);
		supermercado.configurarSimulacao(nomeSupermercado, tempoSimulacao,
				tempoMedioChegada, limiteCaixaEspecial, &caixas);
		supermercado.iniciarSimulacao();
		supermercado.apresentarResultados();
	}
	return 0;
}

