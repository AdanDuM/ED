/*
 * Main.cpp
 *
 *  Created on: 25/09/2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <ogait_fontana@hotmail.com>
 *
 */
#include<iostream>
#include<sstream>
#include<fstream>

#include "ListaContabil.h"

using namespace std;
ListaContabil debitos;
ListaContabil creditos;
ListaContabil *atual;
int modulo(int valor) {
	if (valor < 0)
		valor = valor * (-1);
	return valor;
}
void mostrarMenuInsercao() {
	string menu;
	menu += "________________________________________________________\n";
	menu += "| Digite o código correspondente:                       |\n";
	menu += "| 1 - Adicionar Transação                               |\n";
	menu += "| 2 - Adicionar Transação no Inicio                     |\n";
	menu += "| 3 - Adicionar Transação em Ordem                      |\n";
	menu += "| 4 - Adicionar Transação na Posição                    |\n";
	menu += "| 5 - Voltar ao menu principal                          |\n";
	menu += "|_______________________________________________________|\n";
	bool ativo = true;
	char nome[200];
	int valor;
	while (ativo) {
		cout << menu << endl;
		int comando;
		int erro;
		cin >> comando;
		switch (comando) {
		case 1: //Adicionar Transação
			cout << "Digite o nome do Lancamento: " << endl;
			cin >> nome;
			cout << "Digite o valor do Lancamento: " << endl;
			cin >> valor;
			valor = modulo(valor);
			erro = (atual->adiciona(Lancamento(nome, valor)));
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 2: //Adicionar Transação no Inicio
			cout << "Digite o nome do Lancamento: " << endl;
			cin >> nome;
			cout << "Digite o valor do Lancamento: " << endl;
			cin >> valor;
			valor = modulo(valor);
			erro = (atual->adicionaNoInicio(Lancamento(nome, valor)));
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 3: //Adicionar Transação em Ordem
			cout << "Digite o nome do Lancamento: " << endl;
			cin >> nome;
			cout << "Digite o valor do Lancamento: " << endl;
			cin >> valor;
			valor = modulo(valor);
			erro = (atual->adicionaEmOrdem(Lancamento(nome, valor)));
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			break;
		case 4: //Adicionar Transação na Posição
			int posicao;
			cout << "Digite a posição do Lancamento: " << endl;
			cin >> posicao;
			cout << "Digite o nome do Lancamento: " << endl;
			cin >> nome;
			cout << "Digite o valor do Lancamento: " << endl;
			cin >> valor;
			valor = modulo(valor);
			erro = (atual->adicionaNaPosicao(Lancamento(nome, valor), posicao));
			if (erro == LISTA_CHEIA) {
				cout << "Lista cheia." << endl;
			}
			if (erro == ERRO_POSICAO) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 5: //Voltar ao menu principal
			ativo = false;
			break;
		default: //Caso código digitado seja incompativel
			cout << "Código de comando inexistente!" << endl;
			break;
		}
	}
}

void mostrarMenuRemocao() {
	string menu;
	menu += "________________________________________________________\n";
	menu += "| Digite o código correspondente:                       |\n";
	menu += "| 1 - Retirar Último                                    |\n";
	menu += "| 2 - Retirar do Início                                 |\n";
	menu += "| 3 - Retirar da Posição                                |\n";
	menu += "| 4 - Retirar Específico                                |\n";
	menu += "| 5 - Voltar ao menu principal                          |\n";
	menu += "|_______________________________________________________|\n";
	bool ativo = true;
	Lancamento retirado;
	while (ativo) {
		cout << menu << endl;
		int comando;
		cin >> comando;
		switch (comando) {
		case 1: //Retirar Último
			if ((atual->retira()).verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
			break;
		case 2: //Retirar do Início
			if ((atual->retiraDoInicio()).verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
			break;
		case 3: //Retirar da Posição
			int posicao;
			cout << "Digite a posição do lançamento a ser removido." << endl;
			cin >> posicao;
			retirado = atual->retiraDaPosicao(posicao);
			if (retirado.verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
			if (retirado.verificarErro(ERRO_POSICAO)) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 4: //Retirar Específico
			cout << "Digite a nome do lançamento a ser removido." << endl;
			char nome[200];
			cin >> nome;
			int valor;
			cout << "Digite o valor do lançamento a ser removido." << endl;
			cin >> valor;
			retirado = (atual->retiraEspecifico(Lancamento(nome, valor)));
			if (retirado.verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
			if (retirado.verificarErro(ERRO_POSICAO)) {
				cout << "Posição inválida." << endl;
			}
			break;
		case 5: //Voltar ao menu principal
			ativo = false;
			break;
		default: //Caso código digitado seja incompativel
			cout << "Código de comando inexistente!" << endl;
			break;
		}
	}
}

void mostrarMenuPrincipal() {

	atual = &creditos;
	string menu;
	menu += "________________________________________________________\n";
	menu += "| Digite o código correspondente:                       |\n";
	menu += "| 1 - Selecionar Lista Créditos                         |\n";
	menu += "| 2 - Selecionar Lista Débitos                          |\n";
	menu += "| 3 - Lançar Transação                                  |\n";
	menu += "| 4 - Remover Transações                                |\n";
	menu += "| 5 - Listar Transações                                 |\n";
	menu += "| 6 - Mostrar Saldo ( total créditos - total débitos )  |\n";
	menu += "| 7 - Sair                                              |\n";
	menu += "|_______________________________________________________|\n";
	bool listaCreditosSelecionada = true;
	bool ativo = true;
	while (ativo) {
		cout << menu << endl;
		if (listaCreditosSelecionada) {
			cout << "Lista atual :  CRÉDITOS " << endl;
		} else {
			cout << "Lista atual :  DÉBITOS " << endl;
		}
		int comando;
		cin >> comando;
		switch (comando) {
		case 1: //Selecionar Lista Créditos
			atual = &creditos;
			listaCreditosSelecionada = true;
			break;
		case 2: //Selecionar Lista Débitos
			atual = &debitos;
			listaCreditosSelecionada = false;
			break;
		case 3: //Lançar Transação
			mostrarMenuInsercao();
			break;
		case 4: //Remover Transações
			mostrarMenuRemocao();
			break;
		case 5: //Listar Transações
			atual->mostrarLista();
			break;
		case 6: //Mostrar Saldo ( total créditos - total débitos )
			int total;
			total = (creditos.fornecaTotal() - debitos.fornecaTotal());
			cout << "Saldo: " << total << endl;
			break;
		case 7: //Sair
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
			atual->limpar();
		} else if (command == "CREDITOS") {
			atual = &creditos;
		} else if (command == "DEBITOS") {
			atual = &debitos;
		} else if (command == "INSERIR") {
			int n;
			stream >> n;
			for (int i = 0; i < n; i++) {
				file.getline(line, 256);
				stringstream ss1(line);
				char nome[200];
				ss1 >> nome;
				file.getline(line, 256);
				stringstream ss2(line);
				int valor;
				ss2 >> valor;
				int erro;
				erro = (atual->adiciona(Lancamento(nome, valor)));
				if (erro == LISTA_CHEIA) {
					cout << "Lista cheia." << endl;
				}
			}
		} else if (command == "INSERIR_EM_ORDEM") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				file.getline(line, 256);
				stringstream ss1(line);
				char nome[200];
				ss1 >> nome;
				file.getline(line, 256);
				stringstream ss2(line);
				int valor;
				ss2 >> valor;
				int erro = (atual->adicionaEmOrdem(Lancamento(nome, valor)));
				if (erro == LISTA_CHEIA) {
					cout << "Lista Cheia." << endl;
				}
			}
		} else if (command == "INSERIR_NA_POSICAO") {
			int quantidade;
			stream >> quantidade;
			int posicao;
			stream >> posicao;
			for (int i = 0; i < quantidade; i++) {
				file.getline(line, 256);
				stringstream ss1(line);
				char nome[200];
				ss1 >> nome;
				file.getline(line, 256);
				stringstream ss2(line);
				int valor;
				ss2 >> valor;
				int erro;
				erro = (atual->adicionaNaPosicao(Lancamento(nome, valor),
						posicao));
				if (erro == LISTA_CHEIA) {
					cout << "Lista Cheia." << endl;
				}else if(erro == ERRO_POSICAO){
					cout << "Posição inválida." << endl;
				}
				posicao++;
			}
		} else if (command == "REMOVER") {
			if ((atual->retira()).verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
		} else if (command == "REMOVER_DA_POSICAO") {
			int posicao;
			stream >> posicao;
			Lancamento erro = atual->retiraDaPosicao(posicao);
			if (erro.verificarErro(LISTA_VAZIA)) {
				cout << "Lista vazia." << endl;
			}
			if (erro.verificarErro(ERRO_POSICAO)) {
				cout << "Posição inválida." << endl;
			}
		} else if (command == "REMOVER_MEMBRO") {
			int quantidade;
			stream >> quantidade;
			for (int i = 0; i < quantidade; i++) {
				file.getline(line, 256);
				stringstream ss1(line);
				char nome[200];
				ss1 >> nome;
				file.getline(line, 256);
				stringstream ss2(line);
				int valor;
				ss2 >> valor;
				Lancamento erro = (atual->retiraEspecifico(
						Lancamento(nome, valor)));
				if (erro.verificarErro(LISTA_VAZIA)) {
					cout << "Lista vazia." << endl;
				}else if (erro.verificarErro(ERRO_POSICAO)) {
					cout << "Posição inválida." << endl;
				}
			}
		} else if (command == "MOSTRAR") {
			atual->mostrarLista();
		} else if (command == "SALDO") {
			int total = (creditos.fornecaTotal() - debitos.fornecaTotal());
			cout << total << endl;
		}
		file.getline(line, 256);
	}

}
/**
 * Método que executa um sistema de contabilidade simples, que contém um Plano de Contas constituído por duas listas: débitos e créditos.
 */
int main(int argc, char** argv) {
	if (argc < 2) {
		mostrarMenuPrincipal();
	} else {
		lerCasoDeTeste(argv[1]);
	}
	return 0;
}

