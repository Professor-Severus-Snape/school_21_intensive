#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>  // для NULL

#include "s21_string_test.h"

int main() {
#ifdef Quest_1

    char *str;
    int num_1 = 13, num_2 = -1, num_3 = 0;

    str = "Hello, World!";  // нормальные значения (длина = 13)
    s21_strlen_test(num_1, str);

    str = NULL;  // ненормальные значения
    s21_strlen_test(num_2, str);
    // s21_strlen_test(str);

    str = "";  // краевые значения - например, пустая строка (длина = 0)
    s21_strlen_test(num_3, str);

#endif

#ifdef Quest_2

    char comparison;  // получим знак больше, меньше или равно

    char *str_1;  // первая строка
    char *str_2;  // вторая строка

    str_1 = "Hello, World!";
    str_2 = "Hello, World!";
    comparison = s21_strcmp(str_1, str_2);
    s21_strcmp_test(comparison, str_1, str_2);  // 1-ый тест - нормальные значения (строки равны)

    str_1 = "Hello, World!";
    str_2 = "Hello, School!";
    comparison = s21_strcmp(str_1, str_2);
    s21_strcmp_test(comparison, str_1, str_2);  // 2-ой тест - ненормальные значения (строки не равны)

    str_1 = "Hello, World!";
    str_2 = "";
    comparison = s21_strcmp(str_1, str_2);
    s21_strcmp_test(comparison, str_1, str_2);  // 3-ий тест - краевые значения - пустая строка

#endif

#ifdef Quest_3

    char str_1[20] = "";
    char str_2[20] = "Hello World!";
    char *result_str = s21_strcpy(str_1, str_2);
    s21_strcpy_test(result_str, str_2);  // 1-ый тест ("Hello World!")

    char str_3[20] = "Hello School!";
    result_str = s21_strcpy(str_1, str_3);
    s21_strcpy_test(result_str, str_3);  // 2-ой тест ("Hello School!")

    char str_4[20] = "Hello everybody!";
    result_str = s21_strcpy(str_1, str_4);
    s21_strcpy_test(result_str, str_4);  // 3-ий тест ("Hello everybody!")

#endif

    return 0;
}

void s21_strlen_test(int num, char *str) {
    int length = s21_strlen(str);
    char *result;

    if (length == num) {
        result = "SUCCESS";
    } else {
        result = "FAIL";
    }

    printf("Input_str: %s\nInput_num: %d\nOutput: %d\nResult: %s\n\n", str, num, length,
           result);  // вход - выход - результат !!!
}

void s21_strcmp_test(char comparison, char *str_1, char *str_2) {
    char *result;

    if (s21_strcmp(str_1, str_2) == '=' || s21_strcmp(str_1, str_2) == '>' ||
        s21_strcmp(str_1, str_2) == '<') {
        result = "SUCCESS";
    } else {
        result = "FAIL";
    }

    printf("Input_1: %s\nInput_2: %s\nOutput: %c\nResult: %s\n\n", str_1, str_2, comparison,
           result);  // вход - выход - результат !!!
}

void s21_strcpy_test(char *result_str, char *str_2) {
    char *result;

    if (result_str) {
        result = "SUCCESS";
    } else {
        result = "FAIL";
    }

    printf("Input: %s\nOutput: %s\nResult: %s\n\n", str_2, result_str,
           result);  // вход - выход - результат !!!
}
