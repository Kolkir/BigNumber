#include "bignumber.h"

#include <gtest/gtest.h>

TEST(BitTests, FromBinStringTest)
{
    auto b = BigNumber<unsigned char>::fromBinString("101");
    ASSERT_TRUE(b.getBit(0));
    ASSERT_FALSE(b.getBit(1));
    ASSERT_TRUE(b.getBit(2));
}

