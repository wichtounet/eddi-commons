#include <iostream>
#include <iomanip>
#include <fstream>

#include "ByteCode.h"
#include "IO.h"

using namespace std;

/* Write */

void writeLitteral(ofstream* stream, string litteral){
	binary_write(stream, 'S');
	binary_write(stream, litteral.length() - 2);
	binary_write_string(stream, litteral.substr(1, litteral.length() - 2));
}

void writeOneOperandCall(ofstream* stream, ByteCode bytecode, string litteral){
	binary_write(stream, (int) bytecode);
	
	writeLitteral(stream, litteral);
}

void writeSimpleCall(ofstream* stream, ByteCode bytecode){
	binary_write(stream, (int) bytecode);
}

void writeHeader(ofstream* stream){
	binary_write(stream, (int)('E' + 'D' + 'D' + 'I'));
}

void writeEnd(ofstream* stream){
	binary_write(stream, (int) END);
}

/* Read */

ByteCode readByteCode(ifstream* stream){
	int bytecode;
	binary_read(stream, bytecode);
	return (ByteCode) bytecode;
}

int readHeader(ifstream* stream){
	int header;
	binary_read(stream, header);
	return header;
}

char readConstantType(ifstream* stream){
	char type;
	binary_read(stream, type);
	return type;
}

string readLitteral(ifstream* stream){
	size_t size;
	binary_read(stream, size);
	
	char* buffer = new char[size + 1];
	stream->read(buffer, size);
	buffer[size] = 0;
	string litteral = buffer;
	delete[] buffer;	

	return litteral;
}
