#include "./polish_calc.h"

#include <math.h>
#include <stdlib.h>

double polish_calc(struct Polish_formula** polish_formula) {
    struct Calc_stack* calculation = NULL;
    struct Polish_formula** temp = polish_formula;
    while (*polish_formula != NULL) {
        if ((*polish_formula)->number != -1) {
            calculation = push_calc((*polish_formula)->number, calculation);
        } else if ((*polish_formula)
                       ->
                       operator== '+' ||(*polish_formula)
                       ->
                       operator== '*' ||(*polish_formula)
                       ->
                       operator== '/') {
            double x, y;
            calculation = pop_calc(calculation, &x);
            calculation = pop_calc(calculation, &y);
            double result = calc_two_nums(x, y, (*polish_formula)->operator);
            calculation = push_calc(result, calculation);
        } else if ((*polish_formula)
                       ->
                       operator== 'S' ||(*polish_formula)
                       ->
                       operator== 'C' ||(*polish_formula)
                       ->
                       operator== 'T' ||(*polish_formula)
                       ->
                       operator== 'G' ||(*polish_formula)
                       ->
                       operator== 'L' ||(*polish_formula)
                       ->
                       operator== 'Q') {
            double x;
            calculation = pop_calc(calculation, &x);
            double result = calc_one_num(x, (*polish_formula)->operator);
            calculation = push_calc(result, calculation);
        } else if ((*polish_formula)->operator== '-') {
            if (calculation->prev != NULL) {  // If '-' is binary operation
                double x, y;
                calculation = pop_calc(calculation, &x);
                calculation = pop_calc(calculation, &y);
                double result = calc_two_nums(x, y, (*polish_formula)->operator);
                calculation = push_calc(result, calculation);
            } else {  // If '-' is unary operation
                double x;
                calculation = pop_calc(calculation, &x);
                double result = x * -1;
                calculation = push_calc(result, calculation);
            }
        }
        *polish_formula = (*polish_formula)->next;
    }
    double result = calculation->value;
    free_structure(temp);
    free(calculation);
    return result;
}

double calc_two_nums(double x, double y, char operator) {
    double result = 0;
    switch (operator) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = y - x;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = y / x;
            break;
    }
    return result;
}

double calc_one_num(double x, char operator) {
    double result = 0;
    switch (operator) {
        case 'S':
            result = sin(x);
            break;
        case 'C':
            result = cos(x);
            break;
        case 'T':
            result = tan(x);
            break;
        case 'G':
            result = cos(x) / sin(x);
            break;
        case 'L':
            result = log(x);
            break;
        case 'Q':
            result = sqrt(x);
            break;
    }
    return result;
}
