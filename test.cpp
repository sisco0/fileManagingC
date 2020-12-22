#include "utils.h"
#include "gtest/gtest.h"

namespace {
    TEST(PowerTest, Three) {
        EXPECT_EQ(9.0, numberToThe(3.0, 2.0));
    }
    TEST(PowerTest, Two) {
        EXPECT_EQ(4.0, numberToThe(2.0, 2.0));
    }
}
