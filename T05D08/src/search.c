/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
void output(int *a, int n);

// основная функция:
int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {  // ошибка
        printf("n/a");
    } else {
        output(data, n);
    }
    return 0;
}

// Функция, которая принимает на вход данные:
int input(int *a, int *n) {
    char end;
    int flag = 0;
    int flag1 = 1;

    if ((scanf("%d%c", n, &end) == 2) && (end == '\n') && (*n > 0) && (*n < 31)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &a[i], &end) == 2 && (end == ' ' || end == '\n')) {
                if (end == '\n' && i == *n - 1) {
                    flag1 = 0;
                } else if (end == '\n' && i != *n - 1) {
                    break;
                }

            } else {
                flag = 1;
            }
        }
        if (flag1 == 1) {
            flag = 1;  // ошибка
        }

    } else {
        flag = 1;  // ошибка
    }

    return flag;
}

// Функция, которая возвращает среднее арифметическое из значений элементов массива
double mean(int *a, int n) {
    double summa = 0.0, average;
    for (int i = 0; i < n; i++) {
        summa += a[i];
    }
    average = summa / n;
    return average;
}

// Функция, которая возвращает дисперсию:
double variance(int *a, int n) {
    double summa = 0.0, var_res, variance;
    for (int i = 0; i < n; i++) {
        summa += a[i] * a[i];
    }
    var_res = mean(a, n) * mean(a, n);
    variance = summa / n - var_res;
    return variance;
}

void output(int *a, int n) {
    int result = 0;
    double average, sigma;

    average = mean(a, n);
    sigma = sqrt(variance(a, n)) * 3.0;

    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= average) && (a[i] <= average + sigma) && (a[i] != 0)) {
            result = a[i];
            break;
        }
    }
    printf("%d", result);
}
