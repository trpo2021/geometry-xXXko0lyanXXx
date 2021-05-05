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




