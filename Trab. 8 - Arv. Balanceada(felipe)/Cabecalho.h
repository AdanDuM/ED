#ifndef CABECALHO_H_
#define CABECALHO_H_

#include "Elemento.h"

//Constante para indicar quando a árvore estiver vazia.
	#define VAZIA 0

//Constante para indicar erro de posição quando necessário.
	#define POSICAO -1

class Cabecalho {

private:
//Ponteiro para 'Elemento' que indica a raíz da árvore.
	Elemento *referencia;

//Variável que corresponde a quantidade de elementos que a árvore possui.
	int tamanho;

public:
	Cabecalho();
	~Cabecalho();

//Devolve o valor do atributo 'referencia'.
	Elemento* informarReferencia();

//Devolve o valor do atributo 'tamanho'.
	int informarTamanho();

//Averigua se o conteúdo do elemento 'um' é maior do que o conteúdo de 'dois'.
	bool maior(Elemento *um, Elemento *dois);

//Método booleano que retorna 'true' quando a árvore estiver vazia.
	bool testarVazia();

//Responsável por adicionar um elemento na árvore, retornando a quantidade de elementos já atualizada.
	int adicionar(Elemento *novo);

//Recebendo um vetor previamente organizado como parâmetro, adiciona todos os elementos de uma forma recursiva para balancear a árvore.
	void balancear(int *dado, int inicio, int final);

//Realiza a busca na árvores de elementos pares, de intervalo [inicio, final].
	void procurar(Elemento *raiz, int inicio, int final);
};
#endif
