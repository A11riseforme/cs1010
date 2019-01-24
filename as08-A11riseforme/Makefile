.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -Wdocumentation -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: maze fill samplerun

samplerun:
	./test.sh maze 2
	./test.sh fill 2

# vim:noexpandtab
