#include "List.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

List::List( const char* filename ): filename( filename ) {
	file.open( filename, ios::binary | ios::in | ios::out );
	if( !file.is_open() ){
		file.open( filename, ios::binary | ios::in | ios::out | ios::trunc );
	}
}

List::~List() {
}

ListInfo List::readInfo( ) {
	ListInfo info;
	file.read( (char*)&info.key, sizeof( int ) );
	file.read( (char*)&info.cpf, sizeof( int ) );
	return info;
}

void List::writeInfo( ListInfo info ) {
	file.write( (char*)&info.key, sizeof( int ) );
	file.write( (char*)&info.cpf, sizeof( int ) );
}

void List::insert( ListInfo info ) {
	file.seekg( 0, ios::end );
	int length = file.tellg();
	file.seekg( 0, ios::beg );
	if ( !length ){
		writeInfo( info );
		return;
	}

	fstream newFile;
	newFile.open( string(filename).append(".bk").c_str(), ios::in | ios::out | ios::binary | ios::trunc );
	char buffer[length];
	file.read( buffer, length );
	newFile.write( buffer, length );

	file.seekg( 0 );
	int i = 0;
	while( i < length/sizeof(ListInfo) && readInfo().key <= info.key  )
		i++;

	file.seekp( i*sizeof( ListInfo)  );
	writeInfo( info );

	if( length - i*sizeof(ListInfo) ){
		newFile.seekg( i*sizeof(ListInfo) );
		char bufferTwo[ length - i*sizeof(ListInfo) ];
		newFile.read( bufferTwo,  length - i*sizeof(ListInfo) );
		file.write( bufferTwo, length - i*sizeof( ListInfo ) );
	}
}

void List::remove( ListInfo info ) {
	file.seekg( 0, ios::end );
	int length = file.tellg();
	file.seekg( 0, ios::beg );

	char buffer[length];

	fstream newFile;
	string backupFilename = string(filename).append(".bk");

	newFile.open( backupFilename.c_str(), ios::in | ios::out | ios::binary | ios::trunc );

	file.seekg( 0 );
	int i = 0;
	while( i < length/sizeof(ListInfo) && readInfo().key != info.key  )
		i++;

	if( i*sizeof(ListInfo) == length )
		return;

	file.seekg( 0 );
	file.read( buffer, i*sizeof(ListInfo) );
	newFile.write( buffer, i*sizeof(ListInfo) );
	file.seekg( sizeof(ListInfo), ios::cur );
	file.read( buffer,  length - (i+1)*sizeof(ListInfo) );
	newFile.write( buffer,  length - (i+1)*sizeof(ListInfo) );

	file.close();
	rename( backupFilename.c_str(), filename );
	::remove( backupFilename.c_str() );
	file.open( filename );
}

void List::find( ListInfo& key ) {
	file.seekg( 0 );
	ListInfo info = readInfo();
	while( key.key != info.key && ! file.eof() )
		info = readInfo();

	if( file.eof() )
		key.key = -1;
	else
		key.cpf = info.cpf;
	file.clear();
}

void List::print( ) {
	file.seekg( 0 );
	ListInfo info = readInfo();
	while( !file.eof() ){
		cout << info.key << " || " << info.cpf << endl;
		info = readInfo();
	}
	file.clear();
}
