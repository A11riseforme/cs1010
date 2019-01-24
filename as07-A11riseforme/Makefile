.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -Wdocumentation -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: peak scripts inversion samplerun

samplerun: 
	./test.sh peak 50
	./test.sh scripts 50
	./test.sh inversion 50

# vim:noexpandtab
