#pragma once
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SYMB 100

typedef struct{
    char* str;
    
    double radius;    
    double x;
    double y;
} figure;

figure* circle;
int skip_one_space(char* str, int i);
void skip_spaces(char* str, char* conv_str);
int check_points(char* str);
figure* init_figures(int sum_of_figures);
void correct_spelling_object(char* only_letters, int max_symb);
void circle_output(char* str, int index);
void perimeter_and_area(figure* circle);
void string_tolower(char* str, int max_symb);
void check_for_uncorrect_symbols(char* str, int max_symb, int index);
void check_brackets(char* str, int max_symb, int index);
void arrow_output(char* arrow_str);
void get_points(char* str, figure* circle);
double get_radius(char* str);
void intersections(int index, figure* circle, int sum_of_figures);
