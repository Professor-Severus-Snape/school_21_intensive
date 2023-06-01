#include <stdio.h>

int max(int a, int b);

int main(void) {
    int x, y, z;
    char c;

    if (scanf("%d %d%c", &x, &y, &c) == 3 && c == '\n') {
        z = max(x, y);
        printf("%d", z);
    } else {
        printf("n/a");
    }

    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
