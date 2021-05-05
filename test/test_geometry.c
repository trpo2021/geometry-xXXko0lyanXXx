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


