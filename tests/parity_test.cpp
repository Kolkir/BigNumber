#include "number.h"

#include <gtest/gtest.h>

TEST(ParityTests, IsOdd)
{
    using namespace bignumber;

    auto b = Number::fromDecString("5");

    ASSERT_TRUE(b.isOdd());
    ASSERT_FALSE(b.isEven());

    b = Number::fromDecString("15");

    ASSERT_TRUE(b.isOdd());
    ASSERT_FALSE(b.isEven());


    b = Number::fromDecString("6546754615");

    ASSERT_TRUE(b.isOdd());
    ASSERT_FALSE(b.isEven());
}

TEST(ParityTests, IsEven)
{
    using namespace bignumber;

    auto b = Number::fromDecString("6");

    ASSERT_FALSE(b.isOdd());
    ASSERT_TRUE(b.isEven());

    b = Number::fromDecString("32");

    ASSERT_FALSE(b.isOdd());
    ASSERT_TRUE(b.isEven());


    b = Number::fromDecString("6546754614");

    ASSERT_FALSE(b.isOdd());
    ASSERT_TRUE(b.isEven());
}