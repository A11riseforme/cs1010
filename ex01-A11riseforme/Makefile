CC=clang
LIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: freezer1 freezer2 test

freezer1: freezer1.c 
	$(CC) $(CFLAGS) freezer1.c $(LIBS) -o freezer1

freezer2: freezer2.c 
	$(CC) $(CFLAGS) freezer2.c $(LIBS) -o freezer2

test:
	./test.sh freezer1 3
	./test.sh freezer2 3

# vim:noexpandtab
