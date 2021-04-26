#include "libgeometry/geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int i;
    //FILE* input_file = fopen("input.txt", "r+");
    /*if(input_file == NULL){
    printf("ERROR\n");
    exit(228);
    } */
    
    int sum_of_figures;
    int max_symb = 40;
    char *converted_str = calloc(max_symb, sizeof(char));
    if (argc > 2) {
        printf("Invalid number of parameters\n");
        printf("./geometry <number of circles>\n");
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
        fgets(circle[i].str, max_symb, stdin);
    }
    for (i = 0; i < sum_of_figures; i++) {
        string_tolower(circle[i].str, max_symb);
        skip_spaces(circle[i].str, converted_str);
        check_brackets(converted_str, max_symb, i + 1);
        check_for_uncorrect_symbols(converted_str, max_symb, i + 1);
        correct_spelling_object(converted_str, max_symb);
        circle_output(converted_str, i + 1);
        perimeter_and_area(circle[i], max_symb);
    }
    return 0;
}
