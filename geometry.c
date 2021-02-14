#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, m;
    int max_symb = 40;
    char sourse_str[max_symb], coordinates_str[max_symb], radius[max_symb];
    printf("Введите координаты центра окружности и её радиус.\n");
    printf("Формат записи: object(x y, r).\n");
    fgets(sourse_str, max_symb, stdin);
    fputs(sourse_str, stdout);
}
