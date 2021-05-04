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
int validation(char* str);
int skip_spaces(char* str, int i);
int skip_digit(char* str, int i);
int convert_str(char* str, char* conv_str);
int check_points(char* str);
figure* init_figures(int sum_of_figures);
int correct_spelling_object(char* only_letters);
int circle_output(char* str, int index);
int perimeter_and_area(figure* circle);
int string_tolower(char* str, int max_symb);
int check_for_uncorrect_symbols(char* str, int max_symb, int index);
int check_brackets(char* str, int max_symb, int index);
int arrow_output(char* arrow_str);
int get_points(char* str, figure* circle);
double get_radius(char* str);
int intersections(int index, figure* circle, int sum_of_figures);
int check_rad(char* str, int i);
int error_message(int exit_code);
int print_example();
int check_exit_codes(int* exit_code, int sum_of_figures, figure* circle);
