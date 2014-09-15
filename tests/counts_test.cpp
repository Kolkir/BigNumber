#include "number.h"

#include <gtest/gtest.h>

TEST(CountsTests, TotalBitsCount)
{
    using namespace bignumber;

    Number b;

    ASSERT_EQ(0, b.getBitsCount());

    b.setBit(0);

    ASSERT_EQ(1, b.getBitsCount());

    b.setBit(7);

    ASSERT_EQ(8, b.getBitsCount());
}

