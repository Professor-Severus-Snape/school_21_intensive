#include "data_stat.h"

// Функция, которая возвращает максимальное значение из элементов массива:
double max(double *data, int n) {
    double maximum = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > maximum) {
            maximum = data[i];
        }
    }
    return maximum;
}

// Функция, которая возвращает минимальное значение из элементов массива:
double min(double *data, int n) {
    double minimum = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < minimum) {
            minimum = data[i];
        }
    }
    return minimum;
}

// Функция, которая возвращает среднее арифметическое из значений элементов массива:
double mean(double *data, int n) {
    double summa = 0.0, average;
    for (int i = 0; i < n; i++) {
        summa += data[i];
    }
    average = summa / n;
    return average;
}

// Функция, которая возвращает дисперсию:
double variance(double *data, int n) {
    double summa = 0.0, var_res, variance;
    for (int i = 0; i < n; i++) {
        summa += data[i] * data[i];
    }
    var_res = mean(data, n) * mean(data, n);
    variance = summa / n - var_res;
    return variance;
}

// сортировка вставками:
void sort(double *data, int n) {
    double tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (data[i] > data[k]) {
                tmp = data[k];
                data[k] = data[i];
                data[i] = tmp;
            }
        }
    }
}
