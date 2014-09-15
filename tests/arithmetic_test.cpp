#include "number.h"

#include <gtest/gtest.h>

TEST(ArithmeticTests, Add)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");
    auto b = Number::fromDecString("5");

    auto r = a + b;

    ASSERT_EQ("10", r.toDecString());
}