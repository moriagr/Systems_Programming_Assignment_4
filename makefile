# AR=ar
# CC=gcc
# FLAGS= -Wall -g

# all:	txtfind isort libSort.a libFind.a

# isort:	isort.o libSort.a
# 	$(CC) $(FLAGS) -o isort isort.o libSort.a -lm

# txtfind:	txtfind.o libFind.a
# 	$(CC) $(FLAGS) -o txtfind txtfind.o libFind.a -lm

# libSort.a:	isort.o
# 	$(AR) -rcs libSort.a isort.o

# libFind.a:	txtfind.o
# 	$(AR) -rcs libFind.a txtfind.o

# isort.o:	isort.c main.h
# 	$(CC) $(FLAGS) -c isort.c

# txtfind.o:	txtfind.c main.h
# 	$(CC) $(FLAGS) -c txtfind.c

# .PHONY: clean all

# clean:
# 	rm -f *.o *.a isort txtfind
