#pragma once
#include <stdio.h>
#define MAX_SYMB 40

typedef struct{
    char* circle_string;
} figure;

figure* init_figures(int sum_of_figures);
void correct_spelling_object(char* only_letters, int max_symb);
void circle_output(char* str, int index);
void perimeter_n_area(char* str, int max_symb);
char* string_tolower(char* str, int max_symb);
int check_for_uncorrect_spaces(char* str, int max_symb, int index);
void check_for_uncorrect_symbols(char* str, int max_symb, int index);
void check_brackets(char* str, int max_symb, int index);
void arrow_output(char* arrow_str);
