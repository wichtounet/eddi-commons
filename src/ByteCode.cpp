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

template<typename T>
std::ostream& binary_write(std::ostream* os, const T& value){
    return os->write(reinterpret_cast<const char*>(&value), sizeof(T));
}

void writeOneOperandCall(ofstream* outStream, ByteCode bytecode, string litteral){
	binary_write(outStream, &bytecode);
	binary_write(outStream, &litteral);
}

void writeSimpleCall(ofstream* outStream, ByteCode bytecode){
	binary_write(outStream, &bytecode);
}
