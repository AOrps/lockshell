#OBJS = losh.o
SHELL = /bin/sh
CC = gcc
CFLAGS = -g -Wall -pedantic -Og
CFLAGS_HARDEN = -Wall -Wextra -Wformat=2 -Wconversion -Wtrampolines
PROGS = losh

all: $(PROGS)

losh: clean
	$(CC) $(CFLAGS) lockshell.c -o losh

harden: clean
	$(CC) $(CFLAGS_HARDEN) lockshell.c -o loshh

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
