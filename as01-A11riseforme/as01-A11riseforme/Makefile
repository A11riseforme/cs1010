.SILENT: test
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: box invest digits taxi test

test:
	./test.sh box 2
	./test.sh invest 4
	./test.sh digits 3
	./test.sh taxi 7

# vim:noexpandtab
