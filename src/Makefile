SOURCES=alpha.o platform.o exec.o main.o util.o ports.o disasm.o
HEADERS=alpha.h exec.h platform.h util.h disasm.h exec_table.h disasm_table.h
CFLAGS=-I. -O3 -std=gnu99 -Wall
CXXFLAGS=-I. -Wall -O3 -Wall
all: $(SOURCES) $(HEADERS) Makefile
	g++ $(SOURCES) -O3 -o alpha
clean:
	rm -f $(SOURCES) alpha *~ a.out libalpha.so
library:
	g++ $(SOURCES) -O3 -shared -o libalpha.so
