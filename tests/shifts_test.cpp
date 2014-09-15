#include "number.h"

#include <gtest/gtest.h>

TEST(ShiftTests, Left)
{
    using namespace bignumber;

    auto b = Number::fromBinString("101");

    auto r = b << 2;

    ASSERT_EQ("10100", r.toBinString());

    r = r << 16;

    ASSERT_EQ("101000000000000000000", r.toBinString());
}

TEST(ShiftTests, Right)
{
    using namespace bignumber;

    auto b = Number::fromBinString("10100");

    auto r = b >> 2;

    ASSERT_EQ("101", r.toBinString());

    b = Number::fromBinString("1010000000000000000");
    ASSERT_EQ("1010000000000000000", b.toBinString());

    r = b >> 16;

    ASSERT_EQ("101", r.toBinString());

    b = Number::fromBinString("1010000000000000000");

    r = b >> 32;

    ASSERT_EQ("0", r.toBinString());
}
