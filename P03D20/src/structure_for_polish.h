#ifndef LIB_STRUCTURE_H_
#define LIB_STRUCTURE_H_

struct Polish_formula* add(double num, char oper, struct Polish_formula* elem);
void free_structure(struct Polish_formula** polish_formula);

struct Stack* push(char chr, struct Stack* top);
struct Stack* pop(struct Stack* top, char* chr);
void multiple_pop(struct Stack** operators, struct Polish_formula** polish_formula);

struct Calc_stack* push_calc(double number, struct Calc_stack* top);
struct Calc_stack* pop_calc(struct Calc_stack* top, double* num);

struct Polish_formula {
    double number;
    char operator;
    struct Polish_formula* next;
};

struct Stack {
    char value;
    struct Stack* prev;
};

struct Calc_stack {
    double value;
    struct Calc_stack* prev;
};

#endif