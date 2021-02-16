#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INCREMENT 10

void perimeter_n_area(char* str, int max_symb, int size_incr)
{
    char arr[max_symb];
    int j = 0;

    for (int i = 0; i < max_symb - 1; i++) {
        if ((str[i] == '(') || (str[i] == ' ') || (str[i] == ',')) { // circle(0 0, 1.5)
            arr[j] = str[i + 1];
            j++;
        };
        if (arr[i] == ')') {
            break;
        };
    }
}
int main()
{
    int max_symb = 40;
    int size_incr = SIZE_INCREMENT;
    FILE* mf;
    mf = fopen("inputq.txt", "r");
    char sourse_str[max_symb];
    fgets(sourse_str, max_symb, mf);
    perimeter_n_area(sourse_str, max_symb, size_incr);
    fputs(sourse_str, stdout);
    printf("\n");
    return 0;
}
