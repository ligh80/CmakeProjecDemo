#include "gtest/gtest.h"
#include "MathFunctions.h"

TEST(FactorialTest, Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(1, 1);
  EXPECT_EQ(4, power(2, 2));
}

TEST(FactorialTest, own_power) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(3, power(3, 3));
}

