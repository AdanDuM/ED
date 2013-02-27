/*
 * Main.cpp*
 *
 *  Created on: 26/12/2012
 *      Author: Tiago Augusto Fontana <ogait_fontana@hotmail.com>
 */

#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string.h>
#include "ArvoreB.h"
#include "Dados.h"
using namespace Arvores;
using namespace std;
ArvoreB arvore;
fstream file;

string tiratxt(char* nomeInteiro) {
	string nome = (string) nomeInteiro;
	cout << nome << " 1" << endl;

	int tamanho = nome.length();
	cout << tamanho << " 2" << endl;

	char* palavra = new char[tamanho];
	cout << *palavra << " 3" << endl;
	strcpy(palavra, nomeInteiro);
	cout << palavra << " 4" << endl;
	char *ptr = new char[tamanho];
	cout << ptr << " 5" << endl;
	ptr = strtok(palavra, ".");
	cout << *ptr << " 6" << endl;
	return (string) ptr;
}

void adicionarNaLista(char* nome) {

	//cout << nome << " anters tirar txt" << endl;

	//string chavePrimaria = tiratxt(nome);
	//cout << chavePrimaria << " anters inserir" << endl;
/*	Dados* novo = new Dados();
	novo->chavePrimaria = string(nome);*/
	//fstream lol;
	/*lol.open(string("manpages.txt").c_str(),
			ios::in | ios::out | ios::binary| ios::trunc);*/
	cout <<string(nome) << endl;
	arvore.insere(string(nome));
	//cout << chavePrimaria << " tirou txt" << endl;
	/*	string enderecoDiretorio = "manpages/" + (string) nome;
	const char* arquivo = enderecoDiretorio.c_str();
	cout << enderecoDiretorio << " tenta abrir" << endl;
	file.open(arquivo, ios::in);
	string all = "";
	char* temp = new char[1000];
	file.getline(temp, 1000);
	while (!file.eof()) {
		cout << temp << endl;
		all += (string) temp + "\n";
		file.getline(temp, 1000);
	}
	novo->conteudo = all;
	lol << novo;*/
}

/*
 char line[10000];
 file.getline(line, 10000);
 while (!file.eof()) {
 char *ptr;
 ptr = strtok(line," ,.;<>:/()_-#*");//argumentos: frase, caracter delimitador
 while(ptr != NULL)
 {
 cout << ptr << endl; //imprime todas as palavras!!!!!!!!!
 ptr = strtok(NULL, " ,.;<>:/()_-#*");
 delete [] ptr;
 }
 file.getline(line, 10000);
 }
 cout << "tenta fechar" << endl;
 file.clear();
 file.close();*/


/*
 void adicionarManPages(int argc, char** argv){
 for(int i=1; i < argc ; i++){
 cout <<argv[i] <<endl;
 adicionarNaLista(argv[i]);
 }*/

void adicionarManPages() {

DIR *diretorio;
struct dirent *lsdir;

// /home/tiago/Área de Trabalho/manpages
diretorio = opendir("manpages");

/* percorre todos os arquivos dentro do diretório*/
while ((lsdir = readdir(diretorio)) != NULL) {
	if (!((strcmp(lsdir->d_name, ".") == 0)
			|| (strcmp(lsdir->d_name, "..") == 0))) { //trata a ocorrencia de direcionamento de diretório para a pasta superior
		//cout << lsdir->d_name << " antes de add" << endl;
		adicionarNaLista(lsdir->d_name);
	}

}
closedir(diretorio);
}

void mostrarMenu() {
bool ativo = true;
string menu;
menu += "________________________________________________________\n";
menu += "| Digite o código correspondente:                       |\n";
menu += "| 1 - Busca por chave primaria                          |\n";
menu += "| 2 - Busca por chave secundaria                        |\n";
menu += "| 3 - Busca conjuntiva com duas chaves secundárias      |\n";
menu += "| 4 - Sair                                              |\n";
menu += "|_______________________________________________________|\n";

while (ativo) {
	cout << menu << endl;
	int comando;
	cin >> comando;
	string input;
	Dados *novo = new Dados();
			fstream lol;
	switch (comando) {
	case 1: // Busca por chave primaria
		//retornando o texto da MANPAGE para um nome-de-comando ou a mensagem de que uma MANPAGE com aquele nome não existe.
		cout << "Busca por chave primaria selecionada!" << endl;
		//arvore.mostrarInOrdem(arvore.raiz);
		cout << "Digite" << endl;
		cin >> input;
		input = input + ".txt";
		if(!arvore.buscar(arvore.raiz,arvore.raiz->chaves[0])){
			cout << "Nao foi achado!"<< endl;
		}

		break;
	case 2: // Busca por chave secundaria
		//retornando todas as MANPAGES que contém uma determinada chave secundária, ex.: filename
		cout << "Busca por chave secundaria selecionada!" << endl;
		arvore.mostrarInOrdem(arvore.raiz);
		break;
	case 3: // Busca conjuntiva com duas chaves secundárias
		// retornando todas as MANPAGES que contenham ambas as chaves. Ex.: filename e string
		cout << "Busca conjuntiva com duas chaves secundárias selecionada!"
				<< endl;

			lol.open(string("manpages.txt").c_str(),
					ios::in | ios::out | ios::binary );
			lol.read((char*)&novo,sizeof(Dados));
			cout <<" cooonteeuuuuuuuuuudo \n "<< novo->conteudo <<endl;
		break;
	case 4: //sair
		ativo = false;
		break;
	default:
		cout << "Código de comando inexistente!" << endl;
		break;
	}
}
}

int main(int argc, char** argv) {
adicionarManPages();

mostrarMenu();
return 0;
}

