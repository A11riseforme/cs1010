.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -Wdocumentation -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: digits samplerun

samplerun:
	./test.sh digits 6 1
	./test.sh digits 100 30
	./test.sh digits 60000 30
	./test.sh digits 100 10000

clean:
	rm digits
# vim:noexpandtab
