CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c -fPIC $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -shared

bin/libeddi-commons.so: bin/Timer.o
	$(CC) $(LFLAGS)  -Wl,-soname,libeddi-commons.so -o bin/libeddi-commons.so bin/Timer.o

bin/Timer.o : include/Timer.hpp src/Timer.cpp
	$(CC) $(CFLAGS) -o bin/Timer.o src/Timer.cpp

clean:
	rm -f bin/*



