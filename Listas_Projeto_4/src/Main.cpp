/*
 * Main.cpp
 *
 *  Created on: 02/10/2012
 *       Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include"Lista.h"

using namespace std;

Lista lista;

void mostrarMenuPrincipal() {
	string menu;
	menu += "________________________________________________________\n";
	menu += "| Digite o código correspondente:                       |\n";
	menu += "| 1 - Inserir                                           |\n";
	menu += "| 2 - Inserir No Inicio                                 |\n";
	menu += "| 3 - Inserir Na Posição                                |\n";
	menu += "| 4 - Inserir Em Ordem                                  |\n";
	menu += "| 5 - Remover                                           |\n";
	menu += "| 6 - Remover No Inicio                                 |\n";
	menu += "| 7 - Remover Da Posição                                |\n";
	menu += "| 8 - Remover Elemento                                  |\n";
	menu += "| 9 - Mostrar Lista                                     |\n";
	menu += "| 10- Sair                                              |\n";
	menu += "|_______________________________________________________|\n";
	bool ativo = true;
	char* frase;
	char linha[10000];
	int posicao;
	while (ativo) {
		cout << menu << endl;
		int comando;
		cin >> comando;
		switch (comando) {
		case 1: //Insere
			cout << "Digite o a frase a ser Inserida: " << endl;
			cin >> linha;
			frase = new char[strlen(linha)]; //alocação na heap
			strcpy(frase, linha);
			if (lista.adiciona(frase) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 2: //Inserir no Inicio
			cout << "Digite o a frase a ser Inserida no Inicio: " << endl;
			cin >> linha;
			frase = new char[strlen(linha)]; //alocação na heap
			strcpy(frase, linha);
			if (lista.adicionaNoInicio(frase) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 3: //Insere Na Posicao

			cout << "Digite o a frase a ser Inserida: " << endl;
			cin >> linha;
			cout << "Digite o a posição para a frase ser Inserida: " << endl;
			cin >> posicao;

			frase = new char[strlen(linha)]; //alocação na heap
			strcpy(frase, linha);
			int erro;
			erro = lista.adicionaNaPosicao(frase, posicao);
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			} else if (erro == ERRO_POSICAO) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 4: //Insere Em Ordem
			cout << "Digite o a frase a ser Inserida em Ordem: " << endl;
			cin >> linha;
			frase = new char[strlen(linha)]; //alocação na heap
			strcpy(frase, linha);
			if (lista.adicionaEmOrdem(frase) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 5://Remover
			delete [] lista.retira();
			break;
		case 6://Remover do Inicio
			delete [] lista.retiraDoInicio();
			break;
		case 7://Remover na Posição

			cout<< "Insira a posição a ser removida: "<<endl;
			cin >> posicao;
			delete [] lista.retiraDaPosicao(posicao);
			break;
		case 8://Remover especifico
			cout << "Digite o a frase a ser Removida: " << endl;
			cin >> linha;
			frase = new char[strlen(linha)]; //alocação na heap
			strcpy(frase, linha);
			delete [] lista.retiraEspecifico(frase);
			delete [] frase;
			break;
		case 9: //mostrar lista
			lista.mostrarLista();
			break;
		case 10: //Sair
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
			lista = Lista();
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				char line[10000];
				file.getline(line, 10000);
				int size = strlen(line);
				char* myString = new char[size]; //alocação na heap
				strcpy(myString, line);
				if (lista.adiciona(myString) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
		} else if (command == "INSERIR_EM_ORDEM") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				char line[10000];
				file.getline(line, 10000);
				int size = strlen(line);
				char* myString = new char[size]; //alocação na heap
				strcpy(myString, line);
				if (lista.adicionaEmOrdem(myString) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}

			}
		} else if (command == "INSERIR_NA_POSICAO") {
			int quantidade;
			stream >> quantidade;
			int posicao;
			stream >> posicao;
			for (int i = 0; i < quantidade; i++) {
				char line[10000];
				file.getline(line, 10000);
				int size = strlen(line);
				char* myString = new char[size]; //alocação na heap
				strcpy(myString, line);
				int erro;
				erro = lista.adicionaNaPosicao(myString, posicao);
				if (erro == LISTA_CHEIA) {
					cout << "Lista Cheia." << endl;
				} else if (erro == ERRO_POSICAO) {
					cout << "Posição inválida." << endl;
				}
				posicao++;
			}
		} else if (command == "REMOVER") {
			delete[] lista.retira();
		} else if (command == "REMOVER_DA_POSICAO") {
			int posicao;
			stream >> posicao;
			delete[]  lista.retiraDaPosicao(posicao);
		} else if (command == "REMOVER_MEMBRO") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				char line[10000];
				file.getline(line, 10000);
				int size = strlen(line);
				char* myString = new char[size]; //alocação na heap
				strcpy(myString, line);
				delete[] lista.retiraEspecifico(myString);
			}
		} else if (command == "MOSTRAR") {
			lista.mostrarLista();
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

