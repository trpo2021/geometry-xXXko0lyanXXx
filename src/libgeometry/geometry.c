#include "libgeometry/geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

figure* init_figures(int sum_of_figures)
{
    int i;
    figure* ptr = malloc(sum_of_figures * sizeof(figure));
    if (!ptr) {
        return NULL;
    }
    for (i = 0; i < sum_of_figures; i++) {
        ptr[i].str = malloc(MAX_SYMB * sizeof(char));
        if (!ptr->str) {
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}
void string_tolower(char* str, int max_symb)
{
    int i;
    for (i = 0; i < max_symb; i++) {
        if (isalpha(str[i]) != 0) {
            str[i] = tolower(str[i]);
        }
    }
}

void correct_spelling_object(char* str, int max_symb)
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int j;
    char* object_str;
    object_str = (char*)calloc(max_symb, sizeof(char));
    for (int i = 0; str[i] != '('; i++) {
        object_str[i] = str[i];
    }
    j = strcmp(object_str, check_str);
    if (j != 0) {
        printf("ERROR! Input is not correct\n");
        printf("\"%s\" Not found\nDid you mean \"circle\"?\n", object_str);
        free(object_str);
        free(str);
        exit(1);
    };
    free(object_str);
}

void check_for_uncorrect_symbols(char* str, int max_symb, int index)
{
    char* arrow_str;
    arrow_str = (char*)calloc(max_symb, sizeof(char));
    int k = 0;
    for (int i = 0; str[i] != '\n'; i++) {
        if ((isalpha(str[i]) == 0) && (isdigit(str[i]) == 0) && (str[i] != ' ')
            && (str[i] != ',') && (str[i] != '(') && (str[i] != ')')) {
            printf("ERROR! ");
            printf("Unknown symbol \"%c\" at column %d!\n", str[i], i + 1);
            circle_output(str, index);
            for (; k != i; k++) {
                arrow_str[k] = '-';
                arrow_str[k + 1] = '-';
                arrow_str[k + 2] = '-';
                arrow_str[k + 3] = '-';
                arrow_str[k + 4] = '^';
            }
            }
            arrow_output(arrow_str);
            printf("\n");
            free(arrow_str);
            free(str);
            exit(1);
        }
    }
void check_brackets(char* str, int max_symb, int index)
{
    int sum_of_letters, i, k;
    sum_of_letters = 0;
    k = i = 0;
    char* arrow_str;
    arrow_str = (char*)calloc(max_symb, sizeof(char));
    while (str[sum_of_letters] != '(') {
        sum_of_letters++;
    }
    for (i = sum_of_letters + 1; str[i] != '\n'; i++) {
        if ((isdigit(str[i]) == 0) && (str[i] != ' ') && (str[i] != ',')
            && (str[i] != ')')) {
            printf("ERROR! ");
            printf("Unknown symbol \"%c\" at column %d!\n", str[i], i + 1);
            circle_output(str, index);
            printf("\n");
            for (; k != i; k++) {
                arrow_str[k] = '-';
                arrow_str[k + 1] = '-';
                arrow_str[k + 2] = '-';
                arrow_str[k + 3] = '-';
                arrow_str[k + 4] = '^';
            }
            arrow_output(arrow_str);
            printf("\n");
            free(arrow_str);
            free(str);
            exit(1);
        }
    }
    free(arrow_str);
}
void circle_output(char* str, int index)
{
    printf("%d. ", index);
    fputs(str, stdout);
}

void perimeter_and_area(figure circle, int max_symb)
{
    int i, k;
    char radius[10];
    float area, perimeter;
    for (i = 0; i < max_symb; i++) {
        if ((circle.str[i] == ',') && (circle.str[i + 1] == ' ')) {
            for (k = i; circle.str[k + 1] != ')'; k++) {
                radius[k - i] = circle.str[k + 1];
            }
        };
    }
    circle.radius = atoi(radius);
    area = M_PI * circle.radius * circle.radius;
    perimeter = 2 * M_PI * circle.radius;
    printf("area = %.3f\nperimeter = %.3f\n", area, perimeter);
}
void skip_spaces(char* str, char* conv_str)
{
    int i = 0, j;
    i = skip_one_space(str, i);
    for (j = 0; (str[i] != '(') && (str[i] != ' '); i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = '(';
    j++;
    while ((str[i] != '-') && (isdigit(str[i]) == 0)) {
        i++;
    }
    for (; str[i] != ' '; i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = ' ';
    j++;
    i = skip_one_space(str, i);
    for (; (str[i] != ',') && (str[i] != ' '); i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = ',';
    j++;
    conv_str[j] = ' ';
    j++;
    i = skip_one_space(str, i);
    if (str[i] == ',') {
        i++;
    }
    i = skip_one_space(str, i);
    for (; (str[i] != ')') && (str[i] != ' '); i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = ')';
    j++;
    conv_str[j] = '\n';
}

int skip_one_space(char str[], int i)
{
    while (str[i] == ' ') {
        i++;
    }
    return i;
}


void arrow_output(char* arrow_str)
{
    fputs(arrow_str, stdout);
}

