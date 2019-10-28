all: linkedlist.o
	gcc -o program linkedlist.o

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

run:
	./program