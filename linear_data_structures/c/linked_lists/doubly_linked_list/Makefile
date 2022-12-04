CC=gcc
CFLAGS=-I. -Wall --pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -Wextra
BINARIES=main

all : ${BINARIES}

% : %.c
	${CC} ${CFLAGS} $< -o $@
