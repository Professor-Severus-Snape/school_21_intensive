#include <stdio.h>

#ifndef SRC_CIPHER_H
#define SRC_CIPHER_H

void get_menu_number(int *menu_num);  // 1. Считывание пункта меню
char *get_txt_file_name();  // 2. Считывание имени txt-файла и его возврат

int reader(char *filepath);  // 3.1 Открытие файла на чтение
int read_file(FILE *file);   // 3.2 Чтение - проверка файла на пустоту

int writer(char *filepath);   // 4.1 Открытие файла на дозапись
void write_file(FILE *file);  // 4.2 Дозапись в файл

void encrypt(int n, char *filepath);                         // 5.1 Цезарь
void get_new_symbol(FILE *file2, int *flag, char c, int n);  // 5.2 Цезарь

#endif
