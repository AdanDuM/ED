#ifndef ELEMENTO_H_
#define ELEMENTO_H_

class Elemento{

public:

	Elemento(int con);
	~Elemento();

	Elemento* informarReferencia(bool extremo);
	int informarConteudo();


	void receberConteudo(int cont);
	Elemento* receberReferencia(Elemento *ref, bool extremo);

private:
	Elemento *referencia[2];
	int conteudo;
};
#endif
