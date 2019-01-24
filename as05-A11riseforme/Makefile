.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: social life samplerun

samplerun: 
	./test.sh social 4
	#./test.sh life 7

# vim:noexpandtab
