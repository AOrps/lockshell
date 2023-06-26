#OBJS = losh.o
SHELL = /bin/sh
CC = gcc
CFLAGS = -g -Wall -pedantic -Og
# Hardening Flags Resources : https://github.com/ossf/wg-best-practices-os-developers/blob/main/docs/Compiler-Hardening-Guides/Compiler-Options-Hardening-Guide-for-C-and-C%2B%2B.md
CFLAGS_HARDEN = -Wall -Wextra -Wformat=2 -Wconversion -Wtrampolines -Werror -O1 -D_FORTIFY_SOURCE=3 -fstack-clash-protection -fstack-protector-strong -Wl,-z,noexecstack -fPIE -pie
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
ifneq (,$(wildcard ./loshh))
	rm ./loshh
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
