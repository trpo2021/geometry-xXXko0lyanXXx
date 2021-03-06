#include "libgeometry/geometry.h"

int main(int argc, char** argv)
{
    int i;
    int sum_of_figures;
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
        fgets(circle[i].str, MAX_SYMB, stdin);
    }
    char** converted_str;
    converted_str = malloc(sum_of_figures * sizeof(char*));
    for (i = 0; i < sum_of_figures; i++) {
        converted_str[i] = calloc(MAX_SYMB, sizeof(char));
    }
    int exit_code[sum_of_figures];
    for (i = 0; i < sum_of_figures; i++) {
        string_tolower(circle[i].str);
        exit_code[i] = validation(circle[i].str);
    }
    check_exit_codes(exit_code, sum_of_figures, circle);
    for (i = 0; i < sum_of_figures; i++) {
        convert_str(circle[i].str, converted_str[i]);
        get_points(converted_str[i], &circle[i]);
        circle[i].radius = get_radius(converted_str[i]);
        circle_output(converted_str[i], i + 1);
        perimeter(&circle[i]);
        area(&circle[i]);
        if (sum_of_figures > 1) {
            intersections(i, circle, sum_of_figures);
        }
        printf("\n");
    }
    for (i = 0; i < sum_of_figures; i++) {
        free(circle[i].str);
        free(converted_str[i]);
    }
    free(converted_str);
    free(circle);
    return 0;
}
