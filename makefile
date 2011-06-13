CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c -fPIC $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -shared

bin/libeddi-commons.so: bin/Timer.o bin/IO.o
	$(CC) $(LFLAGS)  -Wl,-soname,libeddi-commons.so -o bin/libeddi-commons.so bin/Timer.o bin/IO.o

bin/Timer.o : include/Timer.h src/Timer.cpp
	$(CC) $(CFLAGS) -o bin/Timer.o src/Timer.cpp

bin/IO.o : include/IO.h src/IO.cpp
	$(CC) $(CFLAGS) -o bin/IO.o src/IO.cpp

clean:
	rm -f bin/*



