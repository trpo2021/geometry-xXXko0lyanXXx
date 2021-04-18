#include "libgeometry/geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* string_tolower(char* str, int max_symb)
{
    int i;
    for (i = 0; i < max_symb; i++) {
        if (isalpha(str[i]) != 0) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
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
int check_for_uncorrect_spaces(char* str, int max_symb)
{
    char* arrow_str;
    int flag = 0, isdig;
    int* unc_spcs_index;
    unc_spcs_index = (int*)calloc(max_symb, sizeof(int));
    arrow_str = (char*)calloc(max_symb, sizeof(char));
    int k = 0;
    for (int i = 0; str[i] != '\n'; i++) {
        if ((str[i] == ' ') && ((isdig = isdigit(str[i + 1])) == 0)
            && (str[i + 1] != ',')) {
            unc_spcs_index[i] = i + 1;
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("ERROR! ");
        printf("Uncorrcect spaces!\n");
        circle_output(str);
        for (; str[k] != '\n'; k++) {
            if (unc_spcs_index[k] == k + 1) {
                arrow_str[k] = '^';
            } else
                arrow_str[k] = '-';
        }
        circle_output(arrow_str);
        printf("\n");
        free(unc_spcs_index);
        free(arrow_str);
        free(str);
        exit(1);
    }
    free(unc_spcs_index);
    free(arrow_str);
    return 0;
}
void check_for_uncorrect_symbols(char* str, int max_symb)
{
    char* arrow_str;
    arrow_str = (char*)calloc(max_symb, sizeof(char));
    int k = 0;
    for (int i = 0; str[i] != '\n'; i++) {
        if ((isalpha(str[i]) == 0) && (isdigit(str[i]) == 0) && (str[i] != ' ')
            && (str[i] != ',') && (str[i] != '(') && (str[i] != ')')) {
            printf("ERROR! ");
            printf("Unknown symbol \"%c\" at column %d!\n", str[i], i + 1);
            circle_output(str);
            for (; k != i; k++) {
                arrow_str[k] = '-';
                arrow_str[k + 1] = '^';
            }
            circle_output(arrow_str);
            printf("\n");
            free(arrow_str);
            free(str);
            exit(1);
        }
    }
    free(arrow_str);
}
void check_brackets(char* str, int max_symb)
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
            circle_output(str);
            for (; k != i; k++) {
                arrow_str[k] = '-';
                arrow_str[k + 1] = '^';
            }
            circle_output(arrow_str);
            printf("\n");
            free(arrow_str);
            free(str);
            exit(1);
        }
    }
    free(arrow_str);
}
void circle_output(char* str)
{
    fputs(str, stdout);
}

void perimeter_n_area(char* str, int max_symb)
{
    int r = 0;
    int i, k;
    char radius[10];
    float area, perimeter;
    for (i = 0; i < max_symb; i++) {
        if ((str[i] == ',') && (str[i + 1] == ' ')) {
            for (k = i; str[k + 1] != ')'; k++) {
                radius[k - i] = str[k + 1];
            }
        };
    }
    r = atoi(radius);
    area = M_PI * r * r;
    perimeter = 2 * M_PI * r;
    printf("area = %.3f\nperimeter = %.3f\n", area, perimeter);
}
