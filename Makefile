CC = gcc
CFLAGS=-Wall -g

all: ex22_main

ex22_main: ex22.o 

all: ex22

ex22: ex22.o

clean:
	rm -f ex19
