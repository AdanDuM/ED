/*
 * Cliente.h
 *
 *  Created on: Nov 7, 2012
 *      Author: will
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MIN_COMPRAS 2
#define MAX_COMPRAS 100
#define	MIN_VALOR 1
#define MAX_VALOR 90
#define PROB_CHEQUE 20

namespace Projeto1 {
enum TipoCliente {
	BuscaMenorFila, BuscaFilaComMenosProdutos
};
class Cliente {
public:
	Cliente();
	Cliente(int chegada);
	virtual ~Cliente();
	/** entre 2 e 100 */
	int totalCompras;
	/** cada item varia entre 1 e 90r$ dai td junto é colocado aqui */
	int valorCompras;
	/** horario de chegada do cliente */
	int chegada;
	/** horario de saida do cliente */
	int saida;
	/** True quando for pagamento em cheque */
	bool cheque;
	/** enum de tipo do cliente */
	TipoCliente tipo;
	void gerarTotalDeCompras();
	void calcularValorDeCompras();
	void decidirCheque();
};

} /* namespace Fila */
#endif /* CLIENTE_H_ */
