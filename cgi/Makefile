SOURCES=main.o ../src/disasm.o ../src/exec.o ../src/alpha.o ../src/util.o platform.o ../src/ports.o
HEADERS=../src/disasm.h ../src/alpha.h ../src/platform.h ../src/exec.h ../src/util.h ../src/ports.h
CFLAGS=-I../src -O3 -std=gnu99
CXXFLAGS=-I../src -O3
alpha.cgi: $(SOURCES) $(HEADERS) Makefile
	g++ $(SOURCES) -O3 -o alpha.cgi
all: alpha.cgi Makefile
install: alpha.cgi
	cp alpha.cgi /srv/http/cgi-bin/alpha.cgi
clean:
	rm -f *.o *~ alpha.cgi a.out 
