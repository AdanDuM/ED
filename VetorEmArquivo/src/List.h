#ifndef _LIST_H_
#define _LIST_H_

#include <fstream>
using namespace std;
class ListInfo {
public:
	int key;
	int cpf;
};

class List {
public:
	List( const char* filename );
	virtual ~List();

	void insert( ListInfo info );
	void remove( ListInfo info );
	void find( ListInfo& key );

	void print();
private:
	ListInfo readInfo();
	void writeInfo( ListInfo info );

	const char* filename;
	std::fstream file;
};

#endif
