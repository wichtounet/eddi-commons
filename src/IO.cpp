#include <iostream>
#include <iomanip>
#include <fstream>

#include "IO.h"

using namespace std;

std::ostream& binary_write_string(std::ofstream* stream, string value){
	return stream->write(value.c_str(), value.length());
}
