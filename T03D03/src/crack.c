#include <stdio.h>

int main(void) {
    double x, y;
    char z;

    if (scanf("%lf %lf%c", &x, &y, &z) == 3 && z == '\n') {
        if (x * x + y * y < 25) {
            printf("GOTCHA");
        } else {
            printf("MISS");
        }
    } else {
        printf("n/a");
    }

    return 0;
}
