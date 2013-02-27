/*
 * Info.h
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#ifndef INFO_H_
#define INFO_H_

namespace AVL {

class Info {
public:
	Info();
	Info(long int c, char* l);
	virtual ~Info();
	long int cep;
	char *logradouro;

};

} /* namespace Fila */
#endif /* INFO_H_ */
