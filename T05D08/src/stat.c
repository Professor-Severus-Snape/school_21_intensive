#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

// основная функция:
int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {  // ошибка
        printf("n/a");
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

// Функция, которая принимает на вход данные:
int input(int *a, int *n) {
    char end;
    int flag = 0;
    int flag1 = 1;

    if ((scanf("%d%c", n, &end) == 2) && (end == '\n') && (*n > 0) && (*n < 11)) {
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

// Функция, которая печатает все элементы массива:
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}

// Функция, которая возвращает максимальное значение из элементов массива
int max(int *a, int n) {
    int maximum = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }
    return maximum;
}

// Функция, которая возвращает минимальное значение из элементов массива
int min(int *a, int n) {
    int minimum = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < minimum) {
            minimum = a[i];
        }
    }
    return minimum;
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
    double summa = 0.0, var_res, result;
    for (int i = 0; i < n; i++) {
        summa += a[i] * a[i];
    }
    var_res = mean(a, n) * mean(a, n);
    result = summa / n - var_res;
    return result;
}

// Функция, которая возвращает 4 результата:
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
