# Luiz Fernando Azevedo Vasconcellos GRR20171629
# lfav17@inf.ufpr.br

CC = gcc
CFLAGS = -Wall

OBJS = ortografia.o dicionario.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o ortografia $(OBJS) 

%.o : %.c dicionario.h
	$(CC) -c $< $(CFLAGS)

clean:
	-rm -f *.o

purge: clean
	-rm -f ortografia

compress:
	tar -cvzf projeto_02.tar.gz ortografia.c dicionario.c dicionario.h Makefile
