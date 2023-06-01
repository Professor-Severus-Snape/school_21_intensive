#ifndef POLSKA_PARCER_H_
#define POLSKA_PARCER_H_

#include "./structure_for_polish.h"

double formula_parcer(char formula[100], double x);
int check_operator(const char formula[], int i, struct Stack** operators,
                   struct Polish_formula** polish_formula);
int Prior(char);

#endif