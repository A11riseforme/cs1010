.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -Wdocumentation -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: leap-2 primes-3 samplerun

clean:
	rm leap-2 primes-3

samplerun:
	./test.sh leap-2 10
	./test.sh primes-3 11

# vim:noexpandtab
