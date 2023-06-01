#include "cipher.h"

#include <dirent.h>  // для функций opendir() и readdir()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // для строк - strstr() и strcat()
#define ENG 26  // для шифра Цезаря - используем английский алфавит

int main() {
    int menu_num;
    char *filepath = NULL;

    do {
        get_menu_number(&menu_num);  // считываем пункт меню (1: чтение, 2: запись или -1: выход)

        if (menu_num == 1) {  // открываем файл на чтение

            if (filepath != NULL) {  // если в буфере уже что-то есть, то очищаем его
                free(filepath);
            }
            filepath = get_txt_file_name();  // считываем имя файла, введенное юзером в терминале
            if (filepath == NULL || reader(filepath)) {
                // если не считался путь до файла / не считался сам файл / файл пустой - n/a:
                continue;  // работа программы продолжается - ждем новый пункт меню
            }

        } else if (menu_num == 2) {  // дозапись в конец открытого файла:

            if (filepath == NULL || writer(filepath)) {
                // если что-то пошло не так:
                free(get_txt_file_name());  // очищаем предварительно аллоцированную realloc-ом память

                printf("n/a\n");
                continue;  // работа программы продолжается - ждем новый пункт меню
            }

            reader(filepath);

        } else if (menu_num == 3) {  // шифрование через код Цезаря:

            rewind(stdin);  // очищаем буфер
            int n;
            get_menu_number(&n);  // получаем сдвиг для кода Цезаря из stdin

            if (n != 90) {  // если нет ошибки ввода:

                DIR *dir = opendir("../src/ai_modules/");  // задаем самостоятельно нужную директорию:

                struct dirent *ent;  // создаем элемент структуры - 'ent'

                while ((ent = readdir(dir)) != 0) {  // считываем содержимое директории

                    // для файлов с расширением .c - шифрование:
                    if (strstr(ent->d_name, ".c") != NULL) {  // подстрока в строке (strstr)
                        char temp[1024] = "";
                        strcat(temp, "../src/ai_modules/");
                        strcat(temp, ent->d_name);  // получаем путь к файлу
                        encrypt(n, temp);  // запускаем шифрование кодом Цезаря
                    }

                    // для файлов с расширением .h - очистка:
                    if (strstr(ent->d_name, ".h") != NULL) {
                        char temp[1024] = "";
                        strcat(temp, "../src/ai_modules/");
                        strcat(temp, ent->d_name);

                        FILE *file = NULL;
                        file = fopen(temp,
                                     "w");  // открываем файл на запись - пропадает содержимое автоматически
                        fclose(file);       // закрываем файл
                    }
                }

                closedir(dir);

            } else {
                printf("n/a\n");
            }

        } else if (menu_num == -1) {  // ничего не делаем - на следующую итерацию цикла уже не попадём

            continue;

        } else {  // введен неверный пункт меню
            printf("n/a\n");
        }

    } while (menu_num != -1);

    free(filepath);

    return 0;
}

// 1. Считывание пункта меню:
void get_menu_number(int *menu_num) {
    rewind(stdin);  // очищаем буфер

    char c;

    scanf("%d%c", menu_num, &c);

    if (c != '\n') {
        *menu_num = 90;  // значение наобум, чтобы обозначить ошибку ввода
    }
}

// 2. Считывание имени txt-файла и его возврат:
char *get_txt_file_name() {
    char *filepath = NULL;
    int i = 0;
    char elem;
    // char elem = 'a';  // вымышленное значение по дефолту, чтобы инициализировать переменную

    while (elem != '\n') {  // пока мы не дошли до конца строки, введенной юзером:

        if (scanf("%c", &elem) != EOF) {  // пока мы не дошли до конца файла:

            filepath = (char *)realloc(filepath, (i + 1) * sizeof(char));  // аллоцируем память

            if (filepath == NULL) {  // если память не выделена:
                printf("n/a\n");
                break;
            } else if (elem != '\n') {  // если мы не дошли до конца строки, то продолжаем считывание
                filepath[i] = elem;
                i++;
            } else if (elem == '\n') {  // конец строки - выход из цикла!
                filepath[i] = '\0';
            }
        } else {
            return NULL;
        }
    }

    return filepath;
}

// 3.1 Чтение файла:
int reader(char *filepath) {
    // rewind(stdin);  // очищаем буфер

    int flag = 0;  // TRUE - файл как будто "считался"

    FILE *file = NULL;
    file = fopen(filepath, "r");  // открываем файл на чтение

    if (file == NULL) {  // если файл не считался:
        flag = 1;        // FALSE
    } else {
        if (read_file(file) == 0) {  // если txt-файл пустой:
            flag = 1;                // FALSE
        }

        fclose(file);  // закрываем файл
    }

    return flag;  // возвращаем TRUE или FALSE (т.е. считался файл или нет)
}

// 3.2 Чтение файла - проверка, что файл не пустой:
int read_file(FILE *file) {
    int is_file_empty = 0;  // предположим, что файл пустой
    char text[256];

    while ((fgets(text, 256, file)) != NULL) {
        printf("%s", text);
        is_file_empty++;
    }

    if (is_file_empty) {
        printf("\n");
    }

    return is_file_empty;  // если вернет 0, то файл пустой
}

// 4.1 Дозапись в файл:
int writer(char *filepath) {  // на вход принимает имя txt-файла

    rewind(stdin);  // очищаем буфер

    int flag = 0;  // TRUE - файл как будто "считался"

    FILE *file = NULL;
    file = fopen(filepath, "r+");  // открываем файл на дозапись

    if (file == NULL) {  // если файл не считался:
        flag = 1;        // FALSE
    } else {
        char text[256];

        while ((fgets(text, 256, file)) != NULL) {
            continue;
        }

        write_file(file);
        fclose(file);

        text[0] = 'f';  // значение наобум
    }

    return flag;
}

// 4.2 Дозапись в файл - принимает строку из stdin и записывает ее в конец файла:
void write_file(FILE *file) {
    char *input;

    input = get_txt_file_name();

    if (input != NULL) {
        fputs(input, file);
    }

    free(input);  // чистим аллоцированную realloc-ом память
}

// 5.1 Цезарь:
void encrypt(int n, char *filepath) {
    FILE *file_1 = NULL;
    FILE *file_2 = NULL;

    file_1 = fopen(filepath, "r");
    file_2 = fopen(filepath, "r+");

    int flag;
    char c;
    c = getc(file_1);

    while (!feof(file_1)) {
        flag = 0;
        get_new_symbol(file_2, &flag, c, n);
        c = getc(file_1);
    }

    fclose(file_1);  // закрываем первый файл
    fclose(file_2);  // закрываем второй файл
}

// 5.2 Цезарь - шифрование:
void get_new_symbol(FILE *file, int *flag, char c, int n) {
    if (c >= 'A' && c <= 'Z') {
        c = c + (n % ENG);

        if (c > 'Z') {
            c = 'A' + (c - 'Z') - 1;
        }

        fputc(c, file);
        *flag = 1;
    }

    if (c >= 'a' && c <= 'z') {
        c = c + (n % ENG);
        if (c > 'z') {
            c = 'a' + (c - 'z') - 1;
        }

        fputc(c, file);
        *flag = 1;
    }

    if (!*flag) {
        fputc(c, file);
    }
}
