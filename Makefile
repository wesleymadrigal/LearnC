CC = gcc
CFLAGS=-Wall -g

#clean:
#	rm -f ex1

all:
	make ex1
	make ex3
	make ex4
	make ex5

clean:
	rm -f ex1
	rm -f ex3
	rm -f ex5
