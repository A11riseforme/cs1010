.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: collatz weekday circle pattern samplerun

samplerun:
	./test.sh collatz 4
	./test.sh weekday 4
	./test.sh circle 4
	./test.sh pattern 4

# vim:noexpandtab
