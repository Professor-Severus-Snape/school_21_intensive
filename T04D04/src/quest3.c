#include <stdio.h>

int fibonacci(int number);

int main() {
    int number;
    char z;

    if ((scanf("%d%c", &number, &z) != 2) || (z != '\n') || (number <= 0)) {
        printf("n/a");
    } else {
        printf("%d", fibonacci(number));
    }

    return 0;
}

int fibonacci(int number) {
    if (number == 1 || number ==2) {
        return 1;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
