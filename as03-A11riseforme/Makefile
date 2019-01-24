.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: kendall histogram countingsort samplerun

samplerun: 
	./test.sh kendall 4
	./test.sh histogram 5
	./test.sh countingsort 4

# vim:noexpandtab
