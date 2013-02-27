/*
 * Main.cpp
 *
 *  Created on: 04/10/2012
 *      Author: tiago
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include"CabecaDeLista.h"
using namespace std;

CabecaDeLista lista;
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
	menu += "| 10- Limpar                                            |\n";
	menu += "| 11- Sair                                              |\n";
	menu += "|_______________________________________________________|\n";

	bool ativo = true;
	char* nome;
	char* telefone;
	char linha[10000];
	int posicao;
	InfoLista *erroAoRetirar;
	while (ativo) {
		cout << menu << endl;
		int comando;
		cin >> comando;
		switch (comando) {
		case 1: //Insere
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			if (lista.adiciona(new InfoLista(nome, telefone)) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 2: //Inserir no Inicio
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			if (lista.adicionaNoInicio(
					new InfoLista(nome, telefone)) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 3: //Insere Na Posicao
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			cout << "Digite o a posição para o numero ser Inserida: " << endl;
			cin >> posicao;
			int erro;
			erro = lista.adicionaNaPosicao(new InfoLista(nome, telefone),
					posicao);
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			} else if (erro == ERRO_POSICAO) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 4: //Insere Em Ordem
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			if (lista.adicionaEmOrdem(
					new InfoLista(nome, telefone)) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 5: //Remover
			erroAoRetirar = lista.retira();
			if (erroAoRetirar == 0) {
				cout << "Lista vazia." << endl;
			}
			delete erroAoRetirar;
			break;
		case 6: //Remover do Inicio
			erroAoRetirar = lista.retiraDoInicio();
			if (erroAoRetirar == 0) {
				cout << "Lista vazia." << endl;
			}
			delete erroAoRetirar;
			break;
		case 7: //Remover na Posição

			cout << "Insira a posição a ser removida: " << endl;
			cin >> posicao;
			delete lista.retiraDaPosicao(posicao);
			break;
		case 8: //Remover especifico
			cout << "Digite o nome: " << endl;
			cin >> linha;
			nome = new char[strlen(linha)]; //alocação na heap
			strcpy(nome, linha);
			cout << "Digite o telefone: " << endl;
			cin >> linha;
			telefone = new char[strlen(linha)]; //alocação na heap
			strcpy(telefone, linha);
			InfoLista *temp1;
			temp1 = new InfoLista(nome, telefone);
			ElementoDeLista *temp2;
			temp2 = new ElementoDeLista(temp1);
			delete lista.retiraEspecifico(temp2);
			delete temp1;
			delete temp2;
			break;
		case 9: //mostrar lista
			lista.mostrarLista();
			break;
		case 10: //Sair
			lista.limpar();
			break;
		case 11: //Sair
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
			lista = CabecaDeLista();
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				char string1[10000];
				file.getline(string1, 10000);
				int size1 = strlen(string1);
				char* nome = new char[size1]; //alocação na heap
				strcpy(nome, string1);

				char string2[10000];
				file.getline(string2, 10000);
				int size2 = strlen(string2);
				char* telefone = new char[size2]; //alocação na heap
				strcpy(telefone, string2);

				if (lista.adiciona(new InfoLista(nome, telefone)) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
		} else if (command == "INSERIR_EM_ORDEM") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				char string1[10000];
				file.getline(string1, 10000);
				int size1 = strlen(string1);
				char* nome = new char[size1]; //alocação na heap
				strcpy(nome, string1);

				char string2[10000];
				file.getline(string2, 10000);
				int size2 = strlen(string2);
				char* telefone = new char[size2]; //alocação na heap
				strcpy(telefone, string2);

				if (lista.adicionaEmOrdem(
						new InfoLista(nome, telefone)) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
		} else if (command == "INSERIR_NA_POSICAO") {
			int quantidade;
			stream >> quantidade;
			int posicao;
			stream >> posicao;
			for (int i = 0; i < quantidade; i++) {
				char string1[10000];
				file.getline(string1, 10000);
				int size1 = strlen(string1);
				char* nome = new char[size1]; //alocação na heap
				strcpy(nome, string1);

				char string2[10000];
				file.getline(string2, 10000);
				int size2 = strlen(string2);
				char* telefone = new char[size2]; //alocação na heap
				strcpy(telefone, string2);
				int erro;
				erro = lista.adicionaNaPosicao(new InfoLista(nome, telefone),
						posicao);
				if (erro == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				} else if (erro == ERRO_POSICAO) {
					cout << "Posição inválida." << endl;
				}
				posicao++;
			}
		} else if (command == "REMOVER") {
			delete lista.retira();
		} else if (command == "REMOVER_DA_POSICAO") {
			int posicao;
			stream >> posicao;
			delete lista.retiraDaPosicao(posicao);
		} else if (command == "REMOVER_MEMBRO") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				char string1[10000];
				file.getline(string1, 10000);
				int size1 = strlen(string1);
				char *nome = new char[size1]; //alocação na heap
				strcpy(nome, string1);

				char string2[10000];
				file.getline(string2, 10000);
				int size2 = strlen(string2);
				char* telefone = new char[size2]; //alocação na heap
				strcpy(telefone, string2);
				InfoLista *temp1 = new InfoLista(nome, telefone);
				ElementoDeLista *temp2 = new ElementoDeLista(temp1);
				delete lista.retiraEspecifico(temp2);
				delete[] nome;
				delete[] telefone;
				delete temp1;
				delete temp2;
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

