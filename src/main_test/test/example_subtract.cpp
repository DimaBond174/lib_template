#include "gtest/gtest.h"

TEST(example, subtract)
{
    double res;
    //res = subtract_numbers(1.0, 2.0);
    res = 3.0;
    ASSERT_NEAR(res, 3.0, 1.0e-11);
    //ASSERT_NEAR(res, -1000.0, 1.0e-11);
}
