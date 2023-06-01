#include <stdio.h>

int prost(int x);
int div(int x, int y);

int main(void) {
    int x, tmp = 1;
    char c;

    if (scanf("%d%c", &x, &c) == 2 && c == '\n') {
        if (x < 0) {
            x = -x;
        }

        for (int i = 1; i <= x; i++) {
            if (prost(i) == 1 && div(x, i) == 1) {
                tmp = i;
            }
        }

        printf("%d", tmp);

    } else {
        printf("n/a");
    }

    return 0;
}

int prost(int x) {
    if (x < 0) {
        x = -x;
    }

    for (int i = 2; i < x; i++) {
        if (div(x, i) == 1) {
            return 0;
        }
    }

    return 1;
}

int div(int x, int y) {
    if (x < 0) {
        x = -x;
    }

    while (x >= y) {
        x -= y;
    }

    if (x == 0) {
        return 1;
    }

    return 0;
}
