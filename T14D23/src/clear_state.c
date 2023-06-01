#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "state_sort.h"

int get_date_state(int *day, int *month, int *year, int *error);
struct my_struct input_bound_from_cmd();
int compare_two_record_short(struct my_struct *record1, struct my_struct *record2);

int main() {
    char *filename = input_from_user();
    if (filename == NULL) {
        printf("n/a");
        free(filename);
        return 0;
    }

    int error = 0;
    FILE *old_file = file_init(filename, &error);
    if (error) {
        printf("n/a");
        free(filename);
        return 0;
    }

    struct my_struct before = input_bound_from_cmd();
    struct my_struct after = input_bound_from_cmd();

    int records_count = get_records_count_in_file(old_file);
    int flag, index = 0;
    sort(old_file);

    for (int i = 0; i < records_count; i++) {
        flag = 0;
        struct my_struct old_record = read_record_from_file(old_file, i);
        if (compare_two_record_short(&old_record, &before) == 0) {
            flag = 1;
        } else if (compare_two_record_short(&after, &old_record) == 0) {
            flag = 1;
        }

        if (flag) {
            index++;
        } else {
        }
    }

    if (error) {
        printf("n/a");
    }

    file_close(old_file);
    free(filename);
    return 0;
}


int get_date_state(int *day, int *month, int *year, int *error) {
    if (scanf("%d.%d.%d", day, month, year) == 3) {
        if ((*day >=1 && *day <=31) && (*month >=1 && *month <=12) && (*year >=0 && *year <=2022)) {
        } else {
            *error = 1;
        }
    } else {
        *error = 1;
    }
    return *error;
}


/**
 * Функция чтения записи заданного типа из файла по ее порядковому номеру.
 * @param pfile указатель на открытый поток
 * @param index порядковый номер записи
*/
struct my_struct read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, по которому искомая запись должна располагаться от начала файла.
    int offset = index * sizeof(struct my_struct);
    // Перемещение указателя позиции на вычисленное смещение от начала файла
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    // В целялх безопасности возвращаем указатель позиции файла в начало файла
    rewind(pfile);

    // Возвращаем прочитанную запись
    return record;
}


/**
 * Функция внесения записи указанного типа в файл по указанному индексу
 * @param pfile указатель на открытый поток
 * @param record_to_write запись для чтения
 * @param index индекс, куда нужно вставить
*/
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    // Вычисление смещения, по которому искомая запись должна располагаться от начала файла.
    int offset = index * sizeof(struct my_struct);
    // Перемещение указателя позиции на вычисленное смещение от начала файла
    fseek(pfile, offset, SEEK_SET);

    // Внести запись указанного типа в файл
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);

    // На всякий случай заставляем подсистему ввода-вывода прямо сейчас записать содержимое буфера в файл
    fflush(pfile);

    // В целялх безопасности возвращаем указатель позиции файла в начало файла
    rewind(pfile);
}


/**
 * Функция взаимного переноса двух записей в файле по их индексам.
 * @param pfile указатель на открытый поток
 * @param record_index1 индекс первого файла
 * @param record_index2 индекс второго файла
*/
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Прочитать обе записи из файла в переменные
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    // Переписать записи в файл
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}


/**
 * Функция для получения размера файла в байтах.
 * @param pfile указатель на открытый поток
*/
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Переместите указатель позиции в конец файла.
    size = ftell(pfile);  // Прочитать количество байтов от начала файла до указателя текущей позиции.
    rewind(pfile);  // Из соображений безопасности переместите указатель в обратное начало файла.
    return size;
}


/**
 * Функция для получения количества записей в файле
 * @param pfile указатель на открытый поток
*/
int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}


FILE* file_init(char *filename, int *error) {
    FILE* fp;
    if ((fp = fopen(filename, "r+b")) == NULL) {
        *error = 1;
    }
    return fp;
}


void file_close(FILE* log_file) {
    fclose(log_file);
}


/**
 * Функция считывает с консоли строку от пользователя
 * @return указатель на стоку, если что-то ввели.
 * @return NULL, если ничего не ввели и просто нажали enter.
*/
char* input_from_user() {
    char *file_path = NULL;
    int i = 0;
    char elem;
    while (elem != '\n') {
        if (scanf("%c", &elem) != EOF) {
            file_path = (char *)realloc(file_path, (i + 1) * sizeof(char));
            if (file_path == NULL) {
                printf("n/a\n");
            } else if (elem != '\n') {
                file_path[i] = elem;
                i++;
            } else if (elem == '\n') {
                file_path[i] = '\0';
            }
        } else {
            return NULL;
        }
    }
    return file_path;
}


void output_file(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile);
    for (int i = 0; i < records_count; i++) {
        struct my_struct record = read_record_from_file(pfile, i);
        printf("%d ", record.year);
        printf("%d ", record.month);
        printf("%d ", record.day);
        printf("%d ", record.hour);
        printf("%d ", record.minutes);
        printf("%d ", record.seconds);
        printf("%d ", record.status);
        printf("%d\n", record.code);
    }
}


/**
 * Функция сравнивает два числа
 * @param num1 первое число
 * @param num2 второе число
 * @return 0, если числа равны или первое меньше второго; 1, если первое число больше второго
*/
int compare_two_num(int num1, int num2) {
    if (num1 > num2) {
        return 1;
    } else if (num1 == num2) {
        return 0;
    }
    return -1;
}


/**
 * Функция сравнивает две записи в файле по строке
 * @param record1 первая запись
 * @param record2 вторая запись
 * @return 0, если записи идентичны или первая запись меньше второй; 1, если первая запись больше второй
*/
int compare_two_record(struct my_struct *record1, struct my_struct *record2) {
    if (compare_two_num(record1 -> year, record2 -> year) == 1) {
        return 1;
    } else if (compare_two_num(record1 -> year, record2 -> year) == 0) {
        if (compare_two_num(record1 -> month, record2 -> month) == 1) {
            return 1;
        } else if (compare_two_num(record1 -> month, record2 -> month) == 0) {
            if (compare_two_num(record1 -> day, record2 -> day) == 1) {
                return 1;
            } else if (compare_two_num(record1 -> day, record2 -> day) == 0) {
                if (compare_two_num(record1 -> hour, record2 -> hour) == 1) {
                    return 1;
                } else if (compare_two_num(record1 -> hour, record2 -> hour) == 0) {
                    if (compare_two_num(record1 -> minutes, record2 -> minutes) == 1) {
                        return 1;
                    } else if (compare_two_num(record1 -> minutes, record2 -> minutes) == 0) {
                        if (compare_two_num(record1 -> seconds, record2 -> seconds) == 1) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


/**
 * Функция сравнивает две записи в файле по строке
 * @param record1 первая запись
 * @param record2 вторая запись
 * @return 0, если записи идентичны или первая запись меньше второй; 1, если первая запись больше второй
*/
int compare_two_record_short(struct my_struct *record1, struct my_struct *record2) {
    if (compare_two_num(record1 -> year, record2 -> year) == 1) {
        return 1;
    } else if (compare_two_num(record1 -> year, record2 -> year) == 0) {
        if (compare_two_num(record1 -> month, record2 -> month) == 1) {
            return 1;
        } else if (compare_two_num(record1 -> month, record2 -> month) == 0) {
            if (compare_two_num(record1 -> day, record2 -> day) == 1) {
                return 1;
            } else if (compare_two_num(record1 -> day, record2 -> day) == 0) {
                return 1;
            }
        }
    }
    return 0;
}


void sort(FILE *pfile) {
    int is_equal = 1;
    int records_count = get_records_count_in_file(pfile);
    while (is_equal) {
        is_equal = 0;
        for (int i = 0; i < records_count - 1; i++) {
            struct my_struct record1 = read_record_from_file(pfile, i);
            struct my_struct record2 = read_record_from_file(pfile, i + 1);
            if (compare_two_record(&record1, &record2) == 1) {
                swap_records_in_file(pfile, i, i + 1);
                is_equal = 1;
            }
        }
    }
}


struct my_struct input_bound_from_cmd() {
    struct my_struct input;
    scanf("%d.%d.%d", &input.day, &input.month, &input.year);
    if (input.year <= 0 || input.year > 2022) {
        printf("n/a");
        exit(0);
    }

    if (input.month <= 0 || input.month > 12) {
        printf("n/a");
        exit(0);
    }

    if (input.day <= 0 || input.day > 31) {
        printf("n/a");
        exit(0);
    }

    return input;
}
