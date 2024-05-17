#include <gtest/gtest.h>
#include <max.h>

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}

TEST(MaxTest, ReturnsMaxValue) {
  EXPECT_EQ(max(10,20), 20);
}