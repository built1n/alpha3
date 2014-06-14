SOURCES=main.o
HEADERS=opcodes.h
CXXFLAGS=-I. -I../src
alpha-asm: $(SOURCES) $(HEADERS)
	g++ $(SOURCES) -I. -I../src/ -o alpha-asm
clean:
	rm -f alpha-asm *~ *.o
