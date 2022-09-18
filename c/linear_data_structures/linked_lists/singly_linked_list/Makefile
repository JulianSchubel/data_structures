CC=gcc
CFLAGS=-I. -Wall -Wextra -std=c99 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3
BINARIES=main

all : ${BINARIES}

% : %.c
	${CC} ${CFLAGS} $< -o $@
