/*
 * Fila.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: William kraemer <will.kraemer.a@gmail.com>
 *			Tiago A. Fontana <oga>it_fontana@hotmail.com
 */

#include "Fila.h"

namespace Fila {
/**
 * Construtor que configura um objeto da classe Fila
 */
	Fila::Fila() {
		// TODO Auto-generated constructor stub
		ultimo = FILAVAZIA;
	}
	/**
	 * Destrutor que exclui um objeto da classe Fila
	 */
	Fila::~Fila() {
		// TODO Auto-generated destructor stub
	}
	/**
	 * Método que recebe um inteiro e coloca-o na última posição da Fila.
	 *
	 * @param elemento = dado da classe ElementoDaFila.
	 *
	 * @return FILACHEIA = caso a fila já possua o número de elementos suportados, determinado por MAXFILA.
	 * @return 0 (zero) = caso o dado recebido tenha sido enfileirado corretamente.	 *
	 */
	int  Fila::enfileirar(ElementoDaFila elemento)
	{
		if(ultimo == MAXFILA - 1)
		{
			return FILACHEIA;
		}
		fila[ultimo + 1] = elemento;
		ultimo++;
		return 0;
	}
	/**
	 *Método que desenfileira o primeiro dado posicionado na fila.
	 *
	 *@return FILAVAZIA = caso a fila não possua nenhum dado a ser retirado.
	 *@return 0 (zero) = caso o dado tenha sido desenfileirado corretamente.
	 */
	int Fila::desenfileirar()
	{
		if(ultimo == FILAVAZIA)
		{
			return FILAVAZIA;
		}
		for(int i = 0; i < ultimo; i++)
		{
			fila[i] = fila[i+1];
		}
		ultimo--;
		return 0;
	}
	/**
	 *Método que imprime no console a Fila.
	 *
	 *O primeiro dado a ser impresso será o primeiro que foi enfileirado, sendo que o último dado a ser enfileirado o último a ser impresso.
	 */
	void Fila::mostrarFila()
	{
		if (ultimo == FILAVAZIA) {
				std::cout << "Fila Vazia."<<endl;
			} else {
				for (int i = 0; i <= ultimo; i++) {
					std::cout << fila[i].nome << endl;
				}
			}
	}
	/**
	 * Método que limpa o conteúdo da Fila. Para isso torna a variável ultimo¹ igual a "FILAVAZIA"(-1).( último¹ = variável que controla a quantidade de elementos da pilha)
	 */
	void Fila::limpar()
	{
		ultimo= FILAVAZIA;
	}
} /* namespace Fila */
