#CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_BSD_SOURCE -D_DEFAULT_SOURCE -std=c99

TETRIS_SOURCES = tetrisMain.c $(wildcard tetris/*.c)
TETRIS_OBJECTS = tetrisMain.o $(TETRIS_SOURCES:.c=.o)

.SUFFIXES: .c .o

.PHONY: all clean

all: tetris

tetris: $(TETRIS_OBJECTS)



clean:
	rm -f $(TETRIS_OBJECTS)
	rm -f tetris	rm -f out


gdb-tetris:
	make
	gdb tetrisMain
