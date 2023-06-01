#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *shift);
void cycle_shift(int *a, int n, int shift);
void output(int *a, int n);

int main() {
    int data_1[NMAX], n, shift = 0;
    if (input(data_1, &n, &shift) == 0) {
        cycle_shift(data_1, n, shift);
        output(data_1, n);
    } else {
        printf("n/a");
    }
    return 0;
}

// Функция, проверяющая корректность ввода:
int input(int *a, int *n, int *shift) {
    char end;
    int flag = 1;  // ошибка
    if ((scanf("%d%c", n, &end) == 2) && (end == '\n') && (*n > 0) && (*n <= NMAX)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &a[i], &end) == 2 && (end == ' ' || end == '\n')) {
                if (end == '\n' && i == *n - 1) {
                    if ((scanf("%d%c", shift, &end) == 2) && (end == '\n')) {
                        flag = 0;
                    } else {
                        break;
                    }
                } else if (end == '\n' && i != *n - 1) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return flag;
}

// Функция, осуществляющая циклический сдвиг:
void cycle_shift(int *a, int n, int shift) {
    if (shift < 0) {
        shift = n - shift;
    }
    shift = shift % n;
    for (int i = 0; i < shift; i++) {
        int tmp = a[0];
        for (int k = 0; k < n; k++) {
            if (k == n - 1) {
                a[k] = tmp;
            } else {
                a[k] = a[k + 1];
            }
        }
    }
}

// Функция, осуществляющая вывод информации в stdout:
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}
