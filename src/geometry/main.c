#include "libgeometry/geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_symb = 40;
    char *source_str;
    source_str = (char*) calloc(max_symb, sizeof(char));
    printf("Input your figure\n");
    fgets(source_str, max_symb, stdin);
    source_str = string_tolower(source_str, max_symb);
    check_for_uncorrect_spaces(source_str, max_symb);
  //  check_brackets(source_str, max_symb);
    check_for_uncorrect_symbols(source_str, max_symb);
    correct_spelling_object(source_str, max_symb);
    circle_output(source_str);
    perimeter_n_area(source_str, max_symb);
    return 0;
}
