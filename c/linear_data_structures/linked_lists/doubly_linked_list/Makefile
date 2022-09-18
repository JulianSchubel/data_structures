CC=gcc
CFLAGS=-I. -Wall --pedantic
BINARIES=main

all : ${BINARIES}

% : %.c
	${CC} ${CFLAGS} $< -o $@
