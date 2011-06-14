//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <fstream>

#include "IO.h"

using std::ostream;
using std::ofstream;
using std::string;

ostream& binary_write_string(ofstream* stream, string value){
	return stream->write(value.c_str(), value.length());
}
