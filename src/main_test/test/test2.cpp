#include "gtest/gtest.h"
#include "test2/test2_impl.h"

TEST(testsuite, Test2)
{  
    int res = do_Test2();
    ASSERT_EQ(res, 1) ;
}
