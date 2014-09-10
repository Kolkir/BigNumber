#include "bignumber.h"

#include <gtest/gtest.h>

TEST(BitTests, SetGetTest)
{
    using namespace bignumber;

    BigNumber b;

    b.setBit(1);
    b.setBit(0);
    b.setBit(7);

    ASSERT_FALSE(b.getBit(2));
    ASSERT_TRUE(b.getBit(1));
    ASSERT_FALSE(b.getBit(6));
    ASSERT_TRUE(b.getBit(7));
}

TEST(BitTests, BitCountTest)
{
    using namespace bignumber;

    BigNumber b;

    ASSERT_EQ(0, b.getBitsCount());

    b.setBit(0);

    ASSERT_EQ(1, b.getBitsCount());

    b.setBit(7);

    ASSERT_EQ(8, b.getBitsCount());
}

TEST(BitTests, RestToggleTest)
{
    using namespace bignumber;

    BigNumber b;
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


TEST(BitTests, ShiftLeftTest)
{
    using namespace bignumber;

    auto b = BigNumber::fromBinString("101");

    auto r = b << 2;

    ASSERT_EQ("10100", BigNumber::toBinString(r));

    r = r << 16;

    ASSERT_EQ("101000000000000000000", BigNumber::toBinString(r));
}

TEST(BitTests, ShiftRightTest)
{
    using namespace bignumber;

    auto b = BigNumber::fromBinString("10100");

    auto r = b << 2;

    ASSERT_EQ("101", BigNumber::toBinString(r));
}
