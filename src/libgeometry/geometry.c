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
        if (!ptr->str) {
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}
int string_tolower(char* str, int max_symb)
{
    int i;
    for (i = 0; i < max_symb; i++) {
        if (isalpha(str[i]) != 0) {
            str[i] = tolower(str[i]);
        }
    }
    return 0;
}

int correct_spelling_object(char* str)
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int i = 0;
    while (str[i] == check_str[i]) {
        i++;
    }
    if (i < 6) {
        return -2;
    }
    return i;
}
int skip_digit(char* str, int i)
{
    while (isdigit(str[i]) != 0) {
        i++;
    }
    return i;
}
int check_rad(char* str, int i)
{
    if (str[i] == '-') {
        return -7;
    }
    if (isdigit(str[i]) == 0) {
        return -7;
    }
    i = skip_digit(str, i);
    if (str[i] != '.') {
        return -7;
    } else {
        i++;
    }
    if (isdigit(str[i]) == 0) {
        return -7;
    }
    i = skip_digit(str, i);
    return i;
}

int check_point(char* str, int i)
{
    if (str[i] == '-') {
        i++;
    }
    if (isdigit(str[i]) == 0) {
        return -1;
    }
    i = skip_digit(str, i);
    if (str[i] != '.') {
        return -1;
    } else {
        i++;
    }
    if (isdigit(str[i]) == 0) {
        return -1;
    }
    i = skip_digit(str, i);
    return i;
}

int circle_output(char* str, int index)
{
    printf("%d. ", index);
    fputs(str, stdout);
    return 0;
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

int perimeter_and_area(figure* circle)
{
    double area, perimeter;
    area = M_PI * circle->radius * circle->radius;
    perimeter = 2 * M_PI * circle->radius;
    printf("area = %.3f\nperimeter = %.3f\n", area, perimeter);
    return 0;
}
int validation(char* str)
{
    int i;
    i = correct_spelling_object(str);
    if (i == -2) {
        return -2;
    }
    i = skip_spaces(str, i);
    if (str[i] != '(') {
        return -3;
    }
    i++;
    i = check_point(str, i);
    if (i == -1) {
        return -1;
    }
    if (str[i] != ' ') {
        return -4;
    }
    i = skip_spaces(str, i);
    i = check_point(str, i);
    if (i == -1) {
        return -1;
    }
    i = skip_spaces(str, i);
    if (str[i] != ',') {
        return -5;
    }
    i++;
    i = skip_spaces(str, i);
    i = check_rad(str, i);
    if (i == -7) {
        return -7;
    }
    if (str[i] != ')') {
        return -6;
    }
    return 0;
}
int convert_str(char* str, char* conv_str)
{
    int i = 0, j;
    i = skip_spaces(str, i);
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
    i = skip_spaces(str, i);
    for (; (str[i] != ',') && (str[i] != ' '); i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = ',';
    j++;
    conv_str[j] = ' ';
    j++;
    i = skip_spaces(str, i);
    if (str[i] == ',') {
        i++;
    }
    i = skip_spaces(str, i);
    for (; (str[i] != ')') && (str[i] != ' '); i++, j++) {
        conv_str[j] = str[i];
    }
    conv_str[j] = ')';
    j++;
    conv_str[j] = '\n';
    return 0;
}
int get_points(char* str, figure* circle)
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
    return 0;
}

int skip_spaces(char str[], int i)
{
    while (str[i] == ' ') {
        i++;
    }
    return i;
}
int intersections(int index, figure* circle, int sum_of_figures)
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
            printf("%d. circle \n", i + 1);
        }
    }
    return 0;
}
int error_message(int exit_code)
{
    switch (exit_code) {
    case -1:
        printf("ERROR! Expected <double>\n");
        print_example();
        break;
    case -2:
        printf("ERROR! Uncorrect input \"object\"!\n");
        printf("Did you mean \"circle\"?");
        print_example();
        break;
    case -3:
        printf("ERROR! Expected '('!\n");
        print_example();
        break;
    case -4:
        printf("ERROR! Expected 'space'!\n");
        print_example();
        break;
    case -5:
        printf("ERROR! Expected ','(comma)!\n");
        print_example();
        break;
    case -6:
        printf("ERROR! Expected ')'!\n");
        print_example();
        break;
    case -7:
        printf("ERROR! Expected <unsigned double>!\n");
        print_example();
        break;
    }
    return 0;
}
int print_example()
{
    printf("Example: object(double double, unsigned double)\n");
    return 0;
}
int check_exit_codes(int* exit_code, int sum_of_figures, figure* circle)
{
    int i;
    int invalid_inputs = 0;
    for (i = 0; i < sum_of_figures; i++) {
        if (exit_code[i] != 0) {
            invalid_inputs++;
        }
    }

    if (invalid_inputs != 0) {
        for (i = 0; i < sum_of_figures; i++) {
            if (exit_code[i] != 0) {
                circle_output(circle[i].str, i + 1);
                error_message(exit_code[i]);

            } else {
                circle_output(circle[i].str, i + 1);
                printf("this input is correct, please correct ");
                printf("the input in the rest of the figures to get the "
                       "result\n");
            }
        }
        exit(1);
    }
    return 0;
}
