CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c -fPIC $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -shared

libeddi-commons.so: ByteCode.o Timer.o
	$(CC) $(LFLAGS)  -Wl,-soname,libeddi-commons.so -o bin/libeddi-commons.so bin/ByteCode.o bin/Timer.o

ByteCode.o : include/ByteCode.h src/ByteCode.cpp
	$(CC) $(CFLAGS) -o bin/ByteCode.o src/ByteCode.cpp

Timer.o : include/Timer.h src/Timer.cpp
	$(CC) $(CFLAGS) -o bin/Timer.o src/Timer.cpp

clean:
	rm -f bin/*



