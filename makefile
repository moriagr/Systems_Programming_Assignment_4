#CC = gcc
#AR = ar
#FLAGS = -Wall -g
#OBJECTS = main.o nodes.o algo.o edges.o

#all: graph

#algo.o: algo.c algo.h nodes.h
#	$(CC) $(FLAGS) -c algo.c
#
#edges.o: edges.c edges.h nodes.h
#	$(CC) $(FLAGS) -c edges.c
#
#nodes.o: nodes.c nodes.h
#	$(CC) $(FLAGS) -c nodes.c
#
#main.o: main.c algo.h
#	$(CC) $(FLAGS) -c main.c
#
#graph: $(OBJECTS)
#	$(CC) $(FLAGS) -o graph $(OBJECTS)
#
#.PHONY: clean all
#
#clean:
#	rm -f *.o *.a graph



AR=ar
CC=gcc
FLAGS= -Wall -g

all:	graph libGraph.a

graph:	main.o libGraph.a
	$(CC) $(FLAGS) -o graph main.o libGraph.a -lm

libGraph.a:	graph.o
	$(AR) -rcs libGraph.a graph.o

#libEdges.a:	main.o
#	$(AR) -rcs libEdges.a edges.o
graph.o:	graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

main.o:	main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a graph
