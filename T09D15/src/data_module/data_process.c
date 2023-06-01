#include "data_process.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);  // нужен модуль для max() - data_stat.h
    double min_value = min(data, n);  // нужен модуль для min() - data_stat.h
    double size = max_value - min_value;

    if (fabs(size) > EPS) {  // по сути проверка деления на ноль
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }

    return result;
}
