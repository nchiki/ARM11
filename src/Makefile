TARGET = src
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC)	$(OBJECTS)	-Wall	$(LIBS)	-o	$@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

test:
	make
	@echo "Make sure arm11_1718_testsuite is cloned in the same directory as arm11_TEAMNUMBER"
	ruby ../../arm11_1718_testsuite/testserver.rb .
