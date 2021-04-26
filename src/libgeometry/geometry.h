#pragma once
#include <stdio.h>
#define MAX_SYMB 40

typedef struct{
    char* str;
    
    int radius;    
    int x;
    int y;
} figure;

figure* circle;
int skip_one_space(char* str, int i);
void skip_spaces(char* str, char* conv_str);
figure* init_figures(int sum_of_figures);
void correct_spelling_object(char* only_letters, int max_symb);
void circle_output(char* str, int index);
void perimeter_and_area(figure circle, int max_symb);
void string_tolower(char* str, int max_symb);
void check_for_uncorrect_symbols(char* str, int max_symb, int index);
void check_brackets(char* str, int max_symb, int index);
void arrow_output(char* arrow_str);
