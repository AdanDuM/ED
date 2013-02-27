/*
 * Main.cpp
 *
 *  Created on: 10/10/2012
 *      Author: Tiago A. Fontana <ogait_fontana@hotmail.com>
 *      	 William kraemer <will.kraemer.a@gmail.com>
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include"CabecaDeFila.h"
using namespace std;

CabecaDeFila fila;
void mostrarMenuPrincipal() {
	std::string menu;
	menu += "___________________________________\n";
	menu += "| Digite o código correspondente: |\n";
	menu += "| 1 - Inserir Pedido              |\n";
	menu += "| 2 - Finalizar Pedido            |\n";
	menu += "| 3 - Limpar                      |\n";
	menu += "| 4 - Sair                        |\n";
	menu += "|_________________________________|\n";

	bool ativo = true;
	while (ativo) {
		cout << menu << endl;
		int comando;
		char *nome, *telefone, *data, *valor;
		InfoFila *erro;
		char linha[10000];
		cin >> comando;
		switch (comando) {
		case 1: //Inserir Pedido
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			cout << "Digite o modelo do Computador: " << endl;
			cin >> linha;
			data = new char[strlen(linha)]; //alocação na heap
			strcpy(data, linha);
			cout << "Digite o valor aproximado do conserto: " << endl;
			cin >> linha;
			valor = new char[strlen(linha)]; //alocação na heap
			strcpy(valor, linha);
			if (fila.enfileirar(
					new InfoFila(nome, telefone, data, valor)) == FILA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 2: //Finalizar pedido
			erro = fila.desenfileirar();
			if (erro == 0) {
				cout << "Lista vazia." << endl;
			}
			delete erro;
			break;
		case 3: //Limpar
			fila.limpar();
			break;
		case 4: //Sair
			ativo = false;
			break;
		default:
			cout << "Código de comando inexistente!" << endl;
			break;
		}
	}
}

void lerCasoDeTeste(char* arquivo) {
	ifstream file(arquivo);
	char line[256];
	file.getline(line, 256);
	while (!file.eof()) {
		stringstream stream(line);
		string command;
		stream >> command;
		if (command == "CRIAR") {
			fila = CabecaDeFila();
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				char string[10000];
				file.getline(string, 10000);
				int size1 = strlen(string);
				char* nome = new char[size1]; //alocação na heap
				strcpy(nome, string);

				file.getline(string, 10000);
				int size2 = strlen(string);
				char* telefone = new char[size2]; //alocação na heap
				strcpy(telefone, string);

				file.getline(string, 10000);
				int size3 = strlen(string);
				char* modelo = new char[size3]; //alocação na heap
				strcpy(modelo, string);

				file.getline(string, 10000);
				int size4 = strlen(string);
				char* valor = new char[size4]; //alocação na heap
				strcpy(valor, string);

				if (fila.enfileirar(new InfoFila(nome, telefone, modelo, valor)) == FILA_CHEIA) {
					cout << "Fila cheia." << endl;
				}
			}
		}else if(command == "REMOVER"){
			if(fila.desenfileirar() == 0){
				cout << "Fila vazia."<<endl;
			}
		}
		file.getline(line, 10000);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		mostrarMenuPrincipal();
	} else {
		lerCasoDeTeste(argv[1]);
	}
	return 0;
}
