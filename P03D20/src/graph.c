#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./polish_calc.h"
#include "./polska_parcer.h"

#define WIDTH 80
#define HEIGHT 25
#define void_sym 46   // .
#define graph_sym 42  // *
#define ordinate 12   // shift of y axis on the center of screen

void fill_graph(int matrix[HEIGHT][WIDTH]);
void create_graphic(int matrix[HEIGHT][WIDTH], char formula[]);
void print_graph(int matrix[HEIGHT][WIDTH]);

int main() {
    char formula[100];
    int flag = 0;

    fgets(formula, 100, stdin);
    for (int i = 0; formula[i] != '\0' && formula[i] != '\n'; i++) {
        if (formula[i] == 'x') flag = 1;
    }
    if (flag) {
        int graph[HEIGHT][WIDTH];
        fill_graph(graph);  // Fill Graph with void symbols '.'
        create_graphic(graph,
                       formula);  // Read input -> call parsing func -> fill graph with results of calculation
        print_graph(graph);
    } else
        printf("n/a");
    return flag;
}

void fill_graph(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = void_sym;
        }
}

void create_graphic(int matrix[HEIGHT][WIDTH], char formula[]) {
    int count = 0;
    for (double x = 0; x <= 4.0 * M_PI; x += 4.0 * M_PI / 80.0) {
        double res = formula_parcer(formula, x);
        int y = round(res * ordinate);  // Zoom graph for [-1; 1]
        if (y <= ordinate && y >= -ordinate) {
            matrix[ordinate + y][count] = graph_sym;
        }
        count++;
    }
}

void print_graph(int matrix[HEIGHT][WIDTH]) {
    for (int rows = 0; rows < HEIGHT; rows++) {
        for (int cols = 0; cols < WIDTH; cols++) {
            printf("%c", matrix[rows][cols]);
        }
        printf("\n");
    }
}
