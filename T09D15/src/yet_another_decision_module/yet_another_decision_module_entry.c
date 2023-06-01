#include <stdio.h>
#include <stdlib.h>  // для malloc()

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));

        if (data != NULL) {
            input(data, n);  // нужен модуль для input() - data_io.h

            if (make_decision(data, n)) {  // нужен модуль для make_decision(() - decision.h
                printf("YES");
            } else {
                printf("NO");
            }

            free(data);
        } else {
            printf("NO");
        }

    } else {
        printf("NO");
    }

    return 0;
}
