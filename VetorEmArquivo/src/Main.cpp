#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const char* filename = "vector";

int main() {
	List list( filename );

	while( true ) {
		cout << "1-insert 2-search 3-remove 4-list 5-exit" << endl;
		ListInfo info;
		int c;
		cin >> c;
		switch(c){
		case 1:
			cin >> info.key;
			cin >> info.cpf;
			list.insert( info );
			break;
		case 2:
			cin >> info.key;
			list.find( info );
			if( info.key == -1 )
				cout << "Key not found" << endl;
			else
				cout << info.cpf << endl;
			break;
		case 3:
			cin >> info.key;
			list.remove( info );
			break;
		case 4:
			list.print();
			break;
		case 5:
			exit(0);
		}
	}
}



