/*
 * main.cpp
 *
 *  Created on: Feb 10, 2013
 *      Author: will
 */
#include<iostream>
#include<sstream>
#include<fstream>


using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	char line[1000];
	int i =1;
	file.getline(line, 1000);
	while (!file.eof()) {
		stringstream stream(line);
		int numero;
		stream >> numero;
		if(numero != i){cout<<"erro "<< numero<<endl;i--;}
		i++;
		file.getline(line, 1000);
	}
}



