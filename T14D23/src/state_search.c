#include <stdio.h>
#include <stdlib.h>
#include "state_sort.h"


int main() {
    char *filename = input_from_user();
    if (filename == NULL) {
        printf("n/a");
        free(filename);
        return 0;
    }

    int error = 0;
    FILE *pfile = file_init(filename, &error);
    if (error) {
        printf("n/a");
        free(filename);
        return 0;
    }

    int day, month, year;
    error = 0;

    get_date(&day, &month, &year, &error, pfile);
    if (error) {
        printf("n/a");
    }

    file_close(pfile);
    free(filename);
    return 0;
}


int get_date(int *day, int *month, int *year, int *error, FILE *pfile) {
    if (scanf("%d.%d.%d", day, month, year) == 3) {
        if ((*day >= 1 && *day <= 31) && (*month >= 1 && *month <= 12) && (*year >= 0 && *year <= 2022)) {
            int records_count = get_records_count_in_file(pfile);
            for (int i = 0; i < records_count; i++) {
                struct my_struct record = read_record_from_file(pfile, i);
                if (record.day == *day && record.month == *month && record.year == *year) {
                    printf("%d", record.code);
                }
            }
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

