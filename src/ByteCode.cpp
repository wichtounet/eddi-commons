#include <iostream>
#include <iomanip>
#include <fstream>

#include "ByteCode.h"

using namespace std;

class SimpleCall {
   public:
	ByteCode m_bytecode;
	SimpleCall(ByteCode bytecode) : m_bytecode(bytecode) {}
};

class OneOperandCall {
   public:
	ByteCode m_bytecode;
	std::string m_litteral;
	OneOperandCall(ByteCode bytecode, string litteral) : m_bytecode(bytecode), m_litteral(litteral) {}
};

/* Write */

std::ostream& binary_write_string(std::ostream* stream, string value){
	return stream->write(value.c_str(), value.length());
}

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

void writeEnd(ofstream* stream){
	binary_write(stream, (int) END);
}

/* Read */

ByteCode readByteCode(ifstream* stream){
	int bytecode;
	binary_read(stream, bytecode);
	return (ByteCode) bytecode;
}

std::string binary_read_string(std::istream* stream){
	size_t size;
	binary_read(stream, size);
	
	char* buffer = new char[size + 1];
	stream->read(buffer, size);
	buffer[size] = 0;
	string litteral = buffer;
	delete[] buffer;	

	return litteral;
}
