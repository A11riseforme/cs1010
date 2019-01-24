.SILENT: sample_run
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: binary rectangle fibonacci prime sample_run

sample_run:
	./test.sh binary 6
	./test.sh rectangle 4
	./test.sh fibonacci 7
	./test.sh prime 9

# vim:noexpandtab
