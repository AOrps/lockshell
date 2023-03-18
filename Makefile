#OBJS = losh.o
SHELL = /bin/sh
CC = gcc
CFLAGS = -g -Wall -pedantic -Og
PROGS = losh

all: $(PROGS)

losh:
	$(CC) $(CFLAGS) lockshell.c -o losh

clean:
ifneq (,$(wildcard ./losh))
	rm ./losh
endif
ifneq (,$(wildcard ./a.out))
	rm ./a.out
endif
ifneq (,$(wildcard *.o))
	rm *.o
endif
ifneq (,$(wildcard *~))
	rm *~
endif
