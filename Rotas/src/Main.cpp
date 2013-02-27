/*
 * Main.cpp
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 *
 */


#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>

#include "Fila.h"
#include "InfoLista.h"
#include "ListaDupla.h"

using namespace std;

ListaDupla lista;
Fila fila;

void testarListaDupla() {
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
	char *nomeCidade;
	char *temp;
	int horarioChegada;
	int horarioPartida;
	char linha[10000];
	int posicao;
	int erro;
	InfoLista *erroAoRetirar;
	while (ativo) {
		cout << menu << endl;
		int comando;
		cin >> comando;
		switch (comando) {
		case 1: //Insere
			cout << "Digite o nome da linha: " << endl;
			cin >> linha;
			nomeCidade = new char[strlen(linha)]; //alocação na heap
			strcpy(nomeCidade, linha);

			cout << "Digite o horário de chegada: " << endl;
			cin >> horarioChegada;

			cout << "Digite o horário de partida: " << endl;
			cin >> horarioPartida;

			if (lista.adiciona(new InfoLista( nomeCidade, horarioChegada, horarioPartida)) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 2: //Inserir no Inicio
			cout << "Digite o nome da linha: " << endl;
			cin >> linha;
			nomeCidade = new char[strlen(linha)]; //alocação na heap
			strcpy(nomeCidade, linha);

			cout << "Digite o horário de chegada: " << endl;
			cin >> horarioChegada;

			cout << "Digite o horário de partida: " << endl;
			cin >> horarioPartida;

			if (lista.adicionaNoInicio(new InfoLista( nomeCidade, horarioChegada, horarioPartida)) == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 3: //Insere Na Posicao
			cout << "Digite o nome da linha: " << endl;
			cin >> linha;
			nomeCidade = new char[strlen(linha)]; //alocação na heap
			strcpy(nomeCidade, linha);

			cout << "Digite o horário de chegada: " << endl;
			cin >> horarioChegada;

			cout << "Digite o horário de partida: " << endl;
			cin >> horarioPartida;

			cout << "Digite o a posição para ser Inserida: " << endl;
			cin >> posicao;

			erro = lista.adicionaNaPosicao((new InfoLista( nomeCidade, horarioChegada, horarioPartida)),posicao);
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			} else if (erro == ERRO_POSICAO) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 4: //Insere Em Ordem
			cout << "Digite o nome da linha: " << endl;
			cin >> linha;
			nomeCidade = new char[strlen(linha)]; //alocação na heap
			strcpy(nomeCidade, linha);

			cout << "Digite o horário de partida: " << endl;
			cin >> horarioPartida;

			cout << "Digite o horário de chegada: " << endl;
			cin >> horarioChegada;

			erro = lista.adicionaEmOrdem(new InfoLista(nomeCidade, horarioChegada, horarioPartida));
			if(erro == LISTA_CHEIA)
				cout << "Lista cheia." << endl;

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
			cout << "Digite o nome da linha: " << endl;
			cin >> linha;
			nomeCidade = new char[strlen(linha)]; //alocação na heap
			strcpy(nomeCidade, linha);

			cout << "Digite o horário de chegada: " << endl;
			cin >> linha;
			temp = new char[strlen(linha)]; //alocação na heap
			horarioChegada =  (int)temp;

			cout << "Digite o horário de partida: " << endl;
			cin >> linha;
			temp = new char[strlen(linha)]; //alocação na heap
			horarioPartida =  (int)temp;

			InfoLista *temp1;
			temp1 = new InfoLista(nomeCidade, horarioChegada, horarioPartida);
			ElementoLista *temp2;
			temp2 = new ElementoLista(temp1);

			delete lista.retiraEspecifico(temp2);
			delete temp1;
			delete temp2;
			break;
		case 9: //mostrar lista
			lista.mostrar();
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

void mostrarMenuPrincipal() {
	std::string menu;
	menu += "___________________________________\n";
	menu += "| Digite o código correspondente: |\n";
	menu += "| 1 - Inserir Rota                |\n";
	menu += "| 2 - Remover Rota                |\n";
	menu += "| 3 - Mostrar                     |\n";
	menu += "| 4 - Buscar                      |\n";
	menu += "| 5 - Limpar                      |\n";
	menu += "| 6 - Sair                        |\n";
	menu += "|_________________________________|\n";

	bool ativo = true;
	while (ativo) {
		cout << menu << endl;
		int comando;
		int numeroLinha;
		char *empresaOnibus;
		char *nomeCidade;
		int horarioChegada;
		int horarioPartida;
		int resultado ;
		char *origem, *destino;
		int hora;
		char linha[10000];
		cin >> comando;
		switch (comando) {
		case 1: //Inserir Rota
		{
			ListaDupla* listaDupla = new ListaDupla();
			cout << "Digite o numero da linha: " << endl;
			cin >> numeroLinha;
			cout << "Digite o nome da empresa: " << endl;
			cin >> linha;
			empresaOnibus = new char[strlen(linha)]; //alocação na heap
			strcpy(empresaOnibus, linha);
			int x;
			cout << "Digite o numero de cidades por onde a rota passa: " << endl;
			cin >> x;
			for(int i = 0; i < x; i++)
			{
				cout << "Digite a cidade: " << endl;
				cin >> linha;
				nomeCidade = new char[strlen(linha)]; //alocação na heap
				strcpy(nomeCidade, linha);
				cout << "Digite o horário de partida: " << endl;
				cin >> horarioPartida;
				cout << "Digite o horário de chegada: " << endl;
				cin >> horarioChegada;
				if (listaDupla->adiciona(new InfoLista( nomeCidade, horarioChegada, horarioPartida)) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
			fila.enfileirar(numeroLinha, empresaOnibus, listaDupla);
			break;
		}
		case 2: //Remover Rota
			ListaDupla *erro;
			erro = fila.desenfileirar();
			if (erro == 0) {
				cout << "Lista vazia." << endl;
			}
			delete erro;
			break;
		case 3: //Mostrar
			fila.mostrar();
			break;
		case 4: //buscar
			cout << "Digite a cidade de origem: " << endl;
			cin >> linha;
			origem = new char[strlen(linha)]; //alocação na heap
			strcpy(origem, linha);
			cout << "Digite a cidade de destino: " << endl;
			cin >> linha;
			destino = new char[strlen(linha)]; //alocação na heap
			strcpy(destino, linha);
			cout << "Digite a hora: " << endl;
			cin >> hora;
			resultado = fila.buscar(origem, destino, hora);
			if(resultado){
				cout<< "Não há rota." <<endl;
			}
			break;
		case 5: //Limpar
			fila.limpar();
			break;
		case 6: //Sair
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
			fila.limpar();
		}else if(command == "ROTA"){
			ListaDupla* listaDupla = new ListaDupla();
			int numeroLinha;
			stream >> numeroLinha;
			char string1[10000];
			stream >> string1;
			int size1 = strlen(string1);
			char* empresaOnibus = new char[size1]; //alocação na heap
			strcpy(empresaOnibus, string1);
			int x;
			stream >> x;
			for(int i = 0; i < x; i++)
			{
				char string1[10000];
				file.getline(string1, 10000);
				int size1 = strlen(string1);
				char* nomeCidade = new char[size1]; //alocação na heap
				strcpy(nomeCidade, string1);
				file.getline(line, 256);
				stringstream st2(line);
				int horarioChegada;
				st2 >> horarioChegada;
				file.getline(line, 256);
				stringstream st3(line);
				int horarioPartida;
				st3 >> horarioPartida;
				if (listaDupla->adiciona(new InfoLista( nomeCidade, horarioChegada, horarioPartida)) == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
			fila.enfileirar(numeroLinha, empresaOnibus, listaDupla);
		}else if(command == "BUSCAR_ROTA"){
			char *origem, *destino;
			int hora;

			char string1[10000];
			file.getline(string1, 10000);
			int size1 = strlen(string1);
			origem = new char[size1]; //alocação na heap
			strcpy(origem, string1);

			char string2[10000];
			file.getline(string2, 10000);
			int size2 = strlen(string2);
			destino = new char[size2]; //alocação na heap
			strcpy(destino, string2);

			file.getline(line, 256);
			stringstream st1(line);
			st1 >> hora;

			int resultado = fila.buscar(origem, destino, hora);
			if(resultado){
				cout<< "Não há rota." <<endl;
			}


		}else if(command == "MOSTRAR"){
			fila.mostrar();
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
