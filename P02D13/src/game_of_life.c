#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define row 25
#define col 80

// gcc -Wall -Werror -Wextra -lcurses game_of_life.c
// ./a.out < file.txt

void draw(int grid[row][col]);
int correctX(int x);
int correctY(int y);
void countLiveNeighbours(int grid[row][col]);
int countNeighbours(int grid[row][col], int x, int y);
int endGame(int a[20][row][col], int grid[row][col]);

int main(void) {
    int grid[row][col];
    int a[20][row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    initscr();  //создание поля ncurses
    FILE *f;
    f = freopen("/dev/tty", "r", stdin);
    int speed;
    printw("Enter the speed (in ms): ");
    scanw("%d", &speed);

    noecho();     //не выводит вводимые значения в терминал
    curs_set(0);  //курсос не мигает
    timeout(speed);
    clear();
    while (1) {
        countLiveNeighbours(grid);
        draw(grid);

        char key;
        key = getch();
        if (key == 'q' || key == 'Q' || endGame(a, grid) == 0) break;
        if (key == '-') {
            speed++;
            timeout(speed);
        }
        if (key == '+') {
            speed--;
            timeout(speed);
        }
    }
    fclose(f);
    endwin();  // закрытие поля ncurses
    echo();    // выводит вводимые значения в терминал
    return 0;
}

int endGame(int a[20][row][col], int grid[row][col]) {
    int flag = 1;
    for (int k = 0; k < 19; k++) {
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (a[k][i][j] != grid[i][j]) count++;
            }
        }
        if (count == 0) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        for (int k = 0; k < 19; k++) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[k][i][j] = a[k + 1][i][j];
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[19][i][j] = grid[i][j];
            }
        }  //получаем новый массив a
    }
    return flag;
}

void draw(int grid[row][col]) {
    clear();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1)
                printw("*");
            else
                printw(".");
        }
        printw("\n");
    }
    printw("Insert Q to exit. \nInsert + to pick up speed. Insert - to slow down.");
}

int correctX(int x) {
    if (x < 0) return x += col;
    if (x >= col) return x -= col;
    return x;
}

int correctY(int y) {
    if (y < 0) return y += row;
    if (y >= row) return y -= row;
    return y;
}

void countLiveNeighbours(int grid[row][col]) {
    int next[row][col];  //создаем массив, это будет наш newgrid после иетрации
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int neighbours = countNeighbours(grid, i, j);
            if (grid[i][j] == 0 && neighbours == 3) {
                next[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbours < 2 || neighbours > 3)) {
                next[i][j] = 0;
            } else if (grid[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                next[i][j] = 1;
            } else {
                next[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

int countNeighbours(int grid[row][col], int x, int y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            count += grid[correctY(x + j)][correctX(y + i)];  // check zone
        }
    }
    count -= grid[x][y];
    return count;
}
