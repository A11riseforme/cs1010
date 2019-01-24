.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: id grade index max samplerun

samplerun: 
	./test.sh id 13
	./test.sh grade 21
	./test.sh index 4
	./test.sh max 3

# vim:noexpandtab
