/*
 * Principal.cpp
 *
 *  Created on: 19/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 *
 *
 */

#include "Fila.h"

#include <fstream>
#include <sstream>
#include <iostream>


using namespace Fila;

Fila::Fila fila;


void testar(const char * arquivo){
	ifstream file(arquivo);
	char line[256];
	file.getline(line, 256);
	while (!file.eof()) {
		stringstream stream(line);
		string command;
		stream >> command;

		if (command == "CRIAR") {
			fila.limpar();
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				file.getline(line, 256);
				stringstream ss(line);
				char valor[MAXNOME];
				ss >> valor;
				int erro;
				ElementoDaFila elemento = ElementoDaFila();
				elemento.receberNome(valor);
				erro = fila.enfileirar(elemento);
				if (erro == FILACHEIA) {
					cout << "Fila Cheia." << endl;
				}
			}
		} else if (command == "REMOVER") {
			int erro;
			erro = fila.desenfileirar();
			if (erro == FILAVAZIA) {
				cout << "Fila Vazia." << endl;
			}
		} else if (command == "MOSTRAR") {
			fila.mostrarFila();
		}
		file.getline(line, 256);
	}
}

void mostrarMenu(){
	std::string menu;
	menu += "___________________________________\n";
	menu += "| Digite o código correspondente: |\n";
	menu += "| 1 - Enfileirar                  |\n";
	menu += "| 2 - Desenfileirar               |\n";
	menu += "| 3 - Mostrar Fila                |\n";
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

					cout << "Digite a quantidade de dados a serem enfileirados"
							<< endl;
					int quant;
					cin >> quant;
					for (int i = 0; i < quant; i++) {
						char valor[MAXNOME];
						cout << "Digite o valor correspondente a " << i + 1
								<< " posição" << endl;
						cin >> valor;
						int erro;
						ElementoDaFila elemento = ElementoDaFila();
						elemento.receberNome(valor);
						erro = fila.enfileirar(elemento);
						if (erro == FILACHEIA) {
							cout << "Fila Cheia." << endl;
						}
					}
					break;
				case 2:
					int erro;
					erro = fila.desenfileirar();
					if (erro == FILAVAZIA) {
						cout << "Fila Vazia." << endl;
					}
					break;
				case 3:
					fila.mostrarFila();
					break;
				case 4:
					fila.limpar();
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
