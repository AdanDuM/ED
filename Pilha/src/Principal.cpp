/*
 * Controlador.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
*/
#include "Pilha.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace Pilha;
Pilha::Pilha pilha;

void testar(const char * arquivo) {
	ifstream file(arquivo);
	char line[256];
	file.getline(line, 256);
	while (!file.eof()) {
		stringstream stream(line);
		string command;

		stream >> command;
		if (command == "CRIAR") {
			pilha.limpar();
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				file.getline(line, 256);
				stringstream ss(line);
				int num;
				ss >> num;
				int erro;
				erro = pilha.empilhar(num);
				if (erro == PILHACHEIA) {
					cout << "Pilha cheia." << endl;
				}
			}
		} else if (command == "MOSTRAR") {
			pilha.mostrarPilha();
		} else if (command == "REMOVER") {
			int erro;
			erro = pilha.desempilhar();
			if (erro == PILHAVAZIA) {
				cout << "Pilha vazia." << endl;
			}
		}
		file.getline(line, 256);
	}
}

void mostrarMenu() {
	string menu;
	menu += "___________________________________\n";
	menu += "| Digite o código correspondente: |\n";
	menu += "| 1 - Empilhar                    |\n";
	menu += "| 2 - Desempilhar                 |\n";
	menu += "| 3 - Mostrar Pilha               |\n";
	menu += "| 4 - Limpar                      |\n";
	menu += "| 5 - Sair                        |\n";
	menu += "|_________________________________|\n";

	bool ativo = true;
	while (ativo) {
		cout << menu << endl;
		int comando;
		cin >> comando;
		switch (comando) {
		case 1:
			cout << "Digite a quantidade de dados a serem empilhados" << endl;
			int quant;
			cin >> quant;
			for (int i = 0; i < quant; i++) {
				int valor;
				cout << "Digite o valor correspondente a " << i + 1
						<< " posição" << endl;
				cin >> valor;
				int erro;
				erro = pilha.empilhar(valor);
				if (erro == PILHACHEIA) {
					cout << "Pilha cheia." << endl;
				}
			}
			break;
		case 2:
			int erro;
			erro = pilha.desempilhar();
			if (erro == PILHAVAZIA) {
				cout << "Pilha Vazia." << endl;
			} else {
				cout << "Desempilhado: " << erro << endl;
			}
			break;
		case 3:
			pilha.mostrarPilha();
			break;
		case 4:
			cout << "Limpando Pilha" << endl;
			pilha.limpar();
			break;
		case 5:
			ativo = false;
			break;
		default:
			cout << "Código de comando inexistente!" << endl;
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		testar(argv[1]);
	} else {
		mostrarMenu();
	}
	return 0;
}
