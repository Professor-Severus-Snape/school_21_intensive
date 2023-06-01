FLAGS = -Wall -Werror -Wextra

rebuild: clean all

clean:
	rm -rf ../build/Quest_1 ../build/Quest_2 ../build/Quest_3

all: state_sort state_search clear_state

state_sort:
	gcc $(FLAGS) -c state_sort.c
	gcc $(FLAGS) -o ../build/Quest_1 state_sort.o
	rm -rf *.o

state_search:
	gcc $(FLAGS) -c state_search.c
	gcc $(FLAGS) -o ../build/Quest_2 state_search.o
	rm -rf *.o

clear_state:
	gcc $(FLAGS) -c clear_state.c
	gcc $(FLAGS) -o ../build/Quest_3 clear_state.o
	rm -rf *.o
