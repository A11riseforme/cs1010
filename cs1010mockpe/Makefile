.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: savings_one savings_two savings_three crcx samplerun

samplerun:
	./test.sh savings_one 5
	./test.sh savings_two 5
	./test.sh savings_three 5
	./test.sh crcx 5

# vim:noexpandtab

