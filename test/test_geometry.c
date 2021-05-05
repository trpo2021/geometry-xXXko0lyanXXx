#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(validation, correct_input)
{
    char input_str[] = "circle(123.00 12.00, 5784.00)\n";

    int expect = 0;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, invalid_object)
{
    char input_str[] = "ciocle(123.00 12.00, 5784.00)\n";

    int expect = -2;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, invalid_x)
{
    char input_str[] = "circle(123.\00 12.00, 5784.00)\n";

    int expect = -1;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, invalid_y)
{
    char input_str[] = "circle(123.00 75j9.00, 5784.00)\n";

    int expect = -1;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, miss_comma)
{
    char input_str[] = "circle(123.00 12.00 5784.00)\n";

    int expect = -5;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, miss_open_bracket)
{
    char input_str[] = "circle123.00 12.00, 5784.00)\n";

    int expect = -3;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, miss_close_bracket)
{
    char input_str[] = "circle(123.00 12.00, 5784.00\n";

    int expect = -6;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(validation, miss_space)
{
    char input_str[] = "circle(123.00v12.00, 5784.00)\n";

    int expect = -4;
    int result = validation(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(skip_spaces, skip_one_space)
{
    char input_str[] = "circle( 123.00 12.00, 5784.00)\n";
    int input_index = 7;
    int expect = 8;
    int result = skip_spaces(input_str, input_index);
    ASSERT_EQUAL(expect, result);
}

CTEST(skip_spaces, skip_spaces_in_start)
{
    char input_str[] = "        circle(123.00 12.00, 5784.00)\n";
    int input_index = 0;
    int expect = 8;
    int result = skip_spaces(input_str, input_index);
    ASSERT_EQUAL(expect, result);
}

CTEST(skip_digit, skip_digit_before_dot)
{
    char input_str[] = "circle(123.00 12.00, 5784.00)\n";
    int input_index = 8;
    int expect = 10;
    int result = skip_digit(input_str, input_index);
    ASSERT_EQUAL(expect, result);
}

CTEST(skip_digit, skip_digit_after_dot)
{
    char input_str[] = "circle(123.00 12.00, 5784.00)\n";
    int input_index = 11;
    int expect = 13;
    int result = skip_digit(input_str, input_index);
    ASSERT_EQUAL(expect, result);
}

CTEST(convert_str, correct_str)
{
    char input_str1[] = "circle(123.00 12.00, 5784.00)\n";
    char input_str2[50];
    char expect_str[] = "circle(123.00 12.00, 5784.00)\n";
    int expect = 0;
    int result = convert_str(input_str1, input_str2);
    ASSERT_STR(input_str2, expect_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(convert_str, delete_random_spaces)
{
    char input_str1[] = "  circle  (  123.00    12.00  ,    5784.00  )  \n";
    char input_str2[50];
    char expect_str[] = "circle(123.00 12.00, 5784.00)\n";
    int expect = 0;
    int result = convert_str(input_str1, input_str2);
    ASSERT_STR(input_str2, expect_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_spelling_object, correct_object)
{
    char input_str[] = "circle(123.00 12.00, 5784.00)\n";
    int expect = 6;
    int result = correct_spelling_object(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_spelling_object, uncorrect_object)
{
    char input_str[] = "cirlle(123.00 12.00, 5784.00)\n";
    int expect = -2;
    int result = correct_spelling_object(input_str);
    ASSERT_EQUAL(expect, result);
}

CTEST(area, small_input)
{
    circle = init_figures(1);
    circle[1].radius = 10.00;
    int expect = 314.159;
    int result = area(&circle[1]);
    ASSERT_DBL_NEAR(expect, result);
    free(circle[1].str);
    free(circle);
}

CTEST(area, big_input)
{
    circle = init_figures(1);
    circle[1].radius = 501.19;
    double expect = 789141.107;
    double result = area(&circle[1]);
    ASSERT_DBL_NEAR_TOL(expect, result, 1.000e-03);
    free(circle[1].str);
    free(circle);
}

CTEST(perimeter, small_input)
{
    circle = init_figures(1);
    circle[1].radius = 30.00;
    double expect = 188.496;
    double result = perimeter(&circle[1]);
    ASSERT_DBL_NEAR_TOL(expect, result, 1.000e-03);
    free(circle[1].str);
    free(circle);
}

CTEST(perimeter, big_input)
{
    circle = init_figures(1);
    circle[1].radius = 906.13;
    double expect = 5693.383;
    double result = perimeter(&circle[1]);
    ASSERT_DBL_NEAR_TOL(expect, result, 1.000e-03);
    free(circle[1].str);
    free(circle);
}

CTEST(string_tolower, small_letters)
{
    char input_str[] = "circle(1.00 2.00, 3.00)";
    char expect_str[] = "circle(1.00 2.00, 3.00)";

    int expect = 0;
    int result = string_tolower(input_str);
    ASSERT_EQUAL(expect, result);
    ASSERT_STR(expect_str, input_str);
}

CTEST(string_tolower, caps_lock)
{
    char input_str[] = "CIRCLE(1.00 2.00, 3.00)";
    char expect_str[] = "circle(1.00 2.00, 3.00)";

    int expect = 0;
    int result = string_tolower(input_str);
    ASSERT_EQUAL(expect, result);
    ASSERT_STR(expect_str, input_str);
}

CTEST(get_points, positive)
{
    circle = init_figures(1);
    char input_str[] = "circle(34.4242 9338.131, 3.00)";
    int expect = 0;
    double expect_x = 34.4242;
    double expect_y = 9338.131;
    int result = get_points(input_str, &circle[1]);
    ASSERT_EQUAL(expect, result);
    ASSERT_DBL_NEAR(expect_x, circle[1].x);
    ASSERT_DBL_NEAR(expect_y, circle[1].y);
    free(circle[1].str);
    free(circle);
}

CTEST(get_points, negative)
{
    circle = init_figures(1);
    char input_str[] = "circle(-89243.3221 -1414.2992, 3.00)";
    int expect = 0;
    double expect_x = -89243.3221;
    double expect_y = -1414.2992;
    int result = get_points(input_str, &circle[1]);
    ASSERT_EQUAL(expect, result);
    ASSERT_DBL_NEAR(expect_x, circle[1].x);
    ASSERT_DBL_NEAR(expect_y, circle[1].y);
    free(circle[1].str);
    free(circle);
}



