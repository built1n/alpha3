SOURCES=alpha.o platform.o exec.o main.o util.o
HEADERS=alpha.h exec.h platform.h util.o
CFLAGS=-I. -O2 -std=gnu99
all: $(SOURCES) $(HEADERS) Makefile
	g++ $(SOURCES) -O3 -o alpha
clean:
	rm -f $(SOURCES) alpha *~ a.out
