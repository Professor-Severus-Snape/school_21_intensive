#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    char end;
    int flag = 1; // ошибка

    if ((scanf("%d%c", n, &end) == 2) && (end == '\n') && (*n > 0) && (*n < 11)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &a[i], &end) == 2 && (end == ' ' || end == '\n')) {
                if (end == '\n' && i == *n - 1) {
                    flag = 0;
                } else if (end == '\n' && i != *n - 1) {
                    break;
                }

            } 
        }
    } 

    return flag;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
