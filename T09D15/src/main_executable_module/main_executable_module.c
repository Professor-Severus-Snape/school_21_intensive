#include <stdio.h>
#include <stdlib.h>  // подключаем модуль для malloc()

#include "../data_libs/data_io.h"         // подключаем модуль для input() и output()
#include "../data_libs/data_stat.h"       // подключаем модуль для sort()
#include "../data_module/data_process.h"  // подключаем модуль для normalization()
#include "../yet_another_decision_module/decision.h"  // подключаем модуль для make_decision()

//#include "data_process.so"  // подключаем динамическую библиотеку - ???

int main() {
    double *data;
    int n;

    printf("LOAD DATA...\n");

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));

        if (data != NULL) {
            input(data, n);  // нужен модуль для input() - data_io.h

            printf("RAW DATA:\n\t");
            output(data, n);  // нужен модуль для output() - data_io.h

            printf("\nNORMALIZED DATA:\n\t");
            normalization(data, n);  // нужен модуль для normalization() - data_process.h
            output(data, n);

            printf("\nSORTED NORMALIZED DATA:\n\t");
            sort(data, n);  // нужен модуль для sort() - data_stat.h
            output(data, n);

            printf("\nFINAL DECISION:\n\t");

            if (make_decision(data, n))  // нужен модуль для make_decision() - decision.h
                printf("YES");
            else
                printf("NO");

            free(data);

        } else {
            printf("NO");
        }

    } else {
        printf("NO");
    }

    return 0;
}
