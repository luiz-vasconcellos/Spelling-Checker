CC=gcc
CFLAGS=-Wall

all: ortografia.o dicionario.o
	$(CC) ortografia.o dicionario.o -o ortografia $(CFLAGS)

ortografia.o: ortografia.c dicionario.h
	$(CC) -c ortografia.c $(CFLAGS)

dicionario.o: dicionario.c dicionario.h
	$(CC) -c dicionario.c $(CFLAGS)

clean:
	-rm -f *.o

purge: clean
	-rm -f ortografia

compress:
	tar -cvzf projeto_02.tar.gz ortografia.c dicionario.c dicionario.h Makefile
