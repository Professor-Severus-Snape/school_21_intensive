#include "./polska_parcer.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./polish_calc.h"

// Parse formula for numbers and operators
double formula_parcer(char formula[100], double x) {
    struct Polish_formula* polish_formula = NULL;
    struct Polish_formula* temporary = NULL;
    polish_formula = add((double)-1, '0', polish_formula);
    temporary = polish_formula;
    struct Stack* operators = NULL;
    int i = 0;
    while (formula[i] != '\0' && formula[i] != '\n') {
        if (formula[i] == '(') {
            operators = push(formula[i], operators);
            i++;
        } else if (formula[i] == 'x') {
            polish_formula = add(x, '0', polish_formula);
            i++;
        } else if (formula[i] >= '0' && formula[i] <= '9') {
            char str_number[100];
            int k = 0;
            for (int j = i; formula[j] >= '0' && formula[j] <= '9'; j++) {
                str_number[k] = formula[j];
                i++, k++;
            }
            int number = atoi(str_number);
            polish_formula = add((double)number, '0', polish_formula);
        } else if (formula[i] == ')') {        // take the operators out of the stack
            while (operators->value != '(') {  // until we get to the opening parenthesis
                char operator= ' ';
                operators = pop(operators, &operator);
                polish_formula = add(-1, operator, polish_formula);
            }
            char tmp = ' ';
            operators = pop(operators, &tmp);  // take the closing bracket out of the stack
            i++;
        } else
            i = check_operator(formula, i, &operators, &polish_formula);
    }
    multiple_pop(&operators, &polish_formula);
    free(operators);
    struct Polish_formula* temp = temporary;
    temporary = temporary->next;
    free(temp);
    return polish_calc(&temporary);
}

int check_operator(const char formula[], int i, struct Stack** operators,
                   struct Polish_formula** polish_formula) {
    char sign = ' ';
    if (formula[i] == 's' && formula[i + 1] == 'i' && formula[i + 2] == 'n') {
        sign = 'S';
        i += 3;
    } else if (formula[i] == 'c' && formula[i + 1] == 'o' && formula[i + 2] == 's') {
        sign = 'C';
        i += 3;
    } else if (formula[i] == 't' && formula[i + 1] == 'a' && formula[i + 2] == 'n') {
        sign = 'T';
        i += 3;
    } else if (formula[i] == 'c' && formula[i + 1] == 't' && formula[i + 2] == 'g') {
        sign = 'G';
        i += 3;
    } else if (formula[i] == 's' && formula[i + 1] == 'q' && formula[i + 2] == 'r' && formula[i + 3] == 't') {
        sign = 'Q';
        i += 4;
    } else if (formula[i] == 'l' && formula[i + 1] == 'n') {
        sign = 'L';
        i += 2;
    } else if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/') {
        sign = formula[i];
        i++;
    }
    if (*operators != NULL && Prior(sign) <= Prior((*operators)->value)) {
        char operator= ' ';
        *operators = pop(*operators, &operator);
        *polish_formula = add(-1, operator, * polish_formula);
    }
    *operators = push(sign, *operators);
    return i;
}

int Prior(char a) {
    switch (a) {
        case 'Q':
            return 4;
        case 'S':
        case 'C':
        case 'T':
        case 'G':
        case 'L':
            return 3;
        case '*':
        case '/':
            return 2;
        case '-':
        case '+':
            return 1;
    }
    return 0;
}
