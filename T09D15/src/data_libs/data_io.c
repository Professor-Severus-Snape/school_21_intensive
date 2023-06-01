#include "data_io.h"

#include <stdio.h>

// Функция, которая принимает на вход данные и заполняет массив:
void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}

// Функция, которая печатает все элементы массива с точностью 2 знака после запятой:
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}
