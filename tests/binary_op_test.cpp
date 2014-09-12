#include "bignumber.h"

#include <gtest/gtest.h>

TEST(BitTests, BinaryNotTest)
{
    using namespace bignumber;

    auto b = BigNumber::fromBinString("10100100101");

    auto r = ~b;

    ASSERT_EQ("1011011010", r.toBinString());

    b = BigNumber::fromBinString("11");

    r = ~b;

    ASSERT_EQ("0", r.toBinString());
}

TEST(BitTests, BinaryAndTest)
{
    using namespace bignumber;

    auto a = BigNumber::fromBinString("101");
    auto b = BigNumber::fromBinString("11");

    auto r = a & b;

    ASSERT_EQ("1", r.toBinString());
}