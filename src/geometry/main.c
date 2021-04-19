#include "libgeometry/geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    figure* circle;
    int i;
    int sum_of_figures;
    int max_symb = 40;
    if (argc > 2) {
        printf("Invalid number of parameters\n");
    }
    if (argc == 1) {
        printf("You ran the program without using command line arguments");
        printf(", the number of circles is 1\n");
        sum_of_figures = 1;
        circle = init_figures(sum_of_figures);
    }
    if ((argc == 1) || ((argc == 2) && (strcmp(argv[1], "1") == 0))) {
        printf("Input your figure\n");
    }
    if ((argc == 2) && ((strcmp(argv[1], "1") != 0))) {
        printf("Input your figures\n");
        sum_of_figures = atoi(argv[1]);
        circle = init_figures(sum_of_figures);
    }
    for (i = 0; i < sum_of_figures; i++) {
        fgets(circle[i].circle_string, max_symb, stdin);
    }
    for (i = 0; i < sum_of_figures; i++) {
        circle[i].circle_string
                = string_tolower(circle[i].circle_string, max_symb);
        check_for_uncorrect_spaces(circle[i].circle_string, max_symb, i + 1);
        check_brackets(circle[i].circle_string, max_symb, i + 1);
        check_for_uncorrect_symbols(circle[i].circle_string, max_symb, i + 1);
        correct_spelling_object(circle[i].circle_string, max_symb);
        circle_output(circle[i].circle_string, i + 1);
        perimeter_n_area(circle[i].circle_string, max_symb);
    }
    return 0;
}
