CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
CFILES += htu21Utils.c htu21Utils.h


all:
	$(CC) $(LDFLAGS) -o getMeteo $(CFLAGS) $(CFILES) main.c -li2c

lib:
	$(CC) -fPIC -c $(CFLAGS) $(CFILES)
	$(CC) -shared -o getMeteo.so *.o

clean:
	rm -f *.o getMeteo *.so *.gch
