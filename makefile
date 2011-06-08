CC = g++
DEBUG = -g
CFLAGS = -Wall -c -fPIC $(DEBUG)
LFLAGS = -Wall $(DEBUG) -shared

libeddi-commons.so: ByteCode.o
	$(CC) $(LFLAGS)  -Wl,-soname,libeddi-commons.so -o bin/libeddi-commons.so bin/ByteCode.o

ByteCode.o : include/ByteCode.h src/ByteCode.cpp
	$(CC) $(CFLAGS) -Iinclude -o bin/ByteCode.o src/ByteCode.cpp

clean:
	rm -f bin/*



