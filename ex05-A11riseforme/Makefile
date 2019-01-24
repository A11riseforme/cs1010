.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -Wdocumentation -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: square escape magicsquare samplerun

samplerun: 
	./test.sh square 13
	./test.sh escape 11
	./test.sh magicsquare 10

# vim:noexpandtab
