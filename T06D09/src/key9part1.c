#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *b, int length, int summa);
int sum_numbers(int *a, int n);
int find_length(int *a, int n, int summa, int *b);

int main() {
    int data_1[NMAX], n;
    if (input(data_1, &n) == 0) {
        int data_2[NMAX];
        int summa = sum_numbers(data_1, n);  // сумма четных чисел первого массива = 8
        int length = find_length(data_1, n, summa, data_2);  // длина нового массива = 5
        output(data_2, length, summa);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char end;
    int flag = 1;  // ошибка
    if ((scanf("%d%c", n, &end) == 2) && (end == '\n') && (*n > 0) && (*n <= NMAX)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &a[i], &end) == 2 && (end == ' ' || end == '\n')) {
                if (end == '\n' && i == *n - 1) {
                    flag = 0;
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

// Функция, которая находит сумму четных элементов с 0-й позиции:
int sum_numbers(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }
    return sum;
}

//  Функция которая находит длину нового массива и заполняет массив данными:
int find_length(int *a, int n, int summa, int *b) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (summa % a[i] == 0) {
                b[k] = a[i];
                k++;
            }
        }
    }
    return k;
}

//  Функция выводящая на экран результат работы:
void output(int *b, int length, int summa) {
    printf("%d\n", summa);
    for (int i = 0; i < length; i++) {
        printf("%d", b[i]);
        if (i != (length - 1)) {
            printf(" ");
        }
    }
}
