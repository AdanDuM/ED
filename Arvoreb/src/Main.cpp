/*
 * Main.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<cstring>
#include<cstdlib>
#include<sys/time.h>

#include "Nodo.h"
#include "Info.h"

using namespace std;

Nodo *raiz;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
		char line[1000];
		file.getline(line, 1000);

		raiz = new Nodo(true);

		while (!file.eof()) {
			stringstream stream(line);
			string linha = stream.str();
			string l =linha.substr(0, linha.find("|"));
			char* logradouro = (char*)l.c_str();
			string c = linha.substr(linha.find("")+1,linha.size());
			long int cep = atol(c.c_str());
			while(cep == 0){
				stream >> linha;
				c = linha.substr(linha.find(""),linha.size());
				cep = atol(c.c_str());
			}
			Info *info  = new Info(cep,logradouro);

			raiz->insereB(raiz, info);
//*********************************************************************************
/*
			timeval start,end;
			gettimeofday(&start,0);
			cout<<"inserindo"<<endl;
			raiz = raiz->insere(info, raiz,0);
			cout<<"saindo inserir"<<endl;
			gettimeofday(&end,0);
			double elapsedTime;
			elapsedTime = (end.tv_sec - start.tv_sec)*1000.0;
			elapsedTime = (end.tv_usec - start.tv_usec)/1000.0;
*/
			file.getline(line, 1000);
		}

	return 0;
}

