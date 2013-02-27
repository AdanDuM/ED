/*
 * InfoLista.h
 *
 *  Created on: 16/10/2012
 *      Author: Tiago A. Fontana <oga>it_fontana@hotmail.com
 *      		William kraemer <will.kraemer.a@gmail.com>
 */

#ifndef INFOLISTA_H_
#define INFOLISTA_H_
/*********************************************************************************************************************
 * ______________________________________________________________________________________________________________________
 * |										Dicionario de Dados														    |
 * |____________________________________________________________________________________________________________________|
 * |Nome 		   |		 Tipo    | Descrição		 															    |
 * |_______________|_________________|__________________________________________________________________________________|
 * |nomeCidade     |      caracter*  | Ponteiro que aponta para a posição de memoria  da string que                     |
 * |               |                 | contem a  informação referente ao nome da cidade.                                |
 * |horarioChegada |      inteiro    | Inteiro que contem que contem o horario de chegada do onibus.                    |
 * |horarioPartida |      inteiro    | Inteiro que contem que contem o horario de saida do onibus.                      |
 * |_______________|_________________|__________________________________________________________________________________|
 *
 *
  ********************************************************************************************************************/



/**
 * Classe que representa as informações de um elemento de uma Lista.
 */
class InfoLista {
public:
	InfoLista();
	InfoLista(char *nome, int horarioChegada, int horarioPartida);
	virtual ~InfoLista();

	bool maior(InfoLista *info);
	bool menor(InfoLista *info);
	bool igual(InfoLista *info);

	bool nomeMaior(char *info);
	bool nomeMenor(char *info);
	bool nomeIgual(char *info);

	void mostrar();

	char* nomeCidade;
	int horarioChegada;
	int horarioPartida;
};

#endif /* INFOLISTA_H_ */
