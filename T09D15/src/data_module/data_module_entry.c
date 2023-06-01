#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));

        if (data != NULL) {
            input(data, n);  // нужен модуль для input() - data_io.h

            if (normalization(data, n)) {  // нужен модуль для normalization() - data_process.h
                output(data, n);           // нужен модуль для output() - data_io.h
            } else {
                printf("ERROR");
            }

            free(data);

        } else {
            printf("ERROR");
        }
    }

    else {
        printf("ERROR");
    }

    return 0;
}
