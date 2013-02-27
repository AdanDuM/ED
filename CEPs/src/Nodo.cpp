/*
 * Nodo.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#include "Nodo.h"
#include <iostream>
namespace AVL {

Nodo::Nodo() {
	// TODO Auto-generated constructor stub
	alt = -1;
	info = 0;
	esquerda = 0;
	direita = 0;
}
Nodo::Nodo(Info *i) {
	alt = -1;
	info = i;
	esquerda = 0;
	direita = 0;
}

Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

int Nodo::altura(Nodo *subArvore) {
	if (subArvore == 0)
		return -1; /* A altura de uma subárvore
		 inexistente é definida como -1 */
	else
		return subArvore->alt;

}
Nodo* Nodo::rotacaoEsquerdaSimples(Nodo* k2) {
	Nodo* k1;
	k1 = k2->esquerda;
	k2->esquerda = k1->direita;
	k1->direita = k2;
	/* atualizando alturas */
	k2->alt = max(altura(k2->esquerda), altura(k2->direita)) + 1;
	k1->alt = max(altura(k1->esquerda), k2->alt) + 1;
	return k1; /* nova raiz da subárvore */
}

Nodo* Nodo::rotacaoDireitaSimples(Nodo* k2) {

	Nodo* k1;
	k1 = k2->direita;
	k2->direita = k1->esquerda;
	k1->esquerda = k2;
	/* atualizando alturas */
	k2->alt = max(altura(k2->direita), altura(k2->esquerda)) + 1;
	k1->alt = max(altura(k1->direita), k2->alt) + 1;
	return k1; /* nova raiz da subárvore */
}

Nodo* Nodo::rotacaoDuplaEsquerda(Nodo* k3) {
	k3->esquerda = rotacaoDireitaSimples(k3->esquerda);
	return (rotacaoEsquerdaSimples(k3));
}

Nodo* Nodo::rotacaoDuplaDireita(Nodo* k3) {
	k3->direita = rotacaoEsquerdaSimples(k3->direita);
	return (rotacaoDireitaSimples(k3));
}

Nodo* Nodo::insere(Info *info, Nodo *arv, Nodo *pai) {
	Nodo* arv_rodada;
	if (arv == 0) {
		arv = new Nodo();
		if (arv == 0)
			return 0;
		arv->info = info;
		arv->alt = 0;
		arv->esquerda = 0;
		arv->direita = 0;
	} else {

		if (info->cep < arv->info->cep) {
			arv->esquerda = insere(info, arv->esquerda, arv);
			if ((altura(arv->esquerda) - altura(arv->direita)) > 1) {
				if (info->cep < arv->esquerda->info->cep) {
					arv_rodada = rotacaoEsquerdaSimples(arv);
				} else {
					arv_rodada = rotacaoDuplaEsquerda(arv);
				}
				if (pai->esquerda == arv) {
					pai->esquerda = arv_rodada;
				} else {
					pai->direita = arv_rodada;
				}
			} else {
				arv->alt = max(altura(arv->esquerda), altura(arv->direita)) + 1;
			}
		} else {

			if (info->cep > arv->info->cep) {
				arv->direita = insere(info, arv->direita, arv);
				if ((altura(arv->direita) - altura(arv->esquerda)) > 1) {
					if (info->cep < arv->direita->info->cep) {

						arv_rodada = rotacaoDireitaSimples(arv);
					} else {
						arv_rodada = rotacaoDuplaDireita(arv);
					}
					if (pai->direita == arv) {
						pai->direita = arv_rodada;
					} else {
						pai->esquerda = arv_rodada;
					}
				}

			} else {
				return 0;
			}
		}
	}
	return arv;
}
int Nodo::max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
} /* namespace Fila */

