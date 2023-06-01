#include "s21_string.h"

#include <stdlib.h>  // для NULL

// функция вычисляющая длину строки:
int s21_strlen(char *str) {
    int length = 0;

    if (str != NULL) {
        for (int i = 0; str[i] != '\0'; i++) {
            length++;
        }
    } else {
        length = -1;
    }

    return length;
}

// функция сравнивающая символы двух строк и возвращающая знак сравнения:
char s21_strcmp(char *str_1, char *str_2) {
    char result = '!';
    int index = 0;

    int length_1 = s21_strlen(str_1);
    int length_2 = s21_strlen(str_2);

    if (length_1 > 0 && length_2 > 0) {
        while (str_1[index] != '\0' && str_2[index] != '\0') {
            if (str_1[index] < str_2[index] || str_1[index] > str_2[index]) {
                if (str_1[index] < str_2[index]) {
                    result = '<';
                } else {
                    result = '>';
                }
                break;
            } else {
                result = '=';
            }

            index++;
        }

    } else if (length_1 > 0 && length_2 == 0) {
        result = '>';
    } else if (length_2 > 0 && length_1 == 0) {
        result = '<';
    } else if (length_1 == 0 && length_2 == 0) {
        result = '=';
    }

    return result;
}

// функция копирующая вторую строку в первую:
char *s21_strcpy(char *str_1, const char *str_2) {
    char *result_str = str_1;

    while (*str_2 != '\0') {
        *str_1 = *str_2;
        str_1++;
        str_2++;
    }

    *str_1 = '\0';

    return result_str;
}
