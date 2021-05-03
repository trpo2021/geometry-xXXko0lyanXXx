#include "libgeometry/geometry.h"

figure* init_figures(int sum_of_figures)
{
    int i;
    figure* ptr = calloc(sum_of_figures, sizeof(figure));
    if (!ptr) {
        return NULL;
    }
    for (i = 0; i < sum_of_figures; i++) {
        ptr[i].str = calloc(MAX_SYMB, sizeof(char));
    //    ptr[i].intersections = calloc(sum_of_figures, sizeof(int));
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
int skip_digit(int i, char* str)
{
    while (isdigit(str[i]) != 0) {
        i++;
    }
    return i;
}
int check_points(char* str)
{
    int index_of_symbol = 0;
    while (isalpha(str[index_of_symbol]) != 0) {
        index_of_symbol++;
    }
    if (str[index_of_symbol] != '(') {
        printf("Error! Expected '(' \n");
        return -10;
    }
    index_of_symbol++;
    if ((isdigit(str[index_of_symbol]) == 0) && (str[index_of_symbol] != '-')) {
        return 1;
    } else if (str[index_of_symbol] == '-') {
        index_of_symbol++;
    }
    if (isdigit(str[index_of_symbol] == 0)) {
        return -1;
    }
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != '.') {
        return -2;
    }
    index_of_symbol++;
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != ' ') {
        return -3;
    }
    index_of_symbol++;
    if ((isdigit(str[index_of_symbol]) == 0) && (str[index_of_symbol] != '-')) {
        return 4;
    } else if (str[index_of_symbol] == '-') {
        index_of_symbol++;
    }
    if (isdigit(str[index_of_symbol]) == 0) {
        return -4;
    }
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != '.') {
        return -5;
    }
    index_of_symbol++;
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != ',') {
        return -6;
    }
    index_of_symbol++;
    if (str[index_of_symbol] != ' ') {
        return -7;
    }
    index_of_symbol++;
    if ((isdigit(str[index_of_symbol]) == 0) && (str[index_of_symbol] != '-')) {
        return 8;
    } else if (str[index_of_symbol] == '-') {
        index_of_symbol++;
    }
    if (isdigit(str[index_of_symbol]) == 0) {
        return -8;
    }
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != '.') {
        return -9;
    }
    index_of_symbol++;
    index_of_symbol = skip_digit(index_of_symbol, str);
    if (str[index_of_symbol] != ')') {
        printf("Error! Expected ')' \n");
        return 10;
    }

    return 0;
}

void circle_output(char* str, int index)
{
    printf("%d. ", index);
    fputs(str, stdout);
}
double get_radius(char* str)
{
    char* radius_str;
    double radius;
    radius_str = calloc(MAX_SYMB, sizeof(char));
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    i = i + 2;
    int k = 0;
    while (str[i] != ')') {
        radius_str[k] = str[i];
        k++;
        i++;
    }
    radius = atof(radius_str);
    return radius;
}

void perimeter_and_area(figure *circle)
{
    double area, perimeter;
    area = M_PI * circle->radius * circle->radius;
    perimeter = 2 * M_PI * circle->radius;
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
void get_points(char* str, figure* circle)
{
    int index_of_symbol, i;
    char* point_str;
    point_str = calloc(MAX_SYMB, sizeof(char));
    index_of_symbol = 7;
    i = 0;
    while (str[index_of_symbol] != ' ') {
        point_str[i] = str[index_of_symbol];
        i++;
        index_of_symbol++;
    }
    circle->x = atof(point_str);
    index_of_symbol++;
    i = 0;
    while (str[index_of_symbol] != ',') {
        point_str[i] = str[index_of_symbol];
        i++;
        index_of_symbol++;
    }
    circle->y = atof(point_str);
    printf("%lf, %lf\n", circle->x, circle->y);
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

void intersections(int index, figure* circle, int sum_of_figures)
{
    double x1 = circle[index].x;
    double y1 = circle[index].y;
    double radius1 = circle[index].radius;
    double* x2 = calloc(sum_of_figures, sizeof(double));
    double* y2 = calloc(sum_of_figures, sizeof(double));
    double* radius2 = calloc(sum_of_figures, sizeof(double));
    int i;
    for (i = 0; i < sum_of_figures; i++) {
        x2[i] = circle[i].x;
        y2[i] = circle[i].y;
        radius2[i] = circle[i].radius;
    }
    double d;
    printf("intersets:\n");
    for (i = 0; i < sum_of_figures; i++) {
        d = sqrt(((x1 - x2[i]) * (x1 - x2[i])) + ((y1 - y2[i]) * (y1 - y2[i])));
        if ((d < radius1 + radius2[i]) && (d > fabs(radius1 - radius2[i]))) {
        printf("%d. circle \n", i);
        }
        }
}

