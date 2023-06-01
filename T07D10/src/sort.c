#include <stdio.h>
#include <stdlib.h>

int array_size();
int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);


int main() {
    int n = array_size();  // размер массива
    int *data = NULL;
    if (n != -1) {
        data = (int*) calloc(n, sizeof(int));  // аллоцируем память:
        if (data != NULL) {
            if (input(data, n) != 1) {
                sort(data, n);
                output(data, n);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}

// определяем размер массива:
int array_size() {
    int n;
    char end;
    if (!(scanf("%d%c", &n, &end) == 2 && end == '\n' && n > 0)) {
        n = -1;
    }
    return n;
}

// функция, заполняющая массив данными:
int input(int *a, int n) {
    
    int flag = 0;  // ok

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if ( !(getchar() == '\n' || getchar() == EOF) ) {
        flag = 1; // ошибка!!
    }

    return flag;
    
}

// сортировка вставками:
void sort(int *a, int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (a[i] > a[k]) {
                tmp = a[k];
                a[k] = a[i];
                a[i] = tmp;
            }
        }
    }
}

// функция вывода:
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}
