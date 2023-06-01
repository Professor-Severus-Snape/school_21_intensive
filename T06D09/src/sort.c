#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int data[NMAX];
    if (input(data) == 0) {
        sort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    char end;
    int counter = 0;
    int flag = 1;  // ошибка

    for (int i = 0; i < NMAX - 1; i++) {
        if (scanf("%d%c", &a[i], &end) == 2 && end == ' ') {
            counter += 1;
        } else {
            break;
        }
    }

    if (counter == (NMAX - 1) && scanf("%d%c", &a[NMAX - 1], &end) == 2 && end == '\n') {
        counter += 1;
    }

    if (counter == NMAX) {
        flag = 0;
    }

    return flag;
}

// сортировка вставками:
void sort(int *a) {
    int tmp;
    for (int i = 0; i < NMAX - 1; i++) {
        for (int k = i + 1; k < NMAX; k++) {
            if (a[i] > a[k]) {
                tmp = a[k];
                a[k] = a[i];
                a[i] = tmp;
            }
        }
    }
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d", a[i]);
        if (i != (NMAX - 1)) {
            printf(" ");
        }
    }
}
