FLAGS = -Wall -Werror -Wextra

PATH_1 = ../data_libs/
PATH_2 = ../data_module/
PATH_3 = ../yet_another_decision_module/
PATH_4 = ../../build/

DATA_IO_C = $(PATH_1)data_io.c
DATA_IO_H = $(PATH_1)data_io.h

DATA_STAT_C = $(PATH_1)data_stat.c
DATA_STAT_H = $(PATH_1)data_stat.h

DATA_PROCESS_C = $(PATH_2)data_process.c
DATA_PROCESS_H = $(PATH_2)data_process.h

DECISION_C = $(PATH_3)decision.c
DECISION_H = $(PATH_3)decision.h

MAIN_EXECUTABLE_MODULE_C = main_executable_module.c

QUEST_3 = $(PATH_4)Quest_3
QUEST_5 = $(PATH_4)Quest_5
QUEST_6 = $(PATH_4)Quest_6

.PHONY: all clean rebuild uninstall

all: $(QUEST_3)

$(QUEST_3): main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	gcc $(FLAGS) main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o $(QUEST_3)

# создание статической библиотеки:
build_with_static: main_executable_module.o data_io.o data_stat.a data_process.o decision.o
	gcc $(FLAGS) main_executable_module.o data_io.o data_stat.a data_process.o decision.o -o $(QUEST_5)

data_io.o: $(DATA_IO_C) $(DATA_IO_H)
	gcc $(FLAGS) -c $(DATA_IO_C)

data_stat.o: $(DATA_STAT_C) $(DATA_STAT_H)
	gcc $(FLAGS) -c $(DATA_STAT_C)

# создание статической библиотеки:
data_stat.a: data_stat.o
	ar rc data_stat.a data_stat.o
	ranlib data_stat.a

data_process.o: $(DATA_PROCESS_C) $(DATA_PROCESS_H)
	gcc $(FLAGS) -c $(DATA_PROCESS_C)

decision.o: $(DECISION_C) $(DECISION_H)
	gcc $(FLAGS) -c $(DECISION_C)

main_executable_module.o: $(MAIN_EXECUTABLE_MODULE_C)
	gcc $(FLAGS) -c $(MAIN_EXECUTABLE_MODULE_C)

# создание динамической библиотеки:
data_process.so: $(DATA_PROCESS_C)
	gcc -Wall -fPIC -c $(DATA_PROCESS_C) $(DATA_STAT_C)
	gcc -shared -o data_process.so data_process.o data_stat.o

# создание динамической библиотеки:
build_with_dynamic: data_io.o data_stat.o data_process.so decision.o main_executable_module.o
	gcc data_io.o data_stat.o data_process.so decision.o main_executable_module.o -o $(QUEST_6)

clean:
	rm -f *.o *.a *.so

rebuild: uninstall all

uninstall:
	rm -rf $(QUEST_3)
