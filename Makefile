CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
CFILES = helloWorld.c helloWorld.h

all:
	$(CC) $(LDFLAGS) -o helloWorld $(CFLAGS) $(CFILES) main.c

lib:
	$(CC) -fPIC -c $(CFLAGS) $(CFILES)
	$(CC) -shared -o helloWorld.so *.o

clean:
	rm -f *.o helloWorld *.so *.gch
