FLAGS = -Wall -Werror -Wextra

QUEST_1 = ../build/Quest_1
QUEST_2 = ../build/Quest_2

.PHONY: all clean rebuild door_struct list_test

all: door_struct list_test

# первый квест:
door_struct:
	gcc $(FLAGS) dmanager_module.c -o $(QUEST_1)

# второй квест:
list_test:
	gcc $(FLAGS) list_test.c list.c -o $(QUEST_2)

clean: 
	rm -rf $(QUEST_1)
	rm -rf $(QUEST_2)

rebuild: clean all
