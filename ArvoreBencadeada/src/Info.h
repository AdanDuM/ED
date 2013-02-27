/*
 * Info.h
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#ifndef INFO_H_
#define INFO_H_
namespace ArvoreB{
class Info {
public:
	Info();
	Info(long int c, char* l);
	virtual ~Info();


	bool maior(Info *dado);
	bool menor(Info *dado);
	bool igual(Info *dado);

	void mostrar();
private:
	long int cep;
	char *logradouro;

};
}

#endif /* INFO_H_ */
