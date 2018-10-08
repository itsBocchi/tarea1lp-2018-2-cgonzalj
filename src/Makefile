all: shared
	mkdir -p bin
	mkdir -p sym

shared: compile
	gcc -c -Wall -fPIC lib/permuta.c
	gcc -shared -o sym/libpermuta.so permuta.o
	gcc -c -Wall -fPIC lib/rot13.c
	gcc -shared -o sym/rot13.so rot13.o
	gcc -c -Wall -fPIC lib/pascal.c
	gcc -shared -o sym/libpascal.so pascal.o
	gcc -c -Wall -fPIC lib/backward.c
	gcc -shared -o sym/libbackward.so backward.o
	gcc -c -Wall -fPIC lib/reverse.c
	gcc -shared -o sym/libreverse.so reverse.o

compile:
	gcc -Wall -o bin/hash main.c -ldl -w

#clean:
#  	rm -f bin/hash && rm -f *.o && rm -f sym/*.so