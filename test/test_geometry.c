#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(get_radius, correct_input)
{
   char input_str[] = "circle(1.00 2.00, 3.00)\n";
   
   double expect = 3.00;
   double result = get_radius(input_str);
   ASSERT_EQUAL(expect, result);
}
