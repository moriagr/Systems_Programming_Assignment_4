AR=ar
CC=gcc
FLAGS= -Wall -g

all:	graph libGraph.a

graph:	main.o libGraph.a
	$(CC) $(FLAGS) -o graph main.o libGraph.a -lm

libGraph.a:	main.o
	$(AR) -rcs libGraph.a main.o

main.o:	main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a graph
