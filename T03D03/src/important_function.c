#include <stdio.h>
#include <math.h>

double res(double x);

int main(void) {
    double a, b;
    char c;

    if (scanf("%lf%c", &a, &c) == 2 && c == '\n') {
        b = res(a);
        printf("%.1f", b);
    } else {
        printf("n/a");
    }

    return 0;
}

double res(double x) {
    double result = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
    return result;
}
