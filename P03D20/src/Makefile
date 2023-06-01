CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak

GRAPH = ../build/graph

.PHONY: all clean rebuild graph

all: graph

rebuild: clean all

graph: graph.c polska_parcer.c polish_calc.c polska_parcer.h polish_calc.h structure_lib
	$(CC) $(FLAGS) -c graph.c polska_parcer.c polish_calc.c
	$(CC) $(FLAGS) graph.o polska_parcer.o polish_calc.o structure_lib.a -o $(GRAPH)

structure_lib: structure_lib.o
	ar rc structure_lib.a structure_for_polish.o

structure_lib.o: structure_for_polish.c structure_for_polish.h
	$(CC) $(FLAGS) -c structure_for_polish.c

clean:
	rm *.o
	rm *.a
	rm $(GRAPH)