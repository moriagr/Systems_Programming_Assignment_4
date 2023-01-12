AR=ar
CC=gcc
FLAGS= -Wall -g

all:	graph libGraph.a

graph:	main.o libGraph.a
	$(CC) $(FLAGS) -o graph main.o libGraph.a -lm

libGraph.a:	graph.o
	$(AR) -rcs libGraph.a graph.o

graph.o:	graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

main.o:	main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.txt graph
