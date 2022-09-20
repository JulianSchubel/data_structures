CC=gcc
CFLAGS=-g -Wall -Wextra --pedantic
BINARIES=generic_tree

all : ${BINARIES}

% : %.c
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm ${BINARIES}
