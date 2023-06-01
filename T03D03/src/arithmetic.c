#include <stdio.h>

int main(void) {
    int x, y;
    char z;
    if (scanf("%d %d%c", &x, &y, &z) == 3 && z == '\n') {
        if (y != 0) {
            printf("%d %d %d %d", x + y, x - y, x * y, x / y);
        } else {
            printf("%d %d %d n/a", x + y, x - y, x * y);
        }

    } else {
        printf("n/a");
    }

    return 0;
}
