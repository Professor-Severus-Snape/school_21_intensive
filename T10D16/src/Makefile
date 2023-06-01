FLAGS = -Wall -Werror -Wextra
PATH_1 = ../build/

QUEST_1 = $(PATH_1)Quest_1
QUEST_2 = $(PATH_1)Quest_2
QUEST_3 = $(PATH_1)Quest_3

.PHONY: all clean rebuild strlen_tests strcmp_tests strcpy_tests

all: strlen_tests strcmp_tests strcpy_tests
# 	rm -f *.o  # по идее не нужно 

strlen_tests:
	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_1) -D Quest_1

strcmp_tests:
	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_2) -D Quest_2

strcpy_tests:
	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_3) -D Quest_3

# 2-ой вариант:
# strlen_tests: $(QUEST_1)
# strcmp_tests: $(QUEST_2)
# strcpy_tests: $(QUEST_3)

# $(QUEST_1):
# 	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_1) -D Quest_1

# $(QUEST_2):
# 	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_2) -D Quest_2

# $(QUEST_3):
# 	gcc $(FLAGS) s21_string.c s21_string_test.c -o $(QUEST_3) -D Quest_3

clean:
	rm -rf $(QUEST_1)
	rm -rf $(QUEST_2)
	rm -rf $(QUEST_3)

rebuild: clean all
