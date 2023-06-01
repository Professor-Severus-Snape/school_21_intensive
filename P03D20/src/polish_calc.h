#ifndef POLISH_CALC_H_
#define POLISH_CALC_H_

#include "./polska_parcer.h"
#include "./structure_for_polish.h"

double polish_calc(struct Polish_formula** polish_formula);
double calc_two_nums(double x, double y, char operation);
double calc_one_num(double x, char operation);

#endif