#include "number.h"

#include <gtest/gtest.h>

TEST(BitTests, FromBinStringTest)
{
    using namespace bignumber;

    auto b = Number::fromBinString("101");
    ASSERT_TRUE(b.getBit(0));
    ASSERT_FALSE(b.getBit(1));
    ASSERT_TRUE(b.getBit(2));

    std::string str2("101001010111100001010101111101000001111010101011101");

    auto b2 = Number::fromBinString(str2);

    ASSERT_TRUE(b2.getBit(0));
    ASSERT_TRUE(b2.getBit(b2.getBitsCount() - 1));
}

TEST(BitTests, ToBinStringTest)
{
    using namespace bignumber;

    std::string str1("101");

    auto b1 = Number::fromBinString(str1);

    ASSERT_EQ(str1, b1.toBinString());


    std::string str2("101001010111100001010101111101000001111010101011101");

    auto b2 = Number::fromBinString(str2);

    ASSERT_EQ(str2, b2.toBinString());

}

TEST(BitTests, FromDecStringTest)
{
    using namespace bignumber;

    auto b = Number::fromDecString("5");
    ASSERT_TRUE(b.getBit(0));
    ASSERT_FALSE(b.getBit(1));
    ASSERT_TRUE(b.getBit(2));

    ASSERT_EQ("101", b.toBinString());

    b = Number::fromDecString("4587864");

    ASSERT_EQ("10001100000000101011000", b.toBinString());
}

