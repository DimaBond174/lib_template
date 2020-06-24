#include "gtest/gtest.h"
#include "test1/test1_impl.h"

TEST(testsuite, Test1)
{  
    int res = do_Test1();// add_numbers(1.0, 2.0);
    ASSERT_EQ(res, 1) ;
}
