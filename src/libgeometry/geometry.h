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
figure* init_figures(int sum_of_figures);
int correct_spelling_object(char* only_letters);
int circle_output(char* str, int index);
double perimeter(figure* circle);
double area(figure* circle);
int string_tolower(char* str, int max_symb);
int get_points(char* str, figure* circle);
double get_radius(char* str);
int intersections(int index, figure* circle, int sum_of_figures);
int check_rad(char* str, int i);
int error_message(int exit_code);
int print_example();
int check_exit_codes(int* exit_code, int sum_of_figures, figure* circle);
