#include "libgeometry/geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_symb = 40;
    char sourse_str[max_symb];
    printf("Input your figure\n");
    fgets(sourse_str, max_symb, stdin);
    string_tolower(sourse_str, max_symb);
    correct_spelling(sourse_str, max_symb);
    cirlce_output(sourse_str);
    perimeter_n_area(sourse_str, max_symb);
    return 0;
}
