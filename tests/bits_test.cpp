#include "bignumber.h"

#include <gtest/gtest.h>

TEST(BitTests, SetGetTest)
{
    BigNumber<unsigned char> b;

    b.setBit(1);
    ASSERT_EQ(2, b.getBitsCount());

    b.setBit(0);
    ASSERT_EQ(2, b.getBitsCount());

    b.setBit(7);
    ASSERT_EQ(8, b.getBitsCount());

    ASSERT_FALSE(b.getBit(2));
    ASSERT_TRUE(b.getBit(1));
    ASSERT_FALSE(b.getBit(6));
    ASSERT_TRUE(b.getBit(7));
}

TEST(BitTests, RestToggleTest)
{
    BigNumber<unsigned char> b;
    b.resetBit(1);
    ASSERT_FALSE(b.getBit(1));

    b.resetBit(7);
    ASSERT_FALSE(b.getBit(7));

    b.toggleBit(7);
    ASSERT_TRUE(b.getBit(7));

    b.toggleBit(1);
    ASSERT_TRUE(b.getBit(1));

    b.toggleBit(23);
    ASSERT_TRUE(b.getBit(23));
    ASSERT_FALSE(b.getBit(22));
}

